// tcpIpSocket.h : main header file for the TCPIPSOCKET application
//

#if !defined(AFX_TCPIPSOCKET_H__8A20396E_3ADA_43C8_9A76_1E6B026071BE__INCLUDED_)
#define AFX_TCPIPSOCKET_H__8A20396E_3ADA_43C8_9A76_1E6B026071BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTcpIpSocketApp:
// See tcpIpSocket.cpp for the implementation of this class
//

class CTcpIpSocketApp : public CWinApp
{
public:
	CTcpIpSocketApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcpIpSocketApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTcpIpSocketApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPIPSOCKET_H__8A20396E_3ADA_43C8_9A76_1E6B026071BE__INCLUDED_)
