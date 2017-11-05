#include<stdio.h>
#include <winsock.h>
#include<sys/types.h>

#include<string.h>
#include<stdlib.h>
int main(int argc,char*argv[])
{
	struct hostent* h;

	if((h=gethostbyname("localhost"))==NULL)
	{/*取得地址信息*/
		
		
		
	}
	printf("hostname:%s",h->h_name);
	printf("IPAddress:%s",inet_ntoa(*((struct in_addr*)h->h_addr)));
	return 0;
}