// Ch14Demo3ClientDlg.h : header file
//

#if !defined(AFX_CH14DEMO3CLIENTDLG_H__484DD95A_6CF1_4FDC_B0F8_8E708601742D__INCLUDED_)
#define AFX_CH14DEMO3CLIENTDLG_H__484DD95A_6CF1_4FDC_B0F8_8E708601742D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ClientSocket.h"
#include "AddrDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CCh14Demo3ClientDlg dialog

class CCh14Demo3ClientDlg : public CDialog
{
// Construction
public:
	CCh14Demo3ClientDlg(CWnd* pParent = NULL);	// standard constructor
	
	char m_szServerAdr[256];

// Dialog Data
	//{{AFX_DATA(CCh14Demo3ClientDlg)
	enum { IDD = IDD_CH14DEMO3CLIENT_DIALOG };
	CEdit	m_MsgS;
	CListBox	m_MsgR;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCh14Demo3ClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int TryCount;
	CClientSocket m_clientSocket;
	UINT m_szPort;
	// Generated message map functions
	//{{AFX_MSG(CCh14Demo3ClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSend();
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CH14DEMO3CLIENTDLG_H__484DD95A_6CF1_4FDC_B0F8_8E708601742D__INCLUDED_)
