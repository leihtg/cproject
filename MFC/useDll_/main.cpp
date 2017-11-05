#include "windows.h"
#include "stdio.h"
typedef int (*func)(int,int);
void main(){
   int i;
   int j;
   printf("请输入两个数:\n");
   scanf("%d %d",&i,&j);
   HINSTANCE hdll;
   func f;
   hdll=LoadLibrary("dll.dll");
   if(hdll!=NULL){
	   f=(func)GetProcAddress(hdll,"max");
	   int a=f(i,j);
	   printf("\n输出结果:%d\n",a);
   }
   FreeLibrary(hdll);
}