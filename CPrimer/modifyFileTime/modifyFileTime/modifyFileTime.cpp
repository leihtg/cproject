// modifyFileTime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <Windows.h>  
#include <stdio.h>  

bool ConvertFileTimeToLocalTime(const FILETIME *lpFileTime, SYSTEMTIME *lpSystemTime)
{
	if (!lpFileTime || !lpSystemTime) {
		return false;
	}
	FILETIME ftLocal;
	FileTimeToLocalFileTime(lpFileTime, &ftLocal);
	FileTimeToSystemTime(&ftLocal, lpSystemTime);
	return true;
}

bool ConvertLocalTimeToFileTime(const SYSTEMTIME *lpSystemTime, FILETIME *lpFileTime)
{
	if (!lpSystemTime || !lpFileTime) {
		return false;
	}

	FILETIME ftLocal;
	SystemTimeToFileTime(lpSystemTime, &ftLocal);
	LocalFileTimeToFileTime(&ftLocal, lpFileTime);
	return true;
}

int main()
{
	HANDLE hFile;
	FILETIME ftCreate, ftAccess, ftWrite;
	SYSTEMTIME stCreate, stAccess, stWrite;
	int year, month, day;

	hFile = CreateFile(L"C:\\Users\\leihtg\\Desktop\\abc", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	if (INVALID_HANDLE_VALUE == hFile) {
		printf("CreateFile error: %d", GetLastError());
		ExitProcess(0);
	}
	GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite);
	ConvertFileTimeToLocalTime(&ftCreate, &stCreate);
	ConvertFileTimeToLocalTime(&ftAccess, &stAccess);
	ConvertFileTimeToLocalTime(&ftWrite, &stWrite);

	printf("yyyy-MM-dd:");
	scanf_s("%d-%d-%d", &year, &month, &day);
	stAccess.wYear = stWrite.wYear = year;
	stAccess.wMonth = stWrite.wMonth = month;
	stAccess.wDay = stWrite.wDay = day;

	ConvertLocalTimeToFileTime(&stAccess, &ftAccess);
	ConvertLocalTimeToFileTime(&stWrite, &ftWrite);

	SetFileTime(hFile, &ftAccess, &ftAccess, &ftWrite);
	CloseHandle(hFile);
	return 0;
}
