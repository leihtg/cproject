#pragma once
class CRegHandle
{
private:
	HKEY hKey;
public:
	CRegHandle();
	virtual ~CRegHandle();
	CString queryKey(CString key);
	BOOL setKey(CString key, CString value);
};

