// TCPClientDlg.h : header file
//

#if !defined(AFX_TCPCLIENTDLG_H__884B2B6A_0812_4C08_9E68_170B75B23874__INCLUDED_)
#define AFX_TCPCLIENTDLG_H__884B2B6A_0812_4C08_9E68_170B75B23874__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MySocket.h"
/////////////////////////////////////////////////////////////////////////////
// CTCPClientDlg dialog

class CTCPClientDlg : public CDialog
{
// Construction
public:
	CTCPClientDlg(CWnd* pParent = NULL);	// standard constructor
	CMySocket m_socket;
	void OnReceive();
	void OnCls();
// Dialog Data
	//{{AFX_DATA(CTCPClientDlg)
	enum { IDD = IDD_TCPCLIENT_DIALOG };
	CString	m_szRecv;
	CString	m_szSend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnConn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPCLIENTDLG_H__884B2B6A_0812_4C08_9E68_170B75B23874__INCLUDED_)
