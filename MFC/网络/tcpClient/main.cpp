#include <winsock2.h>
#include <stdio.h>

void main(){
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD( 1, 1 );
	
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return;
	}
	
	
	
	if ( LOBYTE( wsaData.wVersion ) != 1 ||
        HIBYTE( wsaData.wVersion ) != 1 ) {
		WSACleanup( );
		return; 
	}

	SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(6000);
	connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	char recvBuf[100];
	memset(recvBuf,0,sizeof(recvBuf));
	recv(sockClient,recvBuf,100,0);
	printf("%s w\n",recvBuf);
	send(sockClient,"Theis is 张三",strlen("Theis is 张三")+1,0);
	closesocket(sockClient);
	WSACleanup();
}