#if !defined(AFX_DOWNOCX_H__8B7B5E27_010E_4F7D_AEBC_63F0AD9B3C1F__INCLUDED_)
#define AFX_DOWNOCX_H__8B7B5E27_010E_4F7D_AEBC_63F0AD9B3C1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DownOcx.h : main header file for DOWNOCX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDownOcxApp : See DownOcx.cpp for implementation.

class CDownOcxApp : public COleControlModule
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

#endif // !defined(AFX_DOWNOCX_H__8B7B5E27_010E_4F7D_AEBC_63F0AD9B3C1F__INCLUDED)
