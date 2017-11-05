#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")
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

	SOCKET client=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addr;
	
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8080);
	addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");

	connect(client,(SOCKADDR*)&addr,sizeof(addr));
	char msg[300];
	FILE *file=fopen("D:\\±éÀúÎÄ¼þ.txt","rb");
	
	while(fgets(msg,sizeof(msg),file)){
		printf("%s\n",msg);
		send(client,msg,strlen(msg),0);
		
	}
	fclose(file);
	closesocket(client);
	WSACleanup();
}