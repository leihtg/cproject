#ifndef PARSEBYTE_H
#define PARSEBYTE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef char byte;

class ParseByte
{
public:
    ParseByte(const char* path);
    void parse();
    virtual ~ParseByte();

protected:

private:
    byte* data;
    byte* destory;
    bool bigEndian;
    short nextShort();
    char nextChar();
    char* nextString(int s);
    int nextInt();
    long nextLong();
    double nextDouble();
    void reverse_(byte* d,int len);
};

#endif // PARSEBYTE_H
