// label.h : main header file for the LABEL application
//

#if !defined(AFX_LABEL_H__2697A435_5BF3_47A1_89D6_18C0EE76E891__INCLUDED_)
#define AFX_LABEL_H__2697A435_5BF3_47A1_89D6_18C0EE76E891__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLabelApp:
// See label.cpp for the implementation of this class
//

class CLabelApp : public CWinApp
{
public:
	CLabelApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabelApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLabelApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABEL_H__2697A435_5BF3_47A1_89D6_18C0EE76E891__INCLUDED_)
