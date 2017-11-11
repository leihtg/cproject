#ifndef FILEUTIL_H
#define FILEUTIL_H
#include <stdio.h>

class FileUtil
{
    public:
        FileUtil(const char* name);
        virtual ~FileUtil();
        void save(void* buf,int s);
        void readbuf(void* buf,int s);
        FILE* getFile();
        void rewind();

    protected:

    private:
        const char* name;
        FILE* fp;
};

#endif // FILEUTIL_H
