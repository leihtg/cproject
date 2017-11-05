// popmenu.h : main header file for the POPMENU application
//

#if !defined(AFX_POPMENU_H__A762C45A_2B7D_464D_ACB7_C118968C5F91__INCLUDED_)
#define AFX_POPMENU_H__A762C45A_2B7D_464D_ACB7_C118968C5F91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPopmenuApp:
// See popmenu.cpp for the implementation of this class
//

class CPopmenuApp : public CWinApp
{
public:
	CPopmenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopmenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPopmenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPMENU_H__A762C45A_2B7D_464D_ACB7_C118968C5F91__INCLUDED_)
