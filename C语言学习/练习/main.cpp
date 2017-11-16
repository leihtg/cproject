#include <windows.h>
#include <iostream>
using namespace std;

USHORT CheckSum(USHORT *buffer, int size){
	unsigned long cksum = 0;
	while (size >= 1){
		cksum += *buffer++;
		size -= sizeof(USHORT);
	}
	if (size){
		cksum += *(UCHAR*)buffer;
	}
	cksum = (cksum >> 16) + (cksum & 0xffff);
	cksum += (cksum >> 16);
	return (USHORT)(~cksum);
}
class Z;
class A{
public:
	void put(Z*);
};
class Z{
private:
	int i;
public:
	Z(int i){
		this->i = i;
	}
	void print(){
		cout << "i is " << i << endl;
	}
	friend class A;// 只有你赋予某个类为你的友元时，那个类才有访问你的私有数据的权利。
	friend void put(Z*);
	friend void A::put(Z*);
};
void A::put(Z* z){
	z->i = 20;
}
void put(Z* z){
	z->i = 10;
}
int main(){
	char ch[] = "178asdfasd";
	cout << CheckSum((USHORT*)ch, sizeof(ch)) << endl;
	cout << endl;
	cout << sizeof(USHORT) << endl;
	Z z(1);
	z.print();
	put(&z);
	z.print();
	A a;
	a.put(&z);
	z.print();
	return 0;
}