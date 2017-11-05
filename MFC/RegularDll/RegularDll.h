// RegularDll.h : main header file for the REGULARDLL DLL
//

#if !defined(AFX_REGULARDLL_H__F985FA24_DB28_4EB6_9ABE_EC7F1D78484D__INCLUDED_)
#define AFX_REGULARDLL_H__F985FA24_DB28_4EB6_9ABE_EC7F1D78484D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRegularDllApp
// See RegularDll.cpp for the implementation of this class
//

class CRegularDllApp : public CWinApp
{
public:
	CRegularDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegularDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CRegularDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGULARDLL_H__F985FA24_DB28_4EB6_9ABE_EC7F1D78484D__INCLUDED_)
