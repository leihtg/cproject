// TwoThread.h : main header file for the TWOTHREAD application
//

#if !defined(AFX_TWOTHREAD_H__617A3042_C51E_4CB3_8CEA_817DE1FDEF9E__INCLUDED_)
#define AFX_TWOTHREAD_H__617A3042_C51E_4CB3_8CEA_817DE1FDEF9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadApp:
// See TwoThread.cpp for the implementation of this class
//

class CTwoThreadApp : public CWinApp
{
public:
	CTwoThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTwoThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTwoThreadApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TWOTHREAD_H__617A3042_C51E_4CB3_8CEA_817DE1FDEF9E__INCLUDED_)
