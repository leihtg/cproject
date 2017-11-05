// 数据库1.h : main header file for the 数据库1 application
//

#if !defined(AFX_1_H__EA0ADF99_ED9C_454D_B0C3_33E034C4F9B0__INCLUDED_)
#define AFX_1_H__EA0ADF99_ED9C_454D_B0C3_33E034C4F9B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1App:
// See 数据库1.cpp for the implementation of this class
//

class CMy1App : public CWinApp
{
public:
	CMy1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1_H__EA0ADF99_ED9C_454D_B0C3_33E034C4F9B0__INCLUDED_)
