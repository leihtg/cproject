#include "iostream.h"
#include "Windows.h"
typedef void (*fun)(double,double);
void main(){
	double s1,s2;
	cout<<"显式调用MFC DLL\n";
	while(true){
		HINSTANCE hdll;
		fun f;
		hdll=LoadLibrary("RegularDll.dll");
		if(hdll!=NULL){
			f=(fun)GetProcAddress(hdll,"ShowDlg");

		}
		cout<<"请输入文化成绩："<<endl;
		cin>>s1;
		cout<<"\n请输入艺术成绩\n";
		cin>>s2;
		f(s1,s2);
		FreeLibrary(hdll);
	}
}