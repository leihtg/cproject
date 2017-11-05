#include <stdio.h>
#include <string.h>
void main(){
	FILE *file=fopen("F:\\c.txt","r");
	char str[40];
	memset(str,0,sizeof(str));
	int i=1;
	while(!feof(file)){
		
		fgets(str,sizeof(str),file);
		
		printf("第%d行 长度%2d |%s\n",i++,strlen(str),str);
	}
}