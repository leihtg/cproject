#include "Fac.h"
#include "iostream.h"
#pragma comment(lib,"DllDemo.lib")

void main(){
	int n;
	cout<<"静态测试DLL\n";
	while(true){
		cout<<"请输入用于计算阶乘的数值\n";
		cin>>n;
		int r=Fun(n);
		cout<<"计算的结果："<<r<<endl;

	}
}