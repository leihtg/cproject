#include <iostream.h>
class Base{
public:
	virtual void print() const{
		cout<<"调用基类的print方法."<<endl;
	}
};
class Derived: public Base{
public:
	virtual void print() const{
		cout<<"调用派生类的print方法。"<<endl;
	}
};
void main(){
	Base *pObj=new Base();
	pObj->print();
	delete pObj;
	pObj=new Derived();
	pObj->print();
	delete pObj;
	return;
	 
}