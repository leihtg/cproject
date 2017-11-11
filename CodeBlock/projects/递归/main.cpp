#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<class T>
void permutations(T list[], int k, int m) {
    if(k == m) {
        copy(list,list+m+1,ostream_iterator<T>(cout,""));
        cout<<endl;
    } else {
        for(int i=k; i<=m; i++) {
            swap(list[k],list[i]);
            permutations(list,k+1,m);
            swap(list[k],list[i]);
        }
    }
};
class Man{
private:
    int i;
    int j;
public:
    void setI(int i){
        this->i=i;
    }
    void setJ(int j){
        this->j=j;
    }
    void print(){
        cout<<i<<"\t"<<j<<endl;;
    }
};
typedef Man *LMan;

void setWin(Man man){
    man.setI(10);
    man.setJ(20);
    man.print();
}

int main() {
//    Man man;
//    setWin(man);
//    man.print();
//    char ch[]= {'a','b','c','d'};
//    permutations<char>(ch,0,3);
    float fval;
    int ival;
    int *pi=0 ;
    int a=10;
    float* pf=new float(123);
    cout<<pi<<endl;
    cout<<pf<<"\t"<<*pf<<endl;
    fval=ival=(int)(pi=&a);
    cout<<pi<<"\t"<<*pi<<endl;
    cout<<fval<<"\t"<<ival<<endl;
    return 0;
}
