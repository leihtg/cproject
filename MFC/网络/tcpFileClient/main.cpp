#include <winsock2.h>
#include <stdio.h>
void a(){
	WORD versionRequest;
	WSADATA wsaData;
	int err;
	versionRequest=MAKEWORD(1,1);
	err=WSAStartup(versionRequest,&wsaData);
	if(err!=0){
		return;
	}
	if(LOBYTE(wsaData.wVersion)!=1||HIBYTE(wsaData.wVersion)!=1){
		WSACleanup();
		return;
	}
	
	SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addr;
	addr.sin_family=AF_INET;
	addr.sin_addr.S_un.S_addr=inet_addr("192.168.1.175");
	addr.sin_port=htons(8080);
	
	//连接主机
	connect(sockClient,(SOCKADDR*)&addr,sizeof(addr));
	
	char msg[1024];
	FILE *file=fopen("F:\\d.3gp","rb");
	long int size=0;
	memset(msg,0,sizeof(msg));
	while(!feof(file)){
	//	fread(msg,sizeof(msg),1,file);
		msg[0]=fgetc(file);
		send(sockClient,msg,strlen(msg),0);
		size+=strlen(msg);
		memset(msg,0,sizeof(msg));
	}
	printf("%ld\t%ld\n",size,ftell(file));
	send(sockClient,msg,sizeof(msg),0);
	fclose(file);
	closesocket(sockClient);
	WSACleanup();
	
	
}

void main(){
		FILE *file=fopen("F:\\a.flv","rb");
		FILE *f=fopen("F:\\a1.flv","w");
		char msg[1000];
		long int size=0;
		memset(msg,0,sizeof(msg));
		while(!feof(file)){
			fread(msg,sizeof(msg),1,file);
			
			fwrite(msg,sizeof(msg),1,f);
			size+=strlen(msg);
			memset(msg,0,sizeof(msg));
		}
		printf("%ld\t%ld\n",size,ftell(file));
		fclose(f);
		fclose(file);
}