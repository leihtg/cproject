// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef unsigned char u8;
typedef unsigned int u16;

void getcount(u8 arr[]){
	for (int i = 0; i < 7; i++){
		arr[i] = arr[i] + 1;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	u8 arr[] = { 1, 2, 3, 4, 1, 2, 3 };
	getcount(arr);
	return 0;
}

