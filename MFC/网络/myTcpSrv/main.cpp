#include <winsock2.h>
#include <stdio.h>
void main(){
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD( 1,1 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return;
	}
	if ( LOBYTE( wsaData.wVersion ) != 1 ||
        HIBYTE( wsaData.wVersion ) != 1 ) {
		WSACleanup( );
		return; 
	}
	
	SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_port=htons(8080);
	
	bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(addrSrv));
	listen(sockSrv,5);
	
	
	SOCKADDR_IN addr;
	int len=sizeof(SOCKADDR);
	SOCKET sockClient=accept(sockSrv,(SOCKADDR*)&addr,&len);

	printf("%s连入！\n",inet_ntoa(addr.sin_addr));
	char msg[2048];
	char rec[2048];
	while(1){
		memset(msg,0,sizeof(msg));
		memset(rec,0,sizeof(rec));
		printf("我说：");
		gets(msg);
		send(sockClient,msg,strlen(msg)+1,0);
		recv(sockClient,rec,sizeof(rec),0);
		printf("%s 说:%s\n",inet_ntoa(addr.sin_addr),rec);
	}

	closesocket(sockClient);
	closesocket(sockSrv);
	WSACleanup();
}