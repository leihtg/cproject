// mySocketDlg.h : header file
//

#if !defined(AFX_MYSOCKETDLG_H__432DBEB8_F828_4D1D_84A1_165864E88CB7__INCLUDED_)
#define AFX_MYSOCKETDLG_H__432DBEB8_F828_4D1D_84A1_165864E88CB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "client.h"
#include "server.h"
/////////////////////////////////////////////////////////////////////////////
// CMySocketDlg dialog

class CMySocketDlg : public CDialog
{
// Construction
public:
	CMySocketDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMySocketDlg)
	enum { IDD = IDD_MYSOCKET_DIALOG };
	CTabCtrl	m_tab;
	CClient client;
	CServer server;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySocketDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMySocketDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCKETDLG_H__432DBEB8_F828_4D1D_84A1_165864E88CB7__INCLUDED_)
