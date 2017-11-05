#include <iostream>
#include <stdio.h>
using namespace std;

void main(){
	int zm=0;//字母
	int num=0;//数字
	int blank=0;//空格
	int ot=0;//其他字符
	cout<<"请输入一段话:"<<endl;
	char ch;
	while((ch=getchar())!='\n'){
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
			zm++;
		}else if(ch>='0'&&ch<='9'){
			num++;
		}else if(ch==' '){
			blank++;
		}else{
			ot++;
		}
	}
	cout<<"字母有："<<zm<<"个"<<endl;
	cout<<"数字有："<<num<<"个"<<endl;
	cout<<"空格有："<<blank<<"个"<<endl;
	cout<<"其他有："<<ot<<"个"<<endl;
	
}