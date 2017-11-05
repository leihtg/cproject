#include <stdio.h>
#include <stdlib.h>
void main(){
	FILE *f_pic,*f_file,*f_finish;
	char pic_name[20],file_name[20],finish_name[20];
	printf("请输入需要合成的图片和文件名称：\n");
	printf("图片:");
	scanf("%s",pic_name);
	printf("文件：");
	scanf("%s",file_name);
	printf("生成为：");
	scanf("%s",finish_name);
	
	if(!(f_pic=fopen(pic_name,"rb"))){
		printf("Cannot open the picture %s!",pic_name);
		return;
	}
	if(!(f_file=fopen(file_name,"rb"))){
		printf("Cannot open the file %s!",file_name);
		return;
	}
	if(!(f_finish=fopen(finish_name,"wb"))){
		printf("Cannot open the file %s!",finish_name);
		return;
	}
	char ch;
	while(!(feof(f_pic))){
		ch=fgetc(f_pic);
		fputc(ch,f_finish);
	}
	fclose(f_pic);
	while(!(feof(f_file))){
		ch=fgetc(f_file);
		fputc(ch,f_finish);
	}
	fclose(f_file);
	fclose(f_finish);
	system("pause");
	
}