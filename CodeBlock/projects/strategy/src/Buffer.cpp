#include "Buffer.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

Buffer::Buffer():Buffer(10)
{
}

Buffer::Buffer(Buffer& b)
{
}

Buffer::Buffer(int limit)
{
    this->limit=limit;
    hb=new BYTE[limit] {0};
}

Buffer::~Buffer()
{
    if(hb)
    {
        delete[] hb;
    }
}

Buffer& Buffer::putInt(int value)
{
    Bits::putInt(this,nextPutIndex(4),value);
    return *this;
}

Buffer& Buffer::putLong(long value)
{
    Bits::putLong(this,nextPutIndex(8),value);
    return *this;
}

void Buffer::_put(int i,BYTE b)
{
    hb[i] = b;
}

void Buffer::print()
{
    string str="[",s;
    stringstream ss;
    for(int i=0;i<position;i++){
        ss<<(int)hb[i];
        ss>>s;
        str+=s+",";
        ss.clear();
    }
    if(str.size()>1)
    {
        str=str.substr(0,str.size()-1);
    }

    str+="]";
    cout<<str<<endl;
}

const int Buffer::nextPutIndex(int nb)
{
    while(limit - position<nb)
    {
        grow(position+nb);
    }
    int p = position;
    position += nb;
    return p;
}

const void Buffer::grow(int minCapacity)
{
    // overflow-conscious code
    int oldCapacity = limit;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity - minCapacity < 0)
        newCapacity = minCapacity;
    if (newCapacity - MAX_ARRAY_SIZE > 0)
        newCapacity = hugeCapacity(minCapacity);
    limit = newCapacity;

    this->hb=(BYTE*)realloc(hb,limit);
}

const int Buffer::hugeCapacity(int minCapacity)
{
//    if (minCapacity < 0) // overflow
//        throw new OutOfMemoryError();
    return (minCapacity > MAX_ARRAY_SIZE) ?
           MAX_VALUE :
           MAX_ARRAY_SIZE;
}

