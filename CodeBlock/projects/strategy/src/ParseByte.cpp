#include "ParseByte.h"
using namespace std;

ParseByte::ParseByte(const char* path)
{
    std::cout<<path<<std::endl;
    FILE* fp=fopen(path,"rb");
    fseek(fp,0,SEEK_END);
    int size_=ftell(fp);
    rewind(fp);
    byte* arr=(byte*)malloc(size_);
    this->destory=this->data=arr;
    int c=fgetc(fp);
    int i=1,j=0;
    while(!feof(fp))
    {
        *arr++=c;
//        j++;
//            cout<<c<<",";
//        if(i++%20==0){
//            cout<<endl;
//        }
        c=fgetc(fp);
    }
    fclose(fp);
}

ParseByte::~ParseByte()
{
    free(this->destory);
}
void ParseByte::parse()
{
    this->bigEndian=nextShort()==1;
    int secNum=nextInt();
    cout<<"SecurityÊýÄ¿:"<<secNum<<endl;
    for(int i=0; i<secNum; i++)
    {
        cout<<"========="<<(i+1)<<"========"<<endl;
        long ds=nextLong();
        cout<<"dataSize    :"<<ds<<endl;
        int ids=nextChar();
        char* name=nextString(ids);
        cout<<"name        :"<<name<<endl;
        int cols=nextInt();
        for(int j=0; j<cols; j++)
        {
            int cns=nextChar();
            char* colName=nextString(cns);
            cout<<"            colName     :"<<colName<<endl;
            int colType=nextShort();

            int rows=nextInt();
            for(int k=0; k<rows; k++)
            {
                switch(colType)
                {
                case 0:
                    nextInt();
                    break;
                case 1:
                    nextLong();
                    break;
                case 2:
                    nextDouble();
                    break;
                }
            }
        }

    }

}
char ParseByte::nextChar()
{
    byte* old=this->data;
    this->data=this->data+2;
    if(bigEndian)
    {
        reverse_(old,2);
    }
    return *(char*)old;
}

char* ParseByte::nextString(int s)
{
    byte* old=this->data;
    this->data+=s;
    char c[s+1];
    int i=0;
    for(; i<s; i++)
    {
        c[i]=*old++;
    }
    c[i]='\0';
    return c;
}

int ParseByte::nextInt()
{
    byte* old=this->data;
    this->data=this->data+4;
    if(bigEndian)
    {
        reverse_(old,4);
    }
    return *(int*)old;
}

long ParseByte::nextLong()
{
    byte* old=this->data;
    this->data+=8;
    if(bigEndian)
    {
        reverse_(old,8);
    }
    return *(long*)old;
}

double ParseByte::nextDouble()
{
    byte* old=this->data;
    this->data+=8;
    if(bigEndian)
    {
        reverse_(old,8);
    }
    return *(double*)old;
}

void ParseByte::reverse_(byte* d, int len)
{
    byte tmp;
    cout<<"reverse:"<<endl;
    for(int i=0; i<len; i++)
    {
        tmp=d[i];
        cout<<(int)tmp<<",";
        d[i]=d[len-i-1];
        d[len-i-1]=tmp;
    }
    cout<<endl;
}
short ParseByte::nextShort()
{
    byte* old=this->data;
    this->data=this->data+1;
    return *old;
}

