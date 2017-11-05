// browse.h : main header file for the BROWSE application
//

#if !defined(AFX_BROWSE_H__5FB0EA88_89D1_43CB_9AF0_4F31D89ED67A__INCLUDED_)
#define AFX_BROWSE_H__5FB0EA88_89D1_43CB_9AF0_4F31D89ED67A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBrowseApp:
// See browse.cpp for the implementation of this class
//

class CBrowseApp : public CWinApp
{
public:
	CBrowseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBrowseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSE_H__5FB0EA88_89D1_43CB_9AF0_4F31D89ED67A__INCLUDED_)
