#include <windows.h>
#include <iostream.h>
USHORT CheckSum(USHORT *buffer,int size){
	unsigned long cksum=0;
	while(size>=1){
		cksum+=*buffer++;
		size-=sizeof(USHORT);
	}
	if(size){
		cksum+=*(UCHAR*)buffer;
	}
	cksum=(cksum>>16)+(cksum&0xffff);
	cksum+=(cksum>>16);
	return (USHORT)(~cksum);
}
class Z;
class A{
public:
	put(Z*);
};
class Z{
	int i;
public:
	Z(int i){
		this->i=i;
	}
	void print(){
		cout<<"i is "<<i<<endl;
	}
	friend void put(Z*);
	friend  A::put(Z*);
};
A::put(Z* z){
	z->i=20;
}
void put(Z* z){
	z->i=10;
}
int main(){
	char ch[]="1";
	cout<<CheckSum((USHORT*)ch,sizeof(ch))<<endl;
/*
	cout<<endl;
	cout<<sizeof(USHORT)<<endl;
	Z z(1);
	z.print();
	put(&z);
	z.print();
	A a;
	a.put(&z);
	z.print();
	*/
	return 0;
}