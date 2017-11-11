#include "sniffer.h"
#include "mstcpip.h"
#include "stdio.h"
#include <iostream>

using namespace std;

int main(int args,char *agrv[])
{
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    wVersionRequested = MAKEWORD( 2, 2);

    err = WSAStartup( wVersionRequested, &wsaData );
    if ( err != 0 )
    {
        return 1;
    }

    if ( LOBYTE( wsaData.wVersion ) != 2 ||
            HIBYTE( wsaData.wVersion ) != 2 )
    {
        WSACleanup();
        return 1;
    }
    int dwErr=0;

    SOCKET m_s=socket(AF_INET,SOCK_RAW,IPPROTO_IP);
    if(INVALID_SOCKET==m_s)
    {
        dwErr=WSAGetLastError();
        cout<<"create socket error!"<<dwErr<<endl;
        closesocket(m_s);
        WSACleanup();
    }
    int rcvtimeo=5000;
    if(setsockopt(m_s,SOL_SOCKET,SO_RCVTIMEO,(const char *)&rcvtimeo,sizeof(rcvtimeo))==SOCKET_ERROR)
    {
        dwErr=WSAGetLastError();
        cout<<"Error setsockopt :"<<dwErr<<endl;
        closesocket(m_s);
        WSACleanup();
        return 1;
    }

    SOCKADDR_IN sa;
    sa.sin_family=AF_INET;
    sa.sin_port=htons(7000);
    sa.sin_addr.S_un.S_addr=inet_addr("localhost");

    if(bind(m_s,(SOCKADDR*)&sa,sizeof(sa))==SOCKET_ERROR)
    {
        dwErr=WSAGetLastError();
        cout<<"bind error:"<<dwErr<<endl;
        return 1;
    }

    DWORD dwBufferLen[10];
    DWORD dwBufferInLen=1;
    DWORD dwBytesReturned=0;

    if(SOCKET_ERROR!=WSAIoctl(m_s,SIO_RCVALL,&dwBufferInLen,sizeof(dwBufferInLen),&dwBufferLen,sizeof(dwBufferLen),&dwBytesReturned,NULL,NULL))
    {
    }
    else
    {
        dwErr=WSAGetLastError();
        cout<<"WSAIoctl error ´íÎóÂë£º"<<dwErr<<endl;
        closesocket(m_s);
        WSACleanup();
        return 1;
    }

    char buf[1024]= {0};
    int iRet;
//    FILE *fp=fopen("C:\\Users\\Thinkpad\\Desktop\\ip.txt","wb");
    while(true)
    {
        iRet=recv(m_s,buf,sizeof(buf),0);
        IP_HEADER *ip=(IP_HEADER*)buf;
        in_addr ia,ib;
        ia.S_un.S_addr=ip->sourceIP;
        ib.S_un.S_addr=ip->destIP;
        cout<<inet_ntoa(ia)<<"\t"<<inet_ntoa(ib)<<endl;
//        fwrite((int*)buf,sizeof(buf),1,fp);
        for(int i=0; i<sizeof(buf); i++)
        {
            cout<<(int)buf[i];
//            fputc(buf[i],fp);
        }

        cout<<"\n----------------\n";
        cout<<ip<<endl;
        cout<<"协议:"<<(int)ip->proto<<endl;
        cout<<ip->destIP<<endl;
    }
//    fclose(fp);
    closesocket(m_s);
    WSACleanup();
    return 0;
}
