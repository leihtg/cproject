#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void sort(int *arr);
void main(){
	int arr[10];
	
	printf("ÇëÊäÈë10¸öÊı\n");
	for(int i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr);
	for(i=0;i<10;i++){
			printf("%d <",arr[i]);
		}
	
}
void sort(int *arr){
	int tmp;
	int n=10;
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
		}
	}
		
}