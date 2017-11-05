// Ocx.h : main header file for the OCX application
//

#if !defined(AFX_OCX_H__FCF9E73D_99B4_481A_A3B7_4C1D69E4721E__INCLUDED_)
#define AFX_OCX_H__FCF9E73D_99B4_481A_A3B7_4C1D69E4721E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COcxApp:
// See Ocx.cpp for the implementation of this class
//

class COcxApp : public CWinApp
{
public:
	COcxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COcxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCX_H__FCF9E73D_99B4_481A_A3B7_4C1D69E4721E__INCLUDED_)
