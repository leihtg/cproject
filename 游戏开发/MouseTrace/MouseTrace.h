// MouseTrace.h : main header file for the MOUSETRACE application
//

#if !defined(AFX_MOUSETRACE_H__854B1087_68DF_4734_A830_DE95071349CA__INCLUDED_)
#define AFX_MOUSETRACE_H__854B1087_68DF_4734_A830_DE95071349CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceApp:
// See MouseTrace.cpp for the implementation of this class
//

class CMouseTraceApp : public CWinApp
{
public:
	CMouseTraceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseTraceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMouseTraceApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSETRACE_H__854B1087_68DF_4734_A830_DE95071349CA__INCLUDED_)
