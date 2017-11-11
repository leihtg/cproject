#ifndef BUFFER_H
#define BUFFER_H

#define MAX_VALUE 0x7fffffff
#define MAX_ARRAY_SIZE MAX_VALUE-8

typedef unsigned char BYTE;

#include <iostream>

using namespace std;

class Buffer
{
public:
    Buffer();
    Buffer(int limit);
    Buffer(Buffer& b);
    virtual ~Buffer();
    virtual Buffer& putInt(int value);
    virtual Buffer& putLong(long value);
    void _put(int pos,BYTE b);
    void print();

protected:

private:
    int position=0;
    int limit;
    BYTE* hb;
    const int nextPutIndex(int nb);
    const void grow(int minCapacity);
    const int hugeCapacity(int minCapacity);
};

class Bits{
public:
    static void putInt(Buffer* bf, int pos, int x){
        bf->_put(pos    ,int3(x));
        bf->_put(pos + 1,int2(x));
        bf->_put(pos + 2,int1(x));
        bf->_put(pos + 3,int0(x));
    }
    static void putLong(Buffer* bf, int pos, long x){
        bf->_put(pos    ,long7(x));
        bf->_put(pos + 1,long6(x));
        bf->_put(pos + 2,long5(x));
        bf->_put(pos + 4,long3(x));
        bf->_put(pos + 3,long4(x));
        bf->_put(pos + 5,long2(x));
        bf->_put(pos + 6,long1(x));
        bf->_put(pos + 7,long0(x));
    }
private:
    static BYTE int3(int x){return (BYTE)(x >> 24); };
    static BYTE int2(int x){return (BYTE)(x >> 16); };
    static BYTE int1(int x){return (BYTE)(x >> 8 ); };
    static BYTE int0(int x){return (BYTE)(x      ); };

    static BYTE long7(long x){return (BYTE)(x >> 56); };
    static BYTE long6(long x){return (BYTE)(x >> 48); };
    static BYTE long5(long x){return (BYTE)(x >> 40); };
    static BYTE long4(long x){return (BYTE)(x >> 32); };
    static BYTE long3(long x){return (BYTE)(x >> 24); };
    static BYTE long2(long x){return (BYTE)(x >> 16); };
    static BYTE long1(long x){return (BYTE)(x >> 8 ); };
    static BYTE long0(long x){return (BYTE)(x      ); };
};


#endif // BUFFER_H
