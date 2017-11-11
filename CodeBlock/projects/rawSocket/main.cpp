#include "RawSocket.h"
#include "FileUtil.h"
typedef struct _A{
    int i;
    int j;
    int l;
    int k;
    void print(){
        cout<<"i="<<i<<",j="<<j<<",k="<<k<<",l="<<l<<endl;
    }
}A,*Ap;
int main(int args,char *agrv[])
{
    RawSocket raw;
    raw.build(5000,7000);
    char name[]="C:\\Users\\Thinkpad\\Desktop\\test.log";
    FileUtil f(name);
    A a;
    a.j=2;
    a.i=1;
    a.k=3;
    a.l=4;
    f.save(&a,sizeof(a));
    A b;
    f.rewind();
    f.readbuf(&b,sizeof(b));
    b.print();



//    FileUtil f(name);
//    RawSocket s;
//    f.save(s);
    return 0;
}


