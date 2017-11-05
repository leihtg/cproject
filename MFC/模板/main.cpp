#include "iostream"
#include "string"
#include<conio.h>
using namespace std;

template<class Type>
void sw(Type t,Type y){
	printf("%d\n",(t+y));
}
void ch(int i,int j);
void main(){
	sw(1,2);
	sw<double>(1.2,2.3);
	ch(1,2);
}
void ch(int i,int j){
	char ch[128];
	cout<<"ÊäÈëÒ»¶Î»°"<<endl;
	cin.getline(ch,128);
	cout<<ch<<endl;
	
}