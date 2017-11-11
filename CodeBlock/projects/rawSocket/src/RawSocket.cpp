#include "RawSocket.h"

PROTN2T aOfProto[]=
{
    {
        IPPROTO_IP,"IP"
    },{
        IPPROTO_ICMP,"ICMP"
    },{
        IPPROTO_IGMP,"IGMP"
    },{
        IPPROTO_GGP,"GGP"
    },{
        IPPROTO_TCP,"TCP"
    },{
        IPPROTO_PUP,"PUP"
    },{
        IPPROTO_UDP,"UDP"
    },{
        IPPROTO_IDP,"IDP"
    },{
        IPPROTO_ND,"ND"
    },{
        IPPROTO_RAW,"RAW"
    },{
        IPPROTO_MAX,"MAX"
    },{
        NULL,""
    }
};

char* get_proto_name(unsigned char proto){
    for(int i=0;i<sizeof(aOfProto)/sizeof(PROTN2T);i++){
        PROTN2T p=aOfProto[i];
        if(proto == p.proto){
            return p.pprototext;
        }
    }
}
RawSocket::RawSocket()
{
    WORD wVersionabout:pluginsRequested = MAKEWORD(2,2);
    WSADATA  data;
    errCode=WSAStartup(wVersionRequested,&data);
    if(errCode != 0)
    {
        cout<<"WSAStartup error"<<endl;
        return ;
    }
    if(LOBYTE(data.wVersion) != 2 || HIBYTE(data.wVersion) != 2)
    {
        WSACleanup();
        return ;
    }
}

RawSocket::~RawSocket()
{
    WSACleanup();
}
void RawSocket::build(int timeout,USHORT port)
{
    rawSocket = socket(AF_INET,SOCK_RAW,IPPROTO_IP);
    if(rawSocket == INVALID_SOCKET)
    {
        cout<<"create socket error!"<<endl;
        return ;
    }
    if(setsockopt(rawSocket,SOL_SOCKET,SO_RCVTIMEO,(const char *)&timeout,sizeof(timeout))==SOCKET_ERROR)
    {
        errCode=WSAGetLastError();
        cout<<"Error setsockopt :"<<errCode<<endl;
        closesocket(rawSocket);
        WSACleanup();
        return ;
    }
    SOCKADDR_IN addr = getAddr();
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    //可重用
//    BOOL optval=TRUE;
//    if(setsockopt(rawSocket,SOL_SOCKET,SO_REUSEADDR,(char FAR*)&optval,sizeof(optval)) == SOCKET_ERROR){
//        cout<<"重用失败！"<<endl;
//    }

    if(bind(rawSocket,(SOCKADDR*)&addr,sizeof(addr)) == SOCKET_ERROR)
    {
        errCode=WSAGetLastError();
        cout<<"bind socket error!"<<endl;
        return ;
    }

//    SOCKADDR_IN cAddr;
//    cAddr.sin_family=AF_INET;
//    cAddr.sin_addr.S_un.S_addr=inet_addr("192.168.1.101");
//    connect(rawSocket,(SOCKADDR*)&cAddr,sizeof(cAddr));

    DWORD dwBufferLen[10];
    DWORD dwBufferInLen = 1;
    DWORD dwBytesReturned = 0;

    if(SOCKET_ERROR == WSAIoctl(rawSocket,SIO_RCVALL,&dwBufferInLen,sizeof(dwBufferInLen),&dwBufferLen,sizeof(dwBufferLen),&dwBytesReturned,NULL,NULL))
    {
        errCode = WSAGetLastError();
        cout<<"WSAIoctl error :"<<errCode<<endl;
        closesocket(rawSocket);
        WSACleanup();
        return ;
    }

    int len;
    while(true)
    {
        errCode=recv(rawSocket,buf,sizeof(buf),0);
        IP_HEADER* ip=(IP_HEADER*)buf;

        in_addr is,it;
        is.S_un.S_addr=ip->sourceIP;
        it.S_un.S_addr=ip->destIP;
        cout<<"源IP："<<inet_ntoa(is)<<"\t"<<"目标IP："<<inet_ntoa(it)<<endl;
        cout<<"协议："<<get_proto_name(ip->proto)<<endl;
        len=ntohs(ip->total_len);
        cout<<"字节数:"<<errCode<<"\t"<<len<<endl;
        len=(ip->h_lenver&0x0f)*4;
        cout<<"内容:"<<*(buf+len)<<endl;
        cout<<endl;
    }
}
SOCKADDR_IN RawSocket::getAddr()
{
    SOCKADDR_IN addr;
    char name[128]= {0};
    errCode = gethostname(name,128);
    if(0 != errCode)
    {
        cout<<"gethostname error!"<<endl;
        return addr;
    }
    cout<<"hostName : "<<name<<endl;

    HOSTENT* host = gethostbyname(name);
    if(NULL == host)
    {
        cout<<"gethostbyname error!"<<endl;
        return addr;
    }

    addr.sin_addr=*(in_addr*)(host->h_addr_list[0]);
    return addr;
}

//TCP伪首部并不是真正存在的，只是用于计算检验和。校验和函数：

USHORT checksum(USHORT *buffer, int size)
{
    unsigned long cksum=0;
    while (size > 1)
    {
        cksum += *buffer++;size
        size -= sizeof(USHORT);
    }
    if (size)
    {
        cksum += *(UCHAR*)buffer;
    }
    cksum = (cksum >> 16) + (cksum & 0xffff);
    cksum += (cksum >>16);
    return (USHORT)(~cksum);
}

