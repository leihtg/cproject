// MsgBox.h : main header file for the MSGBOX application
//

#if !defined(AFX_MSGBOX_H__FC5B6CB0_D462_4B9A_9E6D_96F88D762A8F__INCLUDED_)
#define AFX_MSGBOX_H__FC5B6CB0_D462_4B9A_9E6D_96F88D762A8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMsgBoxApp:
// See MsgBox.cpp for the implementation of this class
//

class CMsgBoxApp : public CWinApp
{
public:
	CMsgBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMsgBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGBOX_H__FC5B6CB0_D462_4B9A_9E6D_96F88D762A8F__INCLUDED_)
