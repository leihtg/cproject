// fileDialog.h : main header file for the FILEDIALOG application
//

#if !defined(AFX_FILEDIALOG_H__B4ACFE49_7C3B_4999_AC11_B43F3BD5BA7C__INCLUDED_)
#define AFX_FILEDIALOG_H__B4ACFE49_7C3B_4999_AC11_B43F3BD5BA7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileDialogApp:
// See fileDialog.cpp for the implementation of this class
//

class CFileDialogApp : public CWinApp
{
public:
	CFileDialogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileDialogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEDIALOG_H__B4ACFE49_7C3B_4999_AC11_B43F3BD5BA7C__INCLUDED_)
