// time.h : main header file for the TIME application
//

#if !defined(AFX_TIME_H__D22D688B_D846_4903_ADC0_A0682EE86524__INCLUDED_)
#define AFX_TIME_H__D22D688B_D846_4903_ADC0_A0682EE86524__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimeApp:
// See time.cpp for the implementation of this class
//

class CTimeApp : public CWinApp
{
public:
	CTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIME_H__D22D688B_D846_4903_ADC0_A0682EE86524__INCLUDED_)
