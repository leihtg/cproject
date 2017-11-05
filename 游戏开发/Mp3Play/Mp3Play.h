// Mp3Play.h : main header file for the MP3PLAY application
//

#if !defined(AFX_MP3PLAY_H__0956A98F_A79F_4AC2_9E81_D4A918514F60__INCLUDED_)
#define AFX_MP3PLAY_H__0956A98F_A79F_4AC2_9E81_D4A918514F60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMp3PlayApp:
// See Mp3Play.cpp for the implementation of this class
//

class CMp3PlayApp : public CWinApp
{
public:
	CMp3PlayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMp3PlayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMp3PlayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3PLAY_H__0956A98F_A79F_4AC2_9E81_D4A918514F60__INCLUDED_)
