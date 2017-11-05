// FmodalView.h : main header file for the FMODALVIEW application
//

#if !defined(AFX_FMODALVIEW_H__E98FBDB4_7767_4C48_BDA6_22FAFA08C530__INCLUDED_)
#define AFX_FMODALVIEW_H__E98FBDB4_7767_4C48_BDA6_22FAFA08C530__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewApp:
// See FmodalView.cpp for the implementation of this class
//

class CFmodalViewApp : public CWinApp
{
public:
	CFmodalViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFmodalViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFmodalViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FMODALVIEW_H__E98FBDB4_7767_4C48_BDA6_22FAFA08C530__INCLUDED_)
