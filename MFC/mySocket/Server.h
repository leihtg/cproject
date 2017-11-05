#if !defined(AFX_SERVER_H__F83D1048_7B55_4379_9B3A_F0C73E370E40__INCLUDED_)
#define AFX_SERVER_H__F83D1048_7B55_4379_9B3A_F0C73E370E40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Server.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CServer dialog

class CServer : public CDialog
{
// Construction
public:
	CServer(CWnd* pParent = NULL);   // standard constructor
	CSocket	 m_socketListen;
	CAsyncSocket	 m_socket;
// Dialog Data
	//{{AFX_DATA(CServer)
	enum { IDD = idd_server };
	CListBox	m_list;
	UINT	m_port;
	CString	m_text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CServer)
	afx_msg void OnListen();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVER_H__F83D1048_7B55_4379_9B3A_F0C73E370E40__INCLUDED_)
