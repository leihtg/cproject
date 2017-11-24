// PicBrowser.h : main header file for the PICBROWSER application
//

#if !defined(AFX_PICBROWSER_H__A27A958D_B66F_443C_977E_6062839AF4B9__INCLUDED_)
#define AFX_PICBROWSER_H__A27A958D_B66F_443C_977E_6062839AF4B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserApp:
// See PicBrowser.cpp for the implementation of this class
//

class CPicBrowserApp : public CWinApp
{
public:
	CPicBrowserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicBrowserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPicBrowserApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICBROWSER_H__A27A958D_B66F_443C_977E_6062839AF4B9__INCLUDED_)
