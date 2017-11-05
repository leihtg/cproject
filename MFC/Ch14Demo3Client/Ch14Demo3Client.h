// Ch14Demo3Client.h : main header file for the CH14DEMO3CLIENT application
//

#if !defined(AFX_CH14DEMO3CLIENT_H__15945873_6E24_4508_B813_A43AAC9A0DBD__INCLUDED_)
#define AFX_CH14DEMO3CLIENT_H__15945873_6E24_4508_B813_A43AAC9A0DBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCh14Demo3ClientApp:
// See Ch14Demo3Client.cpp for the implementation of this class
//

class CCh14Demo3ClientApp : public CWinApp
{
public:
	CCh14Demo3ClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCh14Demo3ClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCh14Demo3ClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CH14DEMO3CLIENT_H__15945873_6E24_4508_B813_A43AAC9A0DBD__INCLUDED_)
