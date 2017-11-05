#include "iostream"
using namespace std;
class vector{
private:
	int x;
	int y;
	int z;
public:
	vector();
	vector(int X,int Y,int Z);
	vector operator+(vector v){
		vector temp;
		temp.x=this->x+v.x;
		temp.y=this->y+v.y;
		temp.z=this->z+v.z;
		return temp;
	}
	void print(){
		cout<<"{"<<x<<","<<y<<","<<z<<"}"<<endl;
	}
};

vector::vector(){
	x=0;
	y=0;
	z=0;
}
vector::vector(int X,int Y,int Z){
	x=X;
	y=Y;
	z=Z;
}
void main(){
	vector v1(12,33,59);
	vector v2(83,67,58);
	
	v1.print();
	v2.print();
	(v1+v2).print();
}