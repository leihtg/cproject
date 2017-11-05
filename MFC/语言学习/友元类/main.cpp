#include <iostream.h>
#include <string.h>
class student;
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
	friend class student;
};
class student{
	int num;
	char name[20];
	float grade;
	parent pt;
public:
	student(int n,char *str,float g,parent t){
		num=n;
		strcpy(name,str);
		grade=g;
		pt=t;
	}
	void show_parent(void) {		
		cout<<"父亲的名字："<<pt.f_name<<endl;
		cout<<"母亲的名字："<<pt.m_name<<endl;
		cout<<"电话号码  : "<<pt.tel<<endl;
		return;
	}
};
void main(void){
	parent p1("张三","张四","abc");
	student st(10001,"小学生",91.6F,p1);
	cout<<"父母信息:"<<endl;
	st.show_parent();
}