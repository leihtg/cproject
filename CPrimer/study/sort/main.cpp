#include <cstdio>

void shellSort(int arr[],int len);
int main(int argc,char* argv[]){
	int arr[]={1,3,5,2,4,0,6,8,7,9};
	shellSort(arr,10);
	for(int i=0;i<10;i++){
		printf("%d,",arr[i]);
	}
	printf("\n");
	getchar();
}

void shellSort(int arr[],int len){
	for(int increment=len/2;increment>0;increment/=2){
		for(int i=increment;i<len;i++){
			int temp=arr[i];
			int k=i-increment;
			while(k>=0&&temp<arr[k]){
				arr[k+increment]=arr[k];
				k-=increment;
			}
			arr[k+increment]=temp;
		}
	}
}
