#include <iostream.h>
class sample{
private:
	int value;
public:
	sample(int x){
		this->value=x;
	}
	int getvalue(){
		return value;
	}
	
};
void main(){
	sample* p=new sample(100);
	cout<<p->getvalue()<<endl;
	
	return;
}