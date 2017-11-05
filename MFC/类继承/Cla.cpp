#include "stdio.h"
#include "string.h"
const int len=128;




class Person{
private:
	char name[len];
	char age[len];
	char sex[len];
public:
	void setName(const char* n){
		strcpy(name,n);
	}
	void setAge(const char* age){
		strcpy(this->age,age);
	}
	void setSex(const char* sex){
		strcpy(this->sex,sex);
	}
	void printInfo();
	virtual void eat()=0;//虚方法
	Person(){
		printf("Person构造方法!\n");
	}
};
void Person::printInfo(){
	printf("姓名:%s\n",name);
	printf("年龄:%s\n",age);
	printf("性别:%s\n",sex);
}
class Men:virtual public Person{
public:
	void eat(){
		printf("men 吃饭！\n");
	}
	Men(){
		printf("Men 构造方法!\n");
	}
};
class Women:virtual public Person{
public:
	void eat(){
		printf("women 吃饭！\n");
	}
	Women(){
		printf("Women 构造方法!\n");
	}
};
class Child:public Men,public Women{
public:
	void eat(){
		printf("Child 吃饭!\n");
	}
};

int main(){
/*	Person p;
	p.setName("lei");
	p.setAge("24");
	p.setSex("男");
	p.printInfo();
	*/
/*	Person *p=new Women();
	p->setName("刘丽娜");
	p->setAge("24");
	p->setSex("女");
	p->printInfo();
	p->eat();
*/
	Child *c=new Child();
	c->eat();
	return 0;
}