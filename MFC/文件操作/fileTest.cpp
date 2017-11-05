#include "stdio.h"
#include "io.h"
void main(){
	_finddata_t t;
	long hd=_findfirst("F:\\สำฦต\\C++\\*.*",&t);
	if(hd){
		int a=_findnext(hd,&t);
		while(!a){
			printf("%s\n",t.name);
			a=_findnext(hd,&t);
		}
	}
}