#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <string>
#include <sstream>
#include <iostream>
#include "whole.h"

class illegalParameterValue;
template<class T> extern
int indexOfMax(T a[], int n);

template<class T>
class MySort
{
public:
    MySort() {};
    virtual ~MySort() {};
    //—°‘Ò≈≈–Ú
    void selectSort(T a[],int n);
    //≤Â»Î≈≈–Ú
    void insertSort(T a[],int& n, const T& x);
    void print();
protected:

private:
    T* a;
    int size;
};


template<typename T>
void MySort<T>::selectSort(T a[], int n)
{
    for(int size=n; size>1; size--)
    {
        int j = indexOfMax(a,size);
        std::swap(a[j],a[size-1]);
    }
    this->a=a;
    this->size=n;

}
template<class T>
void MySort<T>::insertSort(T a[],int& n, const T& x)
{
    int i;
    for(i=n-1; i>=0&&x<a[i]; i--)
    {
        a[i+1]=a[i];
    }
    a[i+1]=x;
    n++;
}

template<class T>
void MySort<T>::print()
{
    std::stringstream ss;
    std::string str("["),s;
    for(int i=0; i<size; i++)
    {
        ss<<a[i];
        ss>>s;
        str+=s+",";
        ss.clear();
    }
    if(str.size()>1)
    {
        str=str.substr(0,str.size()-1);
    }
    str += "]";
    std::cout<<str<<std::endl;
}
#endif // SELECTIONSORT_H
