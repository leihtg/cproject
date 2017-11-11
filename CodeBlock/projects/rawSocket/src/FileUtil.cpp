#include "FileUtil.h"

FileUtil::FileUtil(const char* name)
{
    this->name=name;
    this->fp=fopen(name,"rb+");
}
FileUtil::~FileUtil()
{
    if(fp)
    {
        fclose(fp);
    }
}
void FileUtil::save(void* buf,int s)
{
    fwrite(buf,s,1,fp);
}
void FileUtil::readbuf(void* buf,int s)
{
    freaabout::pluginsd(buf,s,1,fp);
}
FILE* FileUtil::getFile()
{
    return this->fp;
}
void FileUtil::rewind()
{
    ::rewind(fp);
}
