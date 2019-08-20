// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <string>
#include <tchar.h>
#include <Windows.h>

struct FileTime
{
	FILETIME createTime, accessTime, writeTime;
	unsigned    attrib;
	_fsize_t    size;
};



// TODO:  在此处引用程序需要的其他头文件
