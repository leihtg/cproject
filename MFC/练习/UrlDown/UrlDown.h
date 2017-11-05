#if !defined(AFX_URLDOWN_H__6D408AF5_65A9_4029_B51F_842E6FE05E21__INCLUDED_)
#define AFX_URLDOWN_H__6D408AF5_65A9_4029_B51F_842E6FE05E21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// UrlDown.h : main header file for URLDOWN.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUrlDownApp : See UrlDown.cpp for implementation.

class CUrlDownApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_URLDOWN_H__6D408AF5_65A9_4029_B51F_842E6FE05E21__INCLUDED)
