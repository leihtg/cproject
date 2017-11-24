// RAW_socket.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );

	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return 1;
	}

	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		HIBYTE( wsaData.wVersion ) != 2 ) {
			return 1; 
	}
	SOCKET s=socket(AF_INET,SOCK_RAW,IPPROTO_IP);
	char errMsg[50]={0};
	if(INVALID_SOCKET==s){
		err=WSAGetLastError();
		sprintf_s(errMsg,"Error socke() = %d",err);
		printf("%s\n",errMsg);
		closesocket(s);
		system("pause");
		return 1;
	}
	int rcvtimeo=5000;
	if(setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(const char*)&rcvtimeo,sizeof(rcvtimeo))==SOCKET_ERROR){
		printf("ERROR %d",WSAGetLastError());
		closesocket(s);
		return 1;
	}
	printf("socket=%d\n",s);
	system("pause");
	return 0;
}

