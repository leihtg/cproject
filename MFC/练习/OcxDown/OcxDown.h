#if !defined(AFX_OCXDOWN_H__D6DD5D59_641B_4492_8399_05C625AF940E__INCLUDED_)
#define AFX_OCXDOWN_H__D6DD5D59_641B_4492_8399_05C625AF940E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OcxDown.h : main header file for OCXDOWN.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COcxDownApp : See OcxDown.cpp for implementation.

class COcxDownApp : public COleControlModule
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

#endif // !defined(AFX_OCXDOWN_H__D6DD5D59_641B_4492_8399_05C625AF940E__INCLUDED)
