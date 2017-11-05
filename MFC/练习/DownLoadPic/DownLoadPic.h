// DownLoadPic.h : main header file for the DOWNLOADPIC application
//

#if !defined(AFX_DOWNLOADPIC_H__ABA82722_E035_4408_9C19_066FE37AD7C8__INCLUDED_)
#define AFX_DOWNLOADPIC_H__ABA82722_E035_4408_9C19_066FE37AD7C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDownLoadPicApp:
// See DownLoadPic.cpp for the implementation of this class
//

class CDownLoadPicApp : public CWinApp
{
public:
	CDownLoadPicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownLoadPicApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDownLoadPicApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNLOADPIC_H__ABA82722_E035_4408_9C19_066FE37AD7C8__INCLUDED_)
