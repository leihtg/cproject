// dialog1.h : main header file for the DIALOG1 application
//

#if !defined(AFX_DIALOG1_H__E1DD5E22_A1DD_45A9_B1E8_A12D250059B9__INCLUDED_)
#define AFX_DIALOG1_H__E1DD5E22_A1DD_45A9_B1E8_A12D250059B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialog1App:
// See dialog1.cpp for the implementation of this class
//

class CDialog1App : public CWinApp
{
public:
	CDialog1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialog1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1_H__E1DD5E22_A1DD_45A9_B1E8_A12D250059B9__INCLUDED_)
