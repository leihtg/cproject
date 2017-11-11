#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#include <winsock2.h>
#include <iostream>
#include <string>

using namespace std;
//#pragma comment(lib,"ws2_32.lib")

class SocketServer
{
    public:
        SocketServer();
        virtual ~SocketServer();
        void build();
    protected:

    private:
};

#endif // SOCKETSERVER_H
