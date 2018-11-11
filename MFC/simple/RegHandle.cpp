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
	return queryReg(key).value;
}

BOOL CRegHandle::setKey(CString key, CString value){
	DWORD type = queryReg(key).type;
	if (REG_NONE == type){
		type = REG_SZ;
	}
	BOOL ret = ERROR_SUCCESS == RegSetValueEx(hKey, key, NULL, type, (BYTE*)value.GetBuffer(0), value.GetLength()*sizeof(TCHAR));
	LRESULT lret = 0;
	DWORD_PTR dwRet = 0;
	int a;
	if (ret){
		//发送消息立即生效
		//PostMessage(HWND_BROADCAST, WM_SETTINGCHANGE, NULL, NULL);
		
		LPARAM lpm = (LPARAM)"Environment";
		//SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, NULL, lpm, SMTO_NORMAL, 5000, &dwRet);
		//SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, NULL, lpm, SMTO_NOTIMEOUTIFNOTHUNG, 5000, &dwRet);
		lret = SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, LPARAM("Environment"), SMTO_ABORTIFHUNG, 5000, &dwRet);
		a = GetLastError();
	}
	return ret;
}

RegType CRegHandle::queryReg(CString key){
	CString value;
	DWORD type = REG_SZ | REG_EXPAND_SZ | REG_MULTI_SZ;
	DWORD size = 512;
	BYTE* data = (BYTE*)malloc(size);
	long ret = RegQueryValueEx(hKey, key, NULL, &type, data, &size);
	while (ret == ERROR_MORE_DATA){
		data = (BYTE*)realloc(data, size);
		ret = RegQueryValueEx(hKey, key, NULL, &type, data, &size);
	}
	if (ERROR_SUCCESS != ret){
		value = "";
	}
	else
	{
		value = CString((TCHAR*)data, size);
	}
	return{ type, value };
}

BOOL CRegHandle::setKey(CString key, CListBox& listBox){
	CString path;
	for (int i = 0, len = listBox.GetCount(); i < len; i++){
		CString str;
		listBox.GetText(i, str);
		path += str;
		path.Append(_T(";"));
	}
	if (path == _T("")){
		return FALSE;
	}
	return setKey(key, path);
}
