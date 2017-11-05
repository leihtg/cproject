#include<iostream>
#include<cstdlib>
using namespace std;

template<class type>
type max(type x,type y){
	return (x>y)?x:y;
};

void main(){
	int a,b;
	a=rand();
	b=rand();
	cout<<"a的值为："<<a<<endl;
	cout<<"b的值为："<<b<<endl;
	cout<<"它们的最大值为："<<max<int>(a,b)<<endl;


	double a1,b1;
	a1=rand();
	b1=rand();
	cout<<"a1的值为："<<a1<<endl;
	cout<<"b1的值为："<<b1<<endl;
	cout<<"它们的最大值为："<<max(a1,b1)<<endl;


}