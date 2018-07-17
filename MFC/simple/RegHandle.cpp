#include "stdafx.h"
#include "RegHandle.h"


CRegHandle::CRegHandle()
{
	long ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment"), NULL, KEY_ALL_ACCESS, &hKey);
	if (ret != ERROR_SUCCESS)
	{
		MessageBox(AfxGetMainWnd()->m_hWnd, _T("打开注册表失败"), _T("提示"), NULL);
	}
}


CRegHandle::~CRegHandle()
{
	RegCloseKey(hKey);
}

CString CRegHandle::queryKey(CString key)
{
	DWORD type = REG_SZ | REG_EXPAND_SZ | REG_MULTI_SZ;
	DWORD size = 512;
	BYTE* data = (BYTE*)malloc(size);
	long ret = RegQueryValueEx(hKey, key, NULL, &type, data, &size);
	while (ret == ERROR_MORE_DATA){
		data = (BYTE*)realloc(data, size);
		ret = RegQueryValueEx(hKey, key, NULL, &type, data, &size);
	}

	return CString((TCHAR*)data, size);
}

BOOL CRegHandle::setKey(CString key, CString value){
	return ERROR_SUCCESS == RegSetValueEx(hKey, key, NULL, NULL, (BYTE*)value.GetBuffer(0), value.GetLength());
}