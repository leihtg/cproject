#include "stdafx.h"
#include "FileUtil.h"

std::wstring FileUtil::stringToWString(std::string& str){
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

bool FileUtil::createDirs(std::string dir){
	std::string sub;
	int pos = 0;
	int st;
	while ((st = dir.find("\\", pos)) != -1) {
		sub = dir.substr(0, st);
		pos = st + 1;
		int rt = _access(sub.c_str(), 0);
		if (rt == -1) {
			if (_mkdir(sub.c_str())) {
				return false;
			}
		}
	}
	return true;
}
FileUtil::~FileUtil()
{

}
