#pragma once

#define FQ_CHECK_INVALIDARG_NULL(p) {if (NULL == (p)) {ASSERT(FALSE); return E_INVALIDARG;}}

#include <atlbase.h>

#define FQ_UNSPECIFIC_ERROR	_T("Error")
#define __FQ_CATCH_ALL__(statement) \
catch (_com_error& e)\
{\
    e;\
	ATLTRACE(_T("%s(%u) : exception (_com_error): %s | %s\r\n"), (LPCTSTR)_bstr_t((const char*)__FILE__), __LINE__, e.ErrorMessage(), (LPCTSTR)e.Description());\
    statement;\
}\
catch (CException* pEx)\
{\
    TCHAR sz[256] = {0};\
    pEx->GetErrorMessage(sz, 255);\
    ATLTRACE(_T("%s(%u) : exception (CException*): %s\r\n"), (LPCTSTR)_bstr_t((const char*)__FILE__), __LINE__, (LPCTSTR)_bstr_t(sz));\
    pEx->Delete();\
    statement;\
}\
catch (const char* error_msg)\
{\
    ATLTRACE(_T("%s(%u) : exception (const char*): %s\r\n"), (LPCTSTR)_bstr_t((const char*)__FILE__), __LINE__, (LPCTSTR)_bstr_t(error_msg));\
    statement;\
}\
catch (const wchar_t* error_msg)\
{\
    ATLTRACE(_T("%s(%u) : exception (const wchar*): %s\r\n"), (LPCTSTR)_bstr_t((const char*)__FILE__), __LINE__, (LPCTSTR)_bstr_t(error_msg));\
    statement;\
}

#ifdef _DEBUG

#define FQ_TRY try
#define FQ_CATCH_ALL(statement) __FQ_CATCH_ALL__(statement)

#else

#define FQ_TRY try
#define FQ_CATCH_ALL(statement) \
__FQ_CATCH_ALL__(statement)\
catch (...)\
{\
	ATLTRACE(_T("%s(%u) : exception (...): Unknown error.\r\n"), (LPCTSTR)_bstr_t((const char*)__FILE__), __LINE__);\
	statement;\
}

#endif

#define FQ_CATCH_ALL_NOTHING()	FQ_CATCH_ALL(BYTE nothing; nothing)

#ifdef _AFXDLL
inline CString GetModulePath(HMODULE hModule = NULL)
{
	CString strPath;

	::GetModuleFileName(hModule, strPath.GetBuffer(MAX_PATH + 1), MAX_PATH);
	strPath.ReleaseBuffer();

	int index = strPath.ReverseFind(_T('\\'));

	if (index > 0)
	{
		strPath = strPath.Left(index + 1);
	}
	else
	{
		ASSERT(FALSE);
		strPath = _T("\\");
	}

	return strPath;
}
#endif