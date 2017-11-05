#if !defined(AFX_OCXDEMO_H__A9E59BAC_4194_4438_BEC2_7287165D0405__INCLUDED_)
#define AFX_OCXDEMO_H__A9E59BAC_4194_4438_BEC2_7287165D0405__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OcxDemo.h : main header file for OCXDEMO.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COcxDemoApp : See OcxDemo.cpp for implementation.

class COcxDemoApp : public COleControlModule
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

#endif // !defined(AFX_OCXDEMO_H__A9E59BAC_4194_4438_BEC2_7287165D0405__INCLUDED)
