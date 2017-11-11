#ifndef RAWSOCKET_H
#define RAWSOCKET_H
#include <iostream>
#include "sniffer.h"
#include "mstcpip.h"

using namespace std;

class RawSocket
{
public:
    RawSocket();
    virtual ~RawSocket();
    void build(int timeout, USHORT port);

protected:

private:
    SOCKADDR_IN getAddr();
    SOCKET rawSocket;
    int errCode;
    char buf[2048];
};

#endif // RAWSOCKET_H
