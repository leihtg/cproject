#include "file.h"
#include <time.h>

File::File(string fp1,string fp2){
	this->fp1=fp1;
	this->fp2=fp2;
	
	_finddata_t f;
	memset(&f,0,sizeof(f));
	_findfirst(fp1.data(),&f);
	fName1=f.name;
	memset(&f,0,sizeof(f));
	_findfirst(fp2.data(),&f);
	fName2=f.name;
	
	fpL1=strlen(fp1.data())+1;
	fpL2=strlen(fp2.data())+1;
}
string File::substr(int start,const char *str){
	string s="";
	for(int i=0;i<strlen(str);i++){
		if(i>=start)s+=str[i];
	}
	return s;
}
void File::scan(CArray<myFile,myFile&> &arr,string dir,int start){
	//处理路径
	string path=dir+"\\*.*";
	_finddata_t f;
	memset(&f,0,sizeof(f));
	long fh=_findfirst(path.data(),&f);
	if(fh){
		while(_findnext(fh,&f)==0){
			myFile my;
			my.time=f.time_create;
			my.size=f.size;
			if(f.name[0]=='.'){
				my.path=substr(start,(dir+"\\").data());				
				arr.Add(my);
				continue;
			}
			string fname=dir+"\\"+f.name;
			if(f.attrib==_A_SUBDIR){
				scan(arr,fname,start);
			}else{
				my.path=substr(start,fname.data());				
				arr.Add(my);
			}
		}
	}else{
		myFile my;
		const	char *ch=(dir+"\\"+f.name).data();
		my.path=substr(start,ch);
		my.time=f.time_create;
		my.size=f.size;
		arr.Add(my);
	}
}
string File::getSize(long s){
	char str[128]={0};
	sprintf(str,"%dKB\n",s/1024);
	return str;
}
string File::getTime(long t){
	tm *utc=localtime(&t);
	char tmp[128]={0};
	strftime(tmp,sizeof(tmp),"%Y/%m/%d %H:%M:%S\n",utc);
	return tmp;
}
void File::compare(){
	CArray<myFile,myFile&> first;
	CArray<myFile,myFile&> second;
	
	scan(first,fp1,fpL1);
	scan(second,fp2,fpL2);
	//写入文件
	FILE *fname,*fsize,*ftime,*fcomp;
	fname=fopen((fp1+"_name.txt").data(),"w");
	fsize=fopen((fp1+"_size.txt").data(),"w");
	ftime=fopen((fp1+"_time.txt").data(),"w");
	fcomp=fopen((fp1+"_comp.txt").data(),"w");
	
	for(int i=0;i<first.GetSize();i++){
		myFile f=first.GetAt(i);
		
		fputs((f.path+"\n").data(),fname);
		fputs(getSize(f.size).data(),fsize);
		fputs(getTime(f.time).data(),ftime);
		
		for(int j=0;j<second.GetSize();j++){
			myFile f2=second.GetAt(j);
			if(f.path==f2.path){
				second.RemoveAt(j);
				j--;
			}
		}
	}
	fputs((fName1+"与"+fName2+"相比较缺少以下文件：\n").data(),fcomp);
	for(i=0;i<second.GetSize();i++){
		myFile mf=second.GetAt(i);
		fputs((mf.path+",").data(),fcomp);
		
	}
	fclose(fcomp);
	fclose(ftime);
	fclose(fsize);
	fclose(fname);
}

int main(){
	char f1[500]={0},f2[500]={0};
	cout<<"请输入第一个路径：";
	cin>>f1;
	cout<<"\n请输入第二个路径：";
	cin>>f2;
	
	File file(f1,f2);
	cout<<"正在比对，请稍后..."<<endl;
	file.compare();
	cout<<"\n比对结束！"<<endl;
	getchar();
	return 0;
}