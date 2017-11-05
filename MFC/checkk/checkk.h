// checkk.h : main header file for the CHECKK application
//

#if !defined(AFX_CHECKK_H__A27004F5_CAF2_4B03_8D26_0F5785312544__INCLUDED_)
#define AFX_CHECKK_H__A27004F5_CAF2_4B03_8D26_0F5785312544__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCheckkApp:
// See checkk.cpp for the implementation of this class
//

class CCheckkApp : public CWinApp
{
public:
	CCheckkApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckkApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCheckkApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKK_H__A27004F5_CAF2_4B03_8D26_0F5785312544__INCLUDED_)
