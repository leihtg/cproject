// tcpIpClient.h : main header file for the TCPIPCLIENT application
//

#if !defined(AFX_TCPIPCLIENT_H__BC628CD2_DD35_4B55_A01D_B0FF149A343A__INCLUDED_)
#define AFX_TCPIPCLIENT_H__BC628CD2_DD35_4B55_A01D_B0FF149A343A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTcpIpClientApp:
// See tcpIpClient.cpp for the implementation of this class
//

class CTcpIpClientApp : public CWinApp
{
public:
	CTcpIpClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcpIpClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTcpIpClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPIPCLIENT_H__BC628CD2_DD35_4B55_A01D_B0FF149A343A__INCLUDED_)
