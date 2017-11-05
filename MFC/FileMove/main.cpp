#include <stdio.h>
void main(){
	FILE* file;
	FILE* f;
	file=fopen("F:\\视频\\C++\\this指针和类的继承\\this指针和类的继承.mp4","rb");
	f=fopen("F:\\视频\\C++\\this指针和类的继承.mp4","wb");
	if(file==NULL){
		printf("失败");
		
	}else{
		printf("正在复制……\n");
		while(!feof(file)){
			fputc(fgetc(file),f);
		}
		printf("成功！\n");
	}
	
	fclose(f);
	fclose(file);

}