#include <iostream>
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
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
	char ip[]="www.taobao.com";
	
	wchar_t src[32]={0};
	unsigned long ddd= inet_addr(ip);

	//HOSTENT *host=gethostbyaddr(ip,4,AF_INET);
	HOSTENT *host =gethostbyname(ip);
	if(NULL!=host){
		cout<<host->h_name<<endl;
		char **p=host->h_addr_list;
		switch(host->h_addrtype){
		case AF_INET:
		case AF_INET6:
			while(*p!=NULL){
				InetNtop(host->h_addrtype,*p,src,32);
				//cout<<*p<<"\t"<<p<<endl;
				wcout<<src<<endl;
				p++;
			}
			break;
		default:
			cout<<"unknown address"<<endl;
		}


	}else{
		cout<<"host is NULL"<<endl;
	}
	return 0;
}