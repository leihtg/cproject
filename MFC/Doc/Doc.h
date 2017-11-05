// Doc.h : main header file for the DOC application
//

#if !defined(AFX_DOC_H__0EF5D454_9E4A_4885_A456_31B93156FF7A__INCLUDED_)
#define AFX_DOC_H__0EF5D454_9E4A_4885_A456_31B93156FF7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDocApp:
// See Doc.cpp for the implementation of this class
//

class CDocApp : public CWinApp
{
public:
	CDocApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDocApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOC_H__0EF5D454_9E4A_4885_A456_31B93156FF7A__INCLUDED_)
