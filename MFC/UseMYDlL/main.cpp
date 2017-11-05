#include "iostream.h"
#include "windows.h"
typedef int (*aa)(int);
void main(){
	HINSTANCE hdll=LoadLibrary("DllDemo.dll");
	aa f;
	int a;
	
	if(hdll!=NULL){
		f=(aa)GetProcAddress(hdll,"Fun");
	
	}
		cout<<"请输入一个数"<<endl;
		cin>>a;
		cout<<"阶乘为："<<f(a)<<endl;
	FreeLibrary(hdll);
	
}