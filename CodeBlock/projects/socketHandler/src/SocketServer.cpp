#include "SocketServer.h"

SocketServer::SocketServer()
{


    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD( 2, 2 );

    err = WSAStartup(wVersionRequested, &wsaData );
    if ( err != 0 )
    {
        return;
    }

    if ( LOBYTE( wsaData.wVersion ) != 2 ||
            HIBYTE( wsaData.wVersion ) != 2 )
    {
        WSACleanup( );
        return;
    }

}

SocketServer::~SocketServer()
{
    WSACleanup();
}
void SocketServer::build()
{
    int err;
    SOCKET  serverSocket=socket(AF_INET,SOCK_STREAM,0);
    if(INVALID_SOCKET == serverSocket)
    {
        cout<<"create socket error"<<endl;
        WSACleanup();
        return ;
    }
    SOCKADDR_IN addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(8888);
    addr.sin_addr.S_un.S_addr=INADDR_ANY;

    err=bind(serverSocket,(SOCKADDR*)&addr,sizeof(addr));
    if(SOCKET_ERROR==err)
    {
        cout<<"bind error"<<endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }
    err=listen(serverSocket,5);
    if(SOCKET_ERROR == err)
    {
        cout<<"listen error"<<endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }
    SOCKADDR_IN addrClient;
    int len=sizeof(SOCKADDR_IN);
    SOCKET clientSocket=accept(serverSocket,(SOCKADDR*)&addrClient,&len);
    if(INVALID_SOCKET == clientSocket)
    {
        cout<<"accept error"<<endl;
        closesocket(serverSocket);
        WSACleanup();
    }
    char msg[1024];
    while(true)
    {
        memset(msg,0,1024);
        err=recv(clientSocket,msg,1023,0);
        cout<<"字节:"<<err<<endl;
        cout<<"接收来自【"<<inet_ntoa(addrClient.sin_addr)<<":"<<htons(addrClient.sin_port)<<"】_"<<msg<<endl;

        cout<<"我说：";
        cin>>msg;
        send(clientSocket,msg,1024,0);
    }
}
