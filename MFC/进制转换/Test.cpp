#include "iostream.h"
#include "string.h"
void main(){
	int num;
	int n;
	int c[128]={0};
	cout<<"输入一个整数："<<endl;
	cin>>num;
	cout<<"输入要转换的进制"<<endl;
	cin>>n;
	int i=0,a=0;
	while(num!=0){
		c[i++]=num%n;
		num=num/n;
		a++;
	}
	cout<<"转换后的值为：";
	for(i=a-1;i>=0;i--){
		cout<<c[i];
	}
	cout<<endl;
}