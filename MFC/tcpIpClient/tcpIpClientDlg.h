// tcpIpClientDlg.h : header file
//

#if !defined(AFX_TCPIPCLIENTDLG_H__BED0D544_B740_40CB_B93F_E85D22E5E404__INCLUDED_)
#define AFX_TCPIPCLIENTDLG_H__BED0D544_B740_40CB_B93F_E85D22E5E404__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTcpIpClientDlg dialog

class CTcpIpClientDlg : public CDialog
{
// Construction
public:
	CTcpIpClientDlg(CWnd* pParent = NULL);	// standard constructor
	CSocket m_sockReveive;
// Dialog Data
	//{{AFX_DATA(CTcpIpClientDlg)
	enum { IDD = IDD_TCPIPCLIENT_DIALOG };
	CString	m_ServerIP;
	int		m_ServerPort;
	CString	m_data;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcpIpClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTcpIpClientDlg)
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

#endif // !defined(AFX_TCPIPCLIENTDLG_H__BED0D544_B740_40CB_B93F_E85D22E5E404__INCLUDED_)
