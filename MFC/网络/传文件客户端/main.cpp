#include <WINSOCK2.H>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")
#define SIZE 1024*8
void main()
{
	FILE *fp;
	int err;
	int length=0;
	
	SOCKET clientSocket;
	SOCKADDR_IN clientsock_in;
	char receiveBuf[100]={"0"};
	char ip_addr[16]={"127.0.0.1"};
	WORD versionRequired;
	WSADATA wsaData;
	versionRequired=MAKEWORD(1,1);
	err=WSAStartup(versionRequired,&wsaData);//????????
	if (!err)
	{
		
	}
	else
	{
		printf("???????????!\n");
		return;//??
	}
	clientSocket=socket(AF_INET,SOCK_STREAM,0);
	/*printf("?????IP:\n");
	scanf("%s",ip_addr);*/
	//?????
	clientsock_in.sin_addr.S_un.S_addr=inet_addr(ip_addr);
	clientsock_in.sin_family=AF_INET;
	clientsock_in.sin_port=htons(6000);
	connect(clientSocket,(SOCKADDR*)&clientsock_in,sizeof(SOCKADDR));//????
	recv(clientSocket,receiveBuf,101,0);
	printf("%s\n",receiveBuf); 
	char path[100]={"0"};
	gets(path);
	int i=0;
	do
	{
		printf("请输入文件地址:\n"); 
		gets(path);
		while(path[i]!='\0')
		{
			if(path[i]=='/')
				path[i]='\\';
			i++;
		}
		i=0;
		if((fp=fopen(path,"rb"))==NULL)
		{
			i=1;
			printf("文件未打开\n");
		}
	}while(i); 
	fseek(fp,0L,SEEK_END);
    length=ftell(fp);
	printf("待传送文件大小: %d\n",length);
	printf("文件已经打开等待主机消息......\n");
	//??????????
	recv(clientSocket,receiveBuf,101,0);
	printf("%s\n",receiveBuf);
	if(strcmp(receiveBuf,"开始传送")==0)
	{
		//??????
		char sendBuf[20];
		ltoa(length,sendBuf,10);
		send(clientSocket,sendBuf,21,0);
		fseek(fp,0L,SEEK_SET);
		//????
		long int y=0;
		double cent;
		char trans[SIZE];
		while(!feof(fp))
		{
			
			fread(trans,1,SIZE,fp);
			y=y+SIZE;
			if(y<length)
			{
				cent=(double)y*100.0/(double)length;
				printf("已发送: %4.2f%\n",cent);
				send(clientSocket,trans,SIZE+1,0);
			}
			else
			{
				send(clientSocket,trans,length+SIZE-y+1,0);
				closesocket(clientSocket);
				WSACleanup();
			}
		}
		fclose(fp);
	}
	printf("发送完毕\n");
	system("pause");
}