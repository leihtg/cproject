// 图形和CArray.h : main header file for the 图形和CARRAY application
//

#if !defined(AFX_CARRAY_H__56E8A1DA_8C99_4A7E_A5AE_EB03BFC2DD7D__INCLUDED_)
#define AFX_CARRAY_H__56E8A1DA_8C99_4A7E_A5AE_EB03BFC2DD7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCArrayApp:
// See 图形和CArray.cpp for the implementation of this class
//

class CCArrayApp : public CWinApp
{
public:
	CCArrayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArrayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCArrayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAY_H__56E8A1DA_8C99_4A7E_A5AE_EB03BFC2DD7D__INCLUDED_)
