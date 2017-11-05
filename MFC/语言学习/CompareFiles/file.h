#ifndef _MY
#define _MY
#include <string>
#include <io.h>
#include <iostream.h>
#include <afxtempl.h>
using namespace std;

typedef struct {
	string path;
	long time;
	long size;
} myFile;

class File{
public:
	File(string fp1,string fp2);
	void compare();
	string substr(int start,const char *str);
	string getTime(long t);
	string getSize(long s);
private:
	string fp1;//第一个目录路径
	string fp2;//第二个目录路径
	string fName1;
	string fName2;
	int fpL1;
	int fpL2;
	
	void scan(CArray<myFile,myFile&> &arr,string dir,int start);
};
#endif
