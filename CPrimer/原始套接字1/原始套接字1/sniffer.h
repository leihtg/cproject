// 头文件

#ifndef RAW_DEF_H
#define RAW_DEF_H

#include <winsock2.h> 
#pragma comment(lib,"ws2_32")

#include <ws2tcpip.h>
#include <mstcpip.h> // 此文件是 Windows platform SDK 的函数，如果找不到，请安装SDK
#include <afx.h>
#include <iostream>

#define PROTOCOL_STRING_ICMP_TXT "ICMP"
#define PROTOCOL_STRING_TCP_TXT "TCP"
#define PROTOCOL_STRING_UDP_TXT "UDP"
#define PROTOCOL_STRING_SPX_TXT "SPX"
#define PROTOCOL_STRING_NCP_TXT "NCP"
#define PROTOCOL_STRING_UNKNOW_TXT "UNKNOW"

// 定义IP首部 
typedef struct ip_hdr 
{ 
 unsigned char h_verlen;   // 4位首部长度,4位IP版本号 
 unsigned char tos;    // 8位服务类型TOS 
 unsigned short total_len;       // 16位总长度（字节） 
 unsigned short ident;      // 16位标识 
 unsigned short frag_and_flags;  // 3位标志位 
 unsigned char ttl;       // 8位生存时间 TTL 
 unsigned char proto;      // 8位协议 (TCP, UDP 或其他) 
 unsigned short checksum;  // 16位IP首部校验和 
 unsigned int sourceIP;   // 32位源IP地址 
 unsigned int destIP;   // 32位目的IP地址 
}IPHEADER;

// 定义TCP伪首部 
typedef struct tsd_hdr 
{ 
 unsigned long saddr;    // 源地址 
 unsigned long daddr;    // 目的地址 
 char mbz;                        // 0
 char ptcl;       // 协议类型 UDP的协议类型为17，TCP为6 
 unsigned short tcpl;    // TCP数据包长度 
}PSDHEADER;

// 定义TCP首部 
typedef struct tcp_hdr 
{ 
 USHORT th_sport;     // 16位源端口 
 USHORT th_dport;     // 16位目的端口 
 unsigned int th_seq;    // 32位序列号 
 unsigned int th_ack;    // 32位确认号 
 unsigned char th_lenres;   // 4位首部长度/6位保留字 
 unsigned char th_flag;    // 6位标志位 
 USHORT th_win;      // 16位窗口大小 
 USHORT th_sum;      // 16位校验和 
 USHORT th_urp;      // 16位紧急数据偏移量 
}TCPHEADER;

// 定义ICMP首部
typedef struct icmp_hdr
{
 unsigned char  i_type;           // 类型
 unsigned char  i_code;           // 代码
 unsigned short i_cksum;          // 校验码
 unsigned short i_id;             // 非标准的ICMP首部  
 unsigned short i_seq;
 unsigned long  timestamp;
}ICMPHEADER;

// 定义UDP首部
// The UDP packet is lick this. Took from RFC768.
//                  0      7 8     15 16    23 24    31  
//                 +--------+--------+--------+--------+ 
//                 |     Source      |   Destination   | 
//                 |      Port       |      Port       | 
//                 +--------+--------+--------+--------+ 
//                 |                 |                 | 
//                 |     Length      |    Checksum     | 
//                 +--------+--------+--------+--------+ 
//                 |                                     
//                 |          data octets ...            
//                 +---------------- ...      

typedef struct udp_hdr  // 8 Bytes
{
 unsigned short uh_sport;         
 unsigned short uh_dport;
 unsigned short uh_len;
 unsigned short uh_sum;
} UDPHEADER;


/* 
// 函数实现不要放在头文件，否则会导致在不同的地方重复定义
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
*/

USHORT checksum(USHORT *buffer, int size);


// 回调函数

// 抓到一个包就会调用这个回调函数
typedef int (CALLBACK *CaptureDef)(CString  &strMsg);

class YRawSniffer
{
public:
 YRawSniffer();
 ~YRawSniffer();
 BOOL StartAll();
 BOOL ExitAll();
 BOOL Capture(CaptureDef CaptureFunc = NULL);
 BOOL StopCapture();

 static DWORD WINAPI CaptureThread(LPVOID lpParam);
 HANDLE m_hCaptureThread;

 // Filter 过滤条件
 BOOL m_bCapTCP;
 BOOL m_bCapUDP;
 BOOL m_bCapICMP;
 CString m_strSrcIP;
 CString m_strDstIP;
 
 SOCKET m_rawSock;
// CString m_strFilePath;

private:
 CaptureDef m_CaptureFunc;
 BOOL m_bExitCapture;
 
 IPHEADER m_ipHeader; 
 TCPHEADER m_tcpHeader;
 ICMPHEADER m_icmpheader;
 UDPHEADER m_udpheader;
};

#endif

