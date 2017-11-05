// timeTest.h : main header file for the TIMETEST application
//

#if !defined(AFX_TIMETEST_H__003806AC_F8E4_4120_BB7F_B86ADA1B3B5D__INCLUDED_)
#define AFX_TIMETEST_H__003806AC_F8E4_4120_BB7F_B86ADA1B3B5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimeTestApp:
// See timeTest.cpp for the implementation of this class
//

class CTimeTestApp : public CWinApp
{
public:
	CTimeTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimeTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMETEST_H__003806AC_F8E4_4120_BB7F_B86ADA1B3B5D__INCLUDED_)
