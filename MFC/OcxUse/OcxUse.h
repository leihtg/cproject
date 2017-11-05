// OcxUse.h : main header file for the OCXUSE application
//

#if !defined(AFX_OCXUSE_H__DEE5C7D3_741D_4422_AC45_220EF85C6C38__INCLUDED_)
#define AFX_OCXUSE_H__DEE5C7D3_741D_4422_AC45_220EF85C6C38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COcxUseApp:
// See OcxUse.cpp for the implementation of this class
//

class COcxUseApp : public CWinApp
{
public:
	COcxUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COcxUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXUSE_H__DEE5C7D3_741D_4422_AC45_220EF85C6C38__INCLUDED_)
