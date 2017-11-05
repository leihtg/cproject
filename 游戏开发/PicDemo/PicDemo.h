// PicDemo.h : main header file for the PICDEMO application
//

#if !defined(AFX_PICDEMO_H__D6C5E5A1_1E64_41BA_961A_64130533315D__INCLUDED_)
#define AFX_PICDEMO_H__D6C5E5A1_1E64_41BA_961A_64130533315D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPicDemoApp:
// See PicDemo.cpp for the implementation of this class
//

class CPicDemoApp : public CWinApp
{
public:
	CPicDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPicDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICDEMO_H__D6C5E5A1_1E64_41BA_961A_64130533315D__INCLUDED_)
