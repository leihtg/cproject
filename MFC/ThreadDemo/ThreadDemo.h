// ThreadDemo.h : main header file for the THREADDEMO application
//

#if !defined(AFX_THREADDEMO_H__601DB6CD_E808_441A_8265_CD1B939C6C46__INCLUDED_)
#define AFX_THREADDEMO_H__601DB6CD_E808_441A_8265_CD1B939C6C46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadDemoApp:
// See ThreadDemo.cpp for the implementation of this class
//

class CThreadDemoApp : public CWinApp
{
public:
	CThreadDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADDEMO_H__601DB6CD_E808_441A_8265_CD1B939C6C46__INCLUDED_)
