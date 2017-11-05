// socket.h : main header file for the SOCKET application
//

#if !defined(AFX_SOCKET_H__8CFC59F5_4B7F_464A_A74E_753513FF5DA8__INCLUDED_)
#define AFX_SOCKET_H__8CFC59F5_4B7F_464A_A74E_753513FF5DA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSocketApp:
// See socket.cpp for the implementation of this class
//

class CSocketApp : public CWinApp
{
public:
	CSocketApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSocketApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSocketApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKET_H__8CFC59F5_4B7F_464A_A74E_753513FF5DA8__INCLUDED_)
