// CCritical线程同步.h : main header file for the CCRITICAL线程同步 application
//

#if !defined(AFX_CCRITICAL_H__ED84A901_940C_4E3F_825D_235866024221__INCLUDED_)
#define AFX_CCRITICAL_H__ED84A901_940C_4E3F_825D_235866024221__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCCriticalApp:
// See CCritical线程同步.cpp for the implementation of this class
//

class CCCriticalApp : public CWinApp
{
public:
	CCCriticalApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCCriticalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCCriticalApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CCRITICAL_H__ED84A901_940C_4E3F_825D_235866024221__INCLUDED_)
