#include <iostream.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main(int args,char *argv[]){
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD( 2, 2 );
	
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return 1;
	}
	if (LOBYTE( wsaData.wVersion ) != 2 ||
        HIBYTE( wsaData.wVersion ) != 2 ) {
		WSACleanup( );
		return 1; 
	}
	char ip[]="www.baidu.com";
	unsigned long ddd= inet_addr(ip);

	//HOSTENT *host=gethostbyaddr(ip,4,AF_INET);
	HOSTENT *host =gethostbyname(ip);
	if(NULL!=host){
		cout<<host->h_name<<endl;
		char **p=host->h_addr_list;
	//	char p[3][6]={"hel10","kkkk","aaad"};
		int i=0;
		while(*p!=NULL){
			cout<<*p<<"\t"<<p<<endl;
			p++;
			
			
		}
		
	}else{
		cout<<"host is NULL"<<endl;
	}
	return 0;
}