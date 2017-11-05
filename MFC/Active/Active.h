// Active.h : main header file for the ACTIVE application
//

#if !defined(AFX_ACTIVE_H__D96C5CF6_AA48_4698_BB28_9B35C3635ACA__INCLUDED_)
#define AFX_ACTIVE_H__D96C5CF6_AA48_4698_BB28_9B35C3635ACA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CActiveApp:
// See Active.cpp for the implementation of this class
//

class CActiveApp : public CWinApp
{
public:
	CActiveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActiveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CActiveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACTIVE_H__D96C5CF6_AA48_4698_BB28_9B35C3635ACA__INCLUDED_)
