#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void main(){
	string fileName;
	cout<<"请输入入文件名:"<<endl;
	cin>>fileName;
	ofstream fout(fileName.c_str());
	fout<<"Write something to this file! ～～～";
	fout.close();


	

	ifstream fin(fileName.c_str());
	char ch;
	while(fin.get(ch)){
		cout<<ch;
	}
	fin.close();


	
	

	cin.get();
}