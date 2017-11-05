// FmodelDialog.h : main header file for the FMODELDIALOG application
//

#if !defined(AFX_FMODELDIALOG_H__76ABF915_3208_4C30_A2DD_4B7D8A7C1652__INCLUDED_)
#define AFX_FMODELDIALOG_H__76ABF915_3208_4C30_A2DD_4B7D8A7C1652__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFmodelDialogApp:
// See FmodelDialog.cpp for the implementation of this class
//

class CFmodelDialogApp : public CWinApp
{
public:
	CFmodelDialogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFmodelDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFmodelDialogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FMODELDIALOG_H__76ABF915_3208_4C30_A2DD_4B7D8A7C1652__INCLUDED_)
