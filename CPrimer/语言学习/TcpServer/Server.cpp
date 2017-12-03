#include <string.h>
#include <stdio.h>
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")

const int SRVER_PORT=3333;
const int MAX_ACCEPT=10;

void main(){
	int sockfd;
	int client_fd;

	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	int sin_size;
	char* msg="»¶Ó­µÇÂ¼";

	WORD wr;
	WSADATA wsaData;
	int err;
	wr=MAKEWORD(2,1);
	err=WSAStartup(wr,&wsaData);

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		printf("socket create error\n");
		exit(1);
	}

	my_addr.sin_family=AF_INET;
	my_addr.sin_port=SRVER_PORT;
	my_addr.sin_addr.S_un.S_addr=INADDR_ANY;
	memset(&(my_addr.sin_zero),0,8);

	if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1){
		printf("socket bind error \n");
		exit(1);
	}

	if(listen(sockfd,MAX_ACCEPT)==-1){
		printf("socket listen error\n");
		exit(1);
	}

	while(1){
		sin_size=sizeof(struct sockaddr_in);
		client_fd=accept(sockfd,(struct sockaddr*)&remote_addr,&sin_size);

		if(client_fd==-1){
			printf("socket accept error\n");
			continue;
		}
		printf("½ÓÈëµÄIP:%s\n",inet_ntoa(remote_addr.sin_addr));
		if(send(client_fd,msg,strlen(msg),0)==-1){
			printf("socket send error\n");
			closesocket(client_fd);
			exit(0);
		}
		closesocket(client_fd);

		
	}
}