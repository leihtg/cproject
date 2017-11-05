// netUrl.h : main header file for the NETURL application
//

#if !defined(AFX_NETURL_H__EDB54A10_AFCF_4BE7_AFE7_0609F781AE22__INCLUDED_)
#define AFX_NETURL_H__EDB54A10_AFCF_4BE7_AFE7_0609F781AE22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetUrlApp:
// See netUrl.cpp for the implementation of this class
//

class CNetUrlApp : public CWinApp
{
public:
	CNetUrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetUrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetUrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETURL_H__EDB54A10_AFCF_4BE7_AFE7_0609F781AE22__INCLUDED_)
