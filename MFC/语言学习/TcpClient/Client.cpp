#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")

const int SERVER_PORT=3333;
void main(){
	int sockfd;
	int recvbytes;

	struct hostent* host;
	struct sockaddr_in serv_addr;

	WORD wVersion;
	WSADATA wsaData;
	int err;
	wVersion=MAKEWORD(2,1);
	err=WSAStartup(wVersion,&wsaData);


	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		printf("socket create error\n");
		exit(1);
	}

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=SERVER_PORT;
	serv_addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	memset(&serv_addr.sin_zero,0,8);

	if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(sockaddr_in))!=0){
		printf("socket connect error\n");
		exit(1);
	}
	char buf[1024];
	memset(buf,0,sizeof(buf));
	if(recv(sockfd,buf,sizeof(buf),0)==-1){
		printf("socket receive data error\n");
		exit(1);
	}
	printf("接收的数据：%s\n",buf);
	closesocket(sockfd);

}