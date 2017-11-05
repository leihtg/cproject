// SocketClientDlg.h : header file
//

#if !defined(AFX_SOCKETCLIENTDLG_H__56AC1751_5EF2_478D_8A8B_23518F77E29C__INCLUDED_)
#define AFX_SOCKETCLIENTDLG_H__56AC1751_5EF2_478D_8A8B_23518F77E29C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSocketClientDlg dialog

class CSocketClientDlg : public CDialog
{
// Construction
public:
	CSocketClientDlg(CWnd* pParent = NULL);	// standard constructor
	CAsyncSocket m_sockReceive;
// Dialog Data
	//{{AFX_DATA(CSocketClientDlg)
	enum { IDD = IDD_SOCKETCLIENT_DIALOG };
	CString	m_ClinetIp;
	int		m_ClientPort;
	CString	m_ServerIp;
 unsigned	int		m_ServerPort;
	CString	m_data;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSocketClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSocketClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReceive();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKETCLIENTDLG_H__56AC1751_5EF2_478D_8A8B_23518F77E29C__INCLUDED_)
