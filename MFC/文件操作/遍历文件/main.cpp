#include <stdio.h>
#include <io.h>
#include <string.h>
#include <time.h>
static int i=0;
FILE *file;
void findAll(const char *p){
	char path[2000];
	memset(path,0,sizeof(path));
	strcat(path,p);
	strcat(path,"\\*.*");
	_finddata_t t;
	long l=_findfirst(path,&t);
	if(l){
		int n=_findnext(l,&t);
		while(!n){
			if(t.name[0]!='.'){
				memset(path,0,sizeof(path));
				strcat(path,p);
				strcat(path,"\\");
				strcat(path,t.name);
				fprintf(file,"%s\t|生成时间：%s",path,ctime(&t.time_create));
				i++;
				findAll(path);
			}
			n=_findnext(l,&t);
		}
	}
	
}
void main(){
	time_t ct, et;
	time(&ct);
	file=fopen("D:\\遍历手机文件.txt","w");
	fprintf(file,"扫描时间：%s\n",ctime(&ct));
	findAll("F:");
	fprintf(file,"一共有%d\n",i);
	time(&et);
	fprintf(file,"用时%ld秒\n",et-ct);
	fclose(file);

}
