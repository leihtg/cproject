#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
class Person{
public:
	string name;
	string age;
public:
	Person(string name,string age){
		this->name=name;
		this->age=age;
	}
	virtual void show()=0;
	/*{
		cout<<"我的名字："<<name<<",年龄："<<age<<endl;
	}*/
};

class Father:public Person{
	string height;
	int a;
public:
	Father(string name,string height="100",string age="90"):Person(name,age),a(99){
		this->height=height;
		cout<<"Father 构造器"<<endl;
	}
	virtual void show(){
		cout<<"爸爸的姓名："<<this->name<<",体重："<<height<<",年龄:"<<this->age<<endl;
	}
};
DWORD WINAPI fun(LPVOID lp);
DWORD WINAPI fun1(LPVOID lp);
int index=0;
volatile int tickes=100;
int main(){
/*	Person p=	Person("lht","25");
	p.show();
	Father f("father");
	f.show();
	Person *fp=new Father("呵呵");
	fp->show();
	*/
HANDLE h=CreateThread(NULL,0,fun,NULL,0,NULL);
HANDLE h1=CreateThread(NULL,0,fun1,NULL,0,NULL);
CloseHandle(h);
CloseHandle(h1);
/*
while(index++<1000)
	cout<<"main runing ----------"<<endl;
	*/
	Sleep(4000);
	return 0;
}
DWORD WINAPI fun(LPVOID lp){
	while(true){
		if(tickes>0){
			cout<<"Thread1 sell ticket:"<<tickes--<<endl;
		}else
			break;
	}
	/*
	while(index++<1000)
	cout<<"sub runing ==========="<<endl;
	*/
	return 0;
}
DWORD WINAPI fun1(LPVOID lp){
	while(true){
		if(tickes>0){
			cout<<"Thread2 sell ticket:"<<tickes--<<endl;
		}else
			break;
	}/*
	while(index++<1000)
	cout<<"sub runing ==========="<<endl;
	*/
	return 0;
}