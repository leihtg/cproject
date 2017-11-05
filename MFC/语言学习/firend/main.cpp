#include <iostream.h>
#include <string.h>

class parent{
	char f_name[20];
	char m_name[20];
	char tel[11];
public:
	parent(char *p1="",char *p2="",char *p3=""){
		strcpy(f_name,p1);
		strcpy(m_name,p2);
		strcpy(tel,p3);
	}
	friend void show(parent &p);
};
void show(parent &p) {
	cout<<"父亲的名字："<<p.f_name<<endl;
	cout<<"母亲的名字："<<p.m_name<<endl;
	cout<<"电 话 号码："<<p.tel<<endl;
	
}
void main(){
	
	parent p1;
	p1=parent("张三","李诗","123213123");
	show(p1);
}