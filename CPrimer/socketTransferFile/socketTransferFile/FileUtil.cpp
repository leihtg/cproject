#include "stdafx.h"
#include "FileUtil.h"


std::wstring stringToWString(std::string& str){
	std::wstring wstr;

	int nlen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, NULL);
	wstr.resize(nlen);
	LPWSTR lpwstr = new wchar_t[nlen];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, lpwstr, nlen);

	wstr = lpwstr;
	delete[] lpwstr;
	return wstr;
}

FileUtil::FileUtil()
{

}

FileTime FileUtil::getFileTime(std::string file){
	std::wstring fp = stringToWString(file);
	HANDLE hFile = CreateFile(fp.c_str(), 0, 0, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	if (INVALID_HANDLE_VALUE == hFile) {
		printf("CreateFile error: %d", GetLastError());
		return{};
	}
	FileTime ft;
	GetFileTime(hFile, &ft.createTime, &ft.accessTime, &ft.writeTime);
	CloseHandle(hFile);
	return ft;
}

void FileUtil::setFileTime(std::string file, FileTime ft){
	std::wstring fp = stringToWString(file);
	HANDLE hFile = CreateFile(fp.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	SetFileTime(hFile, &ft.createTime, &ft.accessTime, &ft.writeTime);
	CloseHandle(hFile);
}
FileUtil::~FileUtil()
{

}
