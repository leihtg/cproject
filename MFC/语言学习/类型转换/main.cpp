#include<iostream.h>
class Base{
private:
	int baseData;
public:
	Base(int baseIn);
	Base();
	void print() const;
};
Base::Base(int baseIn){
	this->baseData=baseIn;
};
Base::Base(){
};
void Base::print() const{
	cout<<"蕨类饮食的数据值为："<<baseData<<endl;
};

class Derived:public Base{
private:
	int deriveData;
public:
	Derived(int baseIn,int derivedIn);
	void print() const;
};
Derived::Derived(int baseIn,int derivedIn):Base(baseIn){
	deriveData=derivedIn;
};
void Derived::print() const{
	Base::print();
	cout<<"派生类中包含的数据值为："<<deriveData<<endl;
}

void main(){
	cout<<"转换之前:"<<endl;
	Base baseObj(10);
	baseObj.print();
	cout<<"转换之后:"<<endl;
	Derived derivedObj(3,5);
	baseObj=derivedObj;
	baseObj.print();

	cout<<"向下转换对象指针:===================="<<endl;
	Base *pB=new Derived(3,5);
	pB->print();
	Derived *pD=new Derived(4,10);
	pD=(Derived *)(pB);
	if(pD){
		pD->print();
	}
	return;
}
