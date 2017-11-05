#include <io.h>
#include <stdio.h>
int main()
{
	long Handle;
	
	struct _finddata_t FileInfo;
	if((Handle=_findfirst("D:\\*.*",&FileInfo))==-1L)
		printf("没有找到匹配的项目\n");
	else
	{
		printf("%s\n",FileInfo.name);
		while(_findnext(Handle,&FileInfo)==0){
			printf("%s\t%ld\n",FileInfo.name,FileInfo.size);
			
		}
		_findclose(Handle);
	}
	return 0;
}