#pragma once
struct RegType
{
	DWORD type;
	CString value;
};

class CRegHandle
{
private:
	HKEY hKey;
public:
	CRegHandle();
	virtual ~CRegHandle();
	CString queryKey(CString key);
	BOOL setKey(CString key, CString value);
	BOOL setKey(CString key, CListBox& listBox);
	RegType queryReg(CString key);
};


