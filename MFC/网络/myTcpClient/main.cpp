#include <winsock2.h>
#include <stdio.h>
void main(){
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD( 2, 2 );
	
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return;
	}
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
        HIBYTE( wsaData.wVersion ) != 2 ) {
		WSACleanup( );
		return; 
	}

	SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addr;
	addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8080);

	connect(sockClient,(SOCKADDR*)&addr,sizeof(addr));
	char msg[2048];
	char sen[2048];
	while(1){
		memset(msg,0,sizeof(msg));
		memset(sen,0,sizeof(sen));
		recv(sockClient,msg,sizeof(msg),0);
		printf("%s 说:%s \n",inet_ntoa(addr.sin_addr),msg);	
		printf("我说：");
		gets(sen);
		send(sockClient,sen,strlen(sen)+1,0);
		if('q'==sen[0]&&strlen(sen)==1){
			printf("您选择了退出!\n");
			break;
		}
	}
	closesocket(sockClient);
	WSACleanup();
	
}