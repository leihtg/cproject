#include "stdio.h"
void main(){
	int a[][4]={1,2,3,4,5,6};
	int x=sizeof(a)/sizeof(a[0]);
	int y=sizeof(a[0])/sizeof(a[0][0]);
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	//printf("%d\n",x);
	//printf("%d\n",y);
}