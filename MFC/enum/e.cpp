#include "iostream"
using namespace std;
void main(){
	int a=8;
	int* myBalls=&a ;
	cout<<"my balls are "<<*myBalls<<endl;
	cout<<"Address is : "<<myBalls<<endl;
	*myBalls++;
	cout<<"Now ,my balls are : "<<*myBalls<<endl;

}