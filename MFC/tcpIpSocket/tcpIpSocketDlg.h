// tcpIpSocketDlg.h : header file
//

#if !defined(AFX_TCPIPSOCKETDLG_H__32161732_68D2_4B0A_94CB_2BA3F6EE685C__INCLUDED_)
#define AFX_TCPIPSOCKETDLG_H__32161732_68D2_4B0A_94CB_2BA3F6EE685C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTcpIpSocketDlg dialog

class CTcpIpSocketDlg : public CDialog
{
// Construction
public:
	CTcpIpSocketDlg(CWnd* pParent = NULL);	// standard constructor
	CSocket m_sockListen;
	CAsyncSocket m_socksend;
// Dialog Data
	//{{AFX_DATA(CTcpIpSocketDlg)
	enum { IDD = IDD_TCPIPSOCKET_DIALOG };
	CString	m_ServerIP;
	int		m_ServerPort;
	CString	m_status;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcpIpSocketDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTcpIpSocketDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPIPSOCKETDLG_H__32161732_68D2_4B0A_94CB_2BA3F6EE685C__INCLUDED_)
