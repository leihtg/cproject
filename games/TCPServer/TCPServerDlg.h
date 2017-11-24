// TCPServerDlg.h : header file
//

#if !defined(AFX_TCPSERVERDLG_H__E2BB4F32_085B_45A9_B5DB_BC07136CF280__INCLUDED_)
#define AFX_TCPSERVERDLG_H__E2BB4F32_085B_45A9_B5DB_BC07136CF280__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "mysocket.h"

/////////////////////////////////////////////////////////////////////////////
// CTCPServerDlg dialog

class CTCPServerDlg : public CDialog
{
// Construction
private:
		CMySocket m_sockListen;
		CMySocket m_sockServer;
public:
	CTCPServerDlg(CWnd* pParent = NULL);	// standard constructor
	void OnReceive();
	void OnAccept();
	void OnClose();

// Dialog Data
	//{{AFX_DATA(CTCPServerDlg)
	enum { IDD = IDD_TCPSERVER_DIALOG };
	CString	m_szRecv;
	CString	m_szSend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnAcceptBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPSERVERDLG_H__E2BB4F32_085B_45A9_B5DB_BC07136CF280__INCLUDED_)
