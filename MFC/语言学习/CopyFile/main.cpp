#include<io.h>
#include<iostream.h>
#include<string>
using namespace std;
void main(){
	_finddata_t file;//要复制的文件
	string frmPath="F:\\电视剧\\薛仁贵传奇\\*";//要复制的文件夹路径
	string toPath="E:\\360云盘\\薛仁贵传奇\\";//目的文件夹
	FILE* f,*t;
	char str[100],s[100];
	char temp[2048];

	memset(str,0,sizeof(str));
	memset(s,0,sizeof(s));
	int size=0;
	long has=_findfirst(frmPath.data(),&file);
	if(has){
		while(_findnext(has,&file)==0){
			if(file.name[0]!='.'){
				memcpy(str,frmPath.data(),frmPath.size()-1);
				memcpy(s,toPath.data(),toPath.size());
				strcat(str,file.name);
				strcat(s,file.name);
				cout<<"正在复制："<<file.name<<endl;
				f=fopen(str,"rb");
				t=fopen(s,"w");
			
				while(!feof(f)){
				//	memset(temp,0,sizeof(temp));
				//	fread(temp,2048,1,f);
				//	fwrite(temp,strlen(temp),1,t);
				
					fputc(fgetc(f),t);
				}
				cout<<ftell(f)<<"--"<<ftell(t)<<endl;
				fclose(f);
				fclose(t);
				memset(str,0,sizeof(str));
				memset(s,0,sizeof(s));
			}			
		}
	}
	
}
