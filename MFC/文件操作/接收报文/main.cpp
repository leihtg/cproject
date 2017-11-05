#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib");
void main(){
	WORD version;
	WSADATA data;
	version=MAKEWORD(1,1);
	int err=WSAStartup(version,&data);
	if(err!=0){
		return;
	}
	if(LOBYTE(data.wVersion)!=1||HIBYTE(data.wVersion)!=1){
		WSACleanup();
		return;
	}

	SOCKET ser=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addr;
	addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8080);

	int a=bind(ser,(SOCKADDR*)&addr,sizeof(addr));
	printf("%d\n",bind!=0);
/*	if(bind!=0){
		closesocket(ser);
		WSACleanup();
		return;
	}*/
	listen(ser,5);
	
	SOCKADDR_IN caddr;
	int len=sizeof(SOCKADDR);
	SOCKET client=accept(ser,(SOCKADDR*)&caddr,&len);
	char msg[1000];
	memset(msg,0,sizeof(msg));	
	while(recv(client,msg,sizeof(msg),0)){
		printf("%s\n",msg);
		memset(msg,0,sizeof(msg));	
	}
	closesocket(client);
	closesocket(ser);
	WSACleanup();
}