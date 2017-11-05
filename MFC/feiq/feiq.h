// feiq.h : main header file for the FEIQ DLL
//

#if !defined(AFX_PLUGIN1_H__17FC3E0F_D9BE_4F30_B43B_88DBBBDBE299__INCLUDED_)
#define AFX_PLUGIN1_H__17FC3E0F_D9BE_4F30_B43B_88DBBBDBE299__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFeiqApp
// See feiq.cpp for the implementation of this class
//

class CFeiqApp : public CWinApp
{
public:
	CFeiqApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFeiqApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFeiqApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLUGIN1_H__17FC3E0F_D9BE_4F30_B43B_88DBBBDBE299__INCLUDED_)
