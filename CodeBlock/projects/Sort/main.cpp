#include <iostream>
#include "SelectionSort.h"

using namespace std;
void print(int arr[],int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
//
void shellSort(int arr[], int n) {
    int i,j,increment,tmp=0,c=0,d=0;
    for(increment=n/2; increment>0; increment/=2) {
        for(i=increment; i<n; i++) {
            bool flag=false;
            for(j=i; j>=increment&&arr[j-increment]>arr[j]; j-=increment) {
                flag=true;
                d++;
                tmp=arr[j];
                arr[j]=arr[j-increment];
                arr[j-increment]=tmp;
            }
            if(!flag) {
                c++;
            }
                        cout<<"----\t";
            print(arr,n);
        }
        cout<<"\t";
        print(arr,n);
    }
    print(arr,n);
    cout<<c<<"\t"<<d<<endl;
}

//Ï£¶ûÅÅÐò
void insertSort(int arr[],int n) {
    int i,j,increment,tmp,c=0,d=0;

    for(increment=n/2; increment>0; increment/=2) {
        for(i=increment; i<n; i++) {
            tmp=arr[i];
            bool flag=false;
            for(j=i; j>=increment&&tmp<arr[j-increment]; j-=increment) {
                flag=true;
                d++;
                arr[j]=arr[j-increment];
            }
            if(!flag)c++
                ;
            arr[j]=tmp;
            cout<<"----\t";
            print(arr,n);
        }
        cout<<"\t";
        print(arr,n);
    }

    print(arr,n);
    cout<<c<<"\t"<<d<<endl;
}

int main() {

    int arr[]= {10,8,9,7,6,4,5,3,1,2};
    print(arr,sizeof(arr)/sizeof(int));
    cout<<"====================="<<endl;;
    insertSort(arr,sizeof(arr)/sizeof(int));
    cout<<"*************************"<<endl;
    int *a=new int[10] {10,9,8,7,6,5,4,3,2,1};
    int a1[]={10,8,9,7,6,4,5,3,1,2};
    int a2[10];
//    arr={10,9,8,7,6,5,4,3,2,1};
    shellSort(a1,sizeof(a1)/sizeof(int));

//    MySort<int> sele=MySort<int>();
//    sele.selectSort(arr,sizeof(arr)/sizeof(int));
//    sele.print();
    return 0;
}

