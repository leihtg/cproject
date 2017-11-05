#include "sniffer.h"
//CheckSum:计算校验和的子函数 
USHORT checksum(USHORT *buffer, int size) 
{ 
	unsigned long cksum=0; 
	while(size >1) 
	{ 
		cksum+=*buffer++; 
		size -=sizeof(USHORT); 
	} 
	if(size ) 
	{ 
		cksum += *(UCHAR*)buffer; 
	} 

	cksum = (cksum >> 16) + (cksum & 0xffff); 
	cksum += (cksum >>16); 
	return (USHORT)(~cksum); 
}

char * GetProtocol(int proto)
{
	switch(proto)
	{
	case IPPROTO_ICMP: return PROTOCOL_STRING_ICMP_TXT;
	case IPPROTO_TCP:  return PROTOCOL_STRING_TCP_TXT;
	case IPPROTO_UDP:  return PROTOCOL_STRING_UDP_TXT;
	default:     return PROTOCOL_STRING_UNKNOW_TXT;
	}
}

DWORD WaitForObjectEx( HANDLE hHandle, DWORD dwMilliseconds )
{
	BOOL bRet;
	MSG msg;
	INT iWaitRet;
	DWORD nTimeOut = 0;
	while( (bRet = ::GetMessage( &msg, NULL, 0, 0 )) != 0)
	{ 
		if( nTimeOut++ * 100 >= dwMilliseconds )
			break;

		iWaitRet = WaitForSingleObject(hHandle, 100);
		if(iWaitRet != WAIT_TIMEOUT)
		{
			break;
		}
		if (bRet == -1)
		{
			break;
		}
		else
		{
			::TranslateMessage(&msg); 
			::DispatchMessage(&msg); 
		}
	}

	return iWaitRet;
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
YRawSniffer *g_rawSniffer;

YRawSniffer::YRawSniffer()
{
	m_bCapTCP = FALSE;
	m_bCapUDP = FALSE;
	m_bCapICMP = FALSE;
	m_strSrcIP = "";
	m_strDstIP = "";

	m_rawSock = INVALID_SOCKET;
	// m_strFilePath = "";

	m_bExitCapture = FALSE;
	m_CaptureFunc = NULL;
	m_hCaptureThread = NULL;

	g_rawSniffer = this;

	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)
	{
		TRACE1("WSAStartup() ERROR! %d", GetLastError());
		return;
	}

}

YRawSniffer::~YRawSniffer()
{
	WSACleanup(); 
}

BOOL YRawSniffer::ExitAll()
{
	m_bExitCapture = TRUE;

	shutdown(m_rawSock, SD_BOTH);

	if(m_hCaptureThread != NULL)
	{
		DWORD dwRet = 0;
		dwRet = WaitForObjectEx(m_hCaptureThread, INFINITE);
		if(dwRet == WAIT_OBJECT_0)
		{
			TRACE("CaptureThread exit Success!");
		}
		closesocket(m_rawSock);
		m_rawSock = INVALID_SOCKET;
		CloseHandle(m_hCaptureThread);
		m_hCaptureThread = NULL;
	}

	TRACE("ExitAll OK!");

	return TRUE;
}

BOOL YRawSniffer::StartAll()
{
	m_bExitCapture = FALSE;

	SOCKADDR_IN addr_in;

	if(m_rawSock == INVALID_SOCKET)
		m_rawSock = socket(AF_INET, SOCK_RAW, IPPROTO_IP);

	BOOL flag = TRUE;

	if(setsockopt(m_rawSock, IPPROTO_IP, IP_HDRINCL, (char*)&flag, sizeof(flag)) != 0)
	{
		TRACE1("setsockopt() ERROR! %d", WSAGetLastError());
		return FALSE;
	}

	char  LocalName[16];
	struct hostent *pHost;

	// 获取本机名 
	if (gethostname((char*)LocalName, sizeof(LocalName)-1) == SOCKET_ERROR) 
	{
		TRACE1("gethostname error! %d", WSAGetLastError());
		return FALSE;
	}

	// 获取本地 IP 地址 
	if ((pHost = gethostbyname((char*)LocalName)) == NULL) 
	{
		TRACE1("gethostbyname error! %d", WSAGetLastError());
		return FALSE;
	}

	// m_strSrcIP = pHost->h_addr_list[0];
	addr_in.sin_addr  = *(in_addr *)pHost->h_addr_list[0]; // IP 
	addr_in.sin_family = AF_INET; 
	addr_in.sin_port  = htons(57274);

	if( bind(m_rawSock, (struct sockaddr *)&addr_in, sizeof(addr_in)) != 0)
	{
		TRACE1("bind error! %d", WSAGetLastError());
		return FALSE;
	}

	// 设置网卡的I/O行为，接收网络上所有的数据包
	DWORD dwValue = 1; 
	if( ioctlsocket(m_rawSock, SIO_RCVALL, &dwValue) != 0)
	{
		TRACE1("ioctlsocket error! %d", WSAGetLastError());
		return FALSE;
	} 

	return TRUE;
}

DWORD WINAPI YRawSniffer::CaptureThread(LPVOID lpParam)
{
	//CFile fLog;
	//BOOL bLogFile = FALSE;
	// 打开记录文件
	//if(g_rawSniffer->m_strFilePath == "")
	// g_rawSniffer->m_strFilePath = "c://Capture.txt";
	//if(g_rawSniffer->m_strFilePath != "")
	// {
	//  if( !fLog.Open(g_rawSniffer->m_strFilePath, CFile::modeCreate|CFile::modeReadWrite) )
	//   TRACE1("file fLog Open failed! %d", GetLastError());
	//  else
	//   bLogFile = TRUE;
	// }

	const int MAX_RECEIVEBUF = 1000;
	char recvBuf[MAX_RECEIVEBUF] = {0};
	char msg[MAX_RECEIVEBUF] = {0};

	char *ptr = NULL;

	CString strLog, strTmp, strContent;

	DWORD nTCPCnt = 0, nUDPCnt = 0, nICMPCnt = 0;

	while(!g_rawSniffer->m_bExitCapture)
	{
		int ret = recv(g_rawSniffer->m_rawSock, recvBuf, MAX_RECEIVEBUF, 0);
		if(ret == SOCKET_ERROR)
			TRACE1("%d, recv(g_rawSniffer->m_rawSock, recvBuf, MAX_RECEIVEBUF, 0) failed!", GetLastError());

		strLog = "";
		strContent = "";

		if(ret > 0)
		{   
			g_rawSniffer->m_ipHeader = *(IPHEADER*)recvBuf;

			// 取得正确的IP头长度
			int iIphLen = sizeof(unsigned long) * (g_rawSniffer->m_ipHeader.h_verlen & 0xf);
			int cpysize = 0;

			// 过滤目标IP或者源IP
			//if(g_rawSniffer->m_strSrcIP.Find(".") > 0 
			// || g_rawSniffer->m_strDstIP.Find(".") > 0)
			{
				if(g_rawSniffer->m_strSrcIP != "" 
					|| g_rawSniffer->m_strDstIP != "")
				{
					if( inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.sourceIP) != g_rawSniffer->m_strSrcIP
						&& inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.destIP) != g_rawSniffer->m_strDstIP)
						continue;
				}
			}

			/*
			// 过滤目标IP或者源IP
			if(g_rawSniffer->m_strSrcIP != "")
			{
			if( inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.sourceIP) != g_rawSniffer->m_strSrcIP)
			continue;
			}

			if(g_rawSniffer->m_strDstIP != "")
			{
			if( inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.destIP) != g_rawSniffer->m_strDstIP)
			continue;
			}
			*/

			if(g_rawSniffer->m_ipHeader.proto == IPPROTO_TCP && g_rawSniffer->m_bCapTCP)
			{
				nTCPCnt++;
				g_rawSniffer->m_tcpHeader = *(TCPHEADER*)(recvBuf + iIphLen);
				strTmp.Format(_T("取得 %d TCP包"), nTCPCnt); strLog += strTmp;
				strTmp.Format(_T("协议： %s \r\n"), GetProtocol(g_rawSniffer->m_ipHeader.proto)); strLog += strTmp;
				strTmp.Format(_T("IP源地址： %s \r\n"), inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.sourceIP)); strLog += strTmp;
				strTmp.Format(_T("IP目标地址: %s \r\n"), inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.destIP)); strLog += strTmp;
				strTmp.Format(_T("TCP源端口号： %d \r\n"), g_rawSniffer->m_tcpHeader.th_sport); strLog += strTmp;
				strTmp.Format(_T("TCP目标端口号：%d \r\n"), g_rawSniffer->m_tcpHeader.th_dport); strLog += strTmp;
				strTmp.Format(_T("数据包长度： %d \r\n"), ntohs(g_rawSniffer->m_ipHeader.total_len)); strLog += strTmp;
				strTmp.Format(_T("TCP数据包的报文内容：\r\n")); strLog += strTmp;

				ptr = recvBuf + iIphLen + (4 * ((g_rawSniffer->m_tcpHeader.th_lenres & 0xf0)>>4|0));
				cpysize = ntohs(g_rawSniffer->m_ipHeader.total_len) - (iIphLen + (4 * ((g_rawSniffer->m_tcpHeader.th_lenres & 0xf0)>>4|0)));

				// ASCII码
				memcpy(msg, ptr, cpysize);
				for(int i = 0; i < cpysize ; i++)
				{
					if(msg[i] >= 32 && msg[i] < 255)
					{
						  strContent.Format(_T("%c"), (unsigned char)msg[i]); strLog += strContent;
					}
					else
					{
						strContent.Format(_T(".")); strLog += strContent;
					}
				}
				strTmp.Format(_T("\r\n \r\n")); strLog += strTmp;
			}


			if(g_rawSniffer->m_ipHeader.proto == IPPROTO_ICMP  && g_rawSniffer->m_bCapICMP)
			{
				nICMPCnt++;
				g_rawSniffer->m_icmpheader = *(ICMPHEADER*)(recvBuf + iIphLen);
				strTmp.Format(_T("取得 %d ICMP包"), nICMPCnt); strLog += strTmp;
				strTmp.Format(_T("协议： %s\r\n"), GetProtocol(g_rawSniffer->m_ipHeader.proto)); strLog += strTmp;
				strTmp.Format(_T("IP源地址： %s\r\n"), inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.sourceIP)); strLog += strTmp;
				strTmp.Format(_T("IP目标地址: %s\r\n"), inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.destIP)); strLog += strTmp;
				strTmp.Format(_T("ICMP返回类型：%d\r\n"), g_rawSniffer->m_icmpheader.i_type); strLog += strTmp;
				strTmp.Format(_T("ICMP返回代码：%d\r\n"), g_rawSniffer->m_icmpheader.i_code); strLog += strTmp;
				strTmp.Format(_T("数据包长度： %d\r\n\r\n\r\n"), ntohs(g_rawSniffer->m_ipHeader.total_len)); strLog += strTmp;    
			}

			if(g_rawSniffer->m_ipHeader.proto == IPPROTO_UDP && g_rawSniffer->m_bCapUDP)
			{
				nUDPCnt++;
				g_rawSniffer->m_udpheader = *(UDPHEADER*)(recvBuf + iIphLen);
				strTmp.Format(_T("取得 %d UDP包"), nUDPCnt); strLog += strTmp;
				strTmp.Format(_T("协议： %s\r\n"), GetProtocol(g_rawSniffer->m_ipHeader.proto)); strLog += strTmp;
				strTmp.Format(_T("IP源地址： %s\r\n"), inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.sourceIP)); strLog += strTmp;
				strTmp.Format(_T("IP目标地址: %s\r\n"), inet_ntoa(*(in_addr*)&g_rawSniffer->m_ipHeader.destIP)); strLog += strTmp;
				strTmp.Format(_T("UDP源端口号： %d\r\n"), g_rawSniffer->m_udpheader.uh_sport); strLog += strTmp;
				strTmp.Format(_T("UDP目标端口号：%d\r\n"), g_rawSniffer->m_udpheader.uh_dport); strLog += strTmp;
				strTmp.Format(_T("数据包长度： %d\r\n"), ntohs(g_rawSniffer->m_ipHeader.total_len)); strLog += strTmp;
				strTmp.Format(_T("UDP数据包的报文内容：\r\n")); strLog += strTmp;

				ptr = recvBuf + iIphLen + 8;
				cpysize = ntohs(g_rawSniffer->m_ipHeader.total_len) - (iIphLen + 8);
				memcpy(msg, ptr, cpysize);

				strTmp.Format(_T("ASCII码格式: \r\n"));
				for(int i = 0; i < cpysize; i++)
				{
					if(msg[i] >= 32 && msg[i] < 255)
					{
						strContent.Format(_T("%c"),(unsigned char)msg[i]); strLog += strContent;
					}
					else
					{
						strContent.Format(_T(".")); strLog += strContent;
					}
				}
				strTmp.Format(_T("\r\n\r\n"));  strLog += strTmp;    

				strTmp.Format(_T("16进制码格式: \r\n"));  strLog += strTmp;
				for(int i = 0; i < cpysize; i++)
				{
					strTmp.Format(_T("%2.2X "), (unsigned char)msg[i]);  strLog += strTmp;
				}
				strTmp.Format(_T("\r\n\r\n")); 
				strLog += strTmp;

			}

			if(g_rawSniffer->m_CaptureFunc != NULL && strLog.GetLength() > 0 && strContent.GetLength() > 0)
				g_rawSniffer->m_CaptureFunc(strLog);

			Sleep(10);
		}
	}


	// 关闭记录文件
	// if(bLogFile)
	//  fLog.Close(); 
	std::cout<<strTmp;
	return 0;
}

BOOL YRawSniffer::Capture(CaptureDef CaptureFunc /*= NULL*/)
{
	StartAll();

	if(CaptureFunc != NULL)
		m_CaptureFunc = CaptureFunc;

	// 创建线程截取包
	m_bExitCapture = FALSE;
	m_hCaptureThread = CreateThread(NULL, 0, CaptureThread, NULL, 0, NULL);
	if(NULL == m_hCaptureThread)
		TRACE1(" \"m_hCaptureThread = CreateThread(NULL, 0, CaptureThread, NULL, 0, NULL)\" failed! %d ", GetLastError());

	return TRUE;
}

BOOL YRawSniffer::StopCapture()
{
	return ExitAll();
}
int main(int arc,char *argv[]){
	  // 过滤条件
  g_rawSniffer->m_bCapTCP = true; // 抓TCP包，TRUE为抓，FALSE不抓
  g_rawSniffer->m_bCapUDP = true; // 抓UDP包，TRUE为抓，FALSE不抓
  g_rawSniffer->m_bCapICMP = true; // 抓ICMP包，TRUE为抓，FALSE不抓
  g_rawSniffer->m_strSrcIP = ""; // 包的源IP串，空为不限制
  g_rawSniffer->m_strDstIP = ""; // 包的目标IP串，空为不限制
  g_rawSniffer->StartAll();
}