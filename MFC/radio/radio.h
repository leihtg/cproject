// radio.h : main header file for the RADIO application
//

#if !defined(AFX_RADIO_H__7D3DF4D9_DD25_4DDA_9973_23B52ECE56AD__INCLUDED_)
#define AFX_RADIO_H__7D3DF4D9_DD25_4DDA_9973_23B52ECE56AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRadioApp:
// See radio.cpp for the implementation of this class
//

class CRadioApp : public CWinApp
{
public:
	CRadioApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRadioApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRadioApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RADIO_H__7D3DF4D9_DD25_4DDA_9973_23B52ECE56AD__INCLUDED_)
