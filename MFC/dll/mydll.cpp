#include "stdio.h"
extern "C" _declspec(dllexport)max(int,int);
int max(int i,int j){
	printf("输入的值：%d和%d",i,j);
	return i>j?i:j;
}