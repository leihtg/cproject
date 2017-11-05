#include <stdio.h>
#include <windows.h> 
#define MAX_PATH 200
BOOL IsRoot(LPCTSTR lpszPath){ 
	TCHAR szRoot[4]; 
	wsprintf(szRoot, "%c:\\", lpszPath[0]); 
	return (lstrcmp(szRoot, lpszPath) == 0); 
} 

void FindInAll(::LPCTSTR lpszPath) {
	TCHAR szFind[MAX_PATH]; 
	lstrcpy(szFind, lpszPath); 
	if (!IsRoot(szFind)) {
		lstrcat(szFind, "\\");
	} 
	lstrcat(szFind, "*.*"); // 找所有文件 
	WIN32_FIND_DATA wfd; 
	HANDLE hFind = FindFirstFile(szFind, &wfd); 
	if (hFind == INVALID_HANDLE_VALUE) // 如果没有找到或查找失败 
		return; 
	
	do 
	{ 
		if (wfd.cFileName[0] == '.') 
			continue; // 过滤这两个目录 
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) 
		{ 
			TCHAR szFile[MAX_PATH]; 
			if (IsRoot(lpszPath)) 
				wsprintf(szFile, "%s%s", lpszPath, wfd.cFileName); 
			else 
				wsprintf(szFile, "%s\\%s", lpszPath, wfd.cFileName); 
			FindInAll(szFile); // 如果找到的是目录，则进入此目录进行递归 
		} 
		else 
		{ 
			TCHAR szFile[MAX_PATH]; 
			if (IsRoot(lpszPath)) 
				wsprintf(szFile, "%s%s", lpszPath, wfd.cFileName); 
			else 
				wsprintf(szFile, "%s\\%s", lpszPath, wfd.cFileName); 
			printf("%s\n",szFile); 
			// 对文件进行操作 
		} 
	}while (FindNextFile(hFind, &wfd)); 
	FindClose(hFind); // 关闭查找句柄 
	
} 
int main(int argc, char* argv[]){ 
	FindInAll("D:\\"); 

	return 0; 
} 