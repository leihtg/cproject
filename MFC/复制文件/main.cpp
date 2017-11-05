#include <stdio.h>
#include <string.h>
struct info{
	char name[20];
	char pic[20];
	char line[50];
	
	char *getStr(){
		memset(line,0,sizeof(line));
		strcat(line,name);
		strcat(line,"|");
		strcat(line,pic);
		strcat(line,"\n");
		return line;
	};
	void init(){
		memset(name,0,sizeof(name));
		memset(pic,0,sizeof(pic));
	}
};
void main(){
	
	char ch[10]; 
	FILE *fp;
	fp=fopen("C:\\Users\\Thinkpad\\Desktop\\test\\t.jpg","rb");
	FILE *txt;
	txt=fopen("C:\\Users\\Thinkpad\\Desktop\\test\\t.txt","wb");
	info in;
	for(int i=0;i<100;i++){
		sprintf(ch,"%d.jpg",i);
		FILE *f;
		f=fopen(ch,"wb");
		while(!feof(fp)){
			fputc(fgetc(fp),f);
		}
		
		strcpy(in.name,ch);
		strcpy(in.pic,ch);
		
		fputs(in.getStr(),txt);
		in.init();
		fseek(fp,0L,SEEK_SET);
		fclose(f);
		
	}
	fclose(fp);
	fclose(txt);
}