// operator.cpp : 定义控制台应用程序的入口点。
//2017年12月3日21:46:58

#include "stdafx.h"
#include <iostream>

using namespace std;

class sample{
private:
	int value;
public:
	sample();
	sample& operator++();//声明重载前缀操作符++
	sample operator++(int);//声明重载后缀操作符++
	void display();
};
sample::sample(){
	value=0;
}
sample& sample::operator ++(){//前缀
	value+=1;
	return (*this);
}
sample sample::operator ++(int){//后缀
	sample sold (*this);
	value+=1;
	return sold;
}
void sample::display(){
	cout<<"value="<<value<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	sample s1;
	s1.display();
	(s1++).display();
	s1.display();
	s1++;
	s1.display();
	(++s1).display();
	s1.display();

	cin.get();
	return 0;
}

