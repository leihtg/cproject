// replace.h : main header file for the REPLACE application
//

#if !defined(AFX_REPLACE_H__71B794CB_C9FC_46B1_8F73_9DB65FB5A8BF__INCLUDED_)
#define AFX_REPLACE_H__71B794CB_C9FC_46B1_8F73_9DB65FB5A8BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReplaceApp:
// See replace.cpp for the implementation of this class
//

class CReplaceApp : public CWinApp
{
public:
	CReplaceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReplaceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReplaceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPLACE_H__71B794CB_C9FC_46B1_8F73_9DB65FB5A8BF__INCLUDED_)
