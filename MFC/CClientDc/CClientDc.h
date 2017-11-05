// CClientDc.h : main header file for the CCLIENTDC application
//

#if !defined(AFX_CCLIENTDC_H__D2109703_8565_43FD_9290_E374A26023B7__INCLUDED_)
#define AFX_CCLIENTDC_H__D2109703_8565_43FD_9290_E374A26023B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCClientDcApp:
// See CClientDc.cpp for the implementation of this class
//

class CCClientDcApp : public CWinApp
{
public:
	CCClientDcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCClientDcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCClientDcApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CCLIENTDC_H__D2109703_8565_43FD_9290_E374A26023B7__INCLUDED_)
