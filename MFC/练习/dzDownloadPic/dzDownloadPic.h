#if !defined(AFX_DZDOWNLOADPIC_H__94D93F84_2346_4022_AA7A_017E619A0408__INCLUDED_)
#define AFX_DZDOWNLOADPIC_H__94D93F84_2346_4022_AA7A_017E619A0408__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// dzDownloadPic.h : main header file for DZDOWNLOADPIC.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicApp : See dzDownloadPic.cpp for implementation.

class CDzDownloadPicApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DZDOWNLOADPIC_H__94D93F84_2346_4022_AA7A_017E619A0408__INCLUDED)
