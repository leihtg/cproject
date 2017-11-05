#include "stdio.h"

int result(int,int);
void main(){
	int x1,y1;
	printf("输入两个数字\n");
	scanf("%d%d",&x1,&y1);
	int r=result(x1,y1);
	printf("最大值:%d\n",r);
}

int result(int x,int y){
	return x>y?x:y;
}