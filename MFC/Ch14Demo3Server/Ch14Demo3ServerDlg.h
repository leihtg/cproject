// Ch14Demo3ServerDlg.h : header file
//

#if !defined(AFX_CH14DEMO3SERVERDLG_H__2E1F8D51_8C7C_44B4_AA95_323095F1C578__INCLUDED_)
#define AFX_CH14DEMO3SERVERDLG_H__2E1F8D51_8C7C_44B4_AA95_323095F1C578__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "listensocket.h"
/////////////////////////////////////////////////////////////////////////////
// CCh14Demo3ServerDlg dialog

class CCh14Demo3ServerDlg : public CDialog
{
// Construction
public:
	CCh14Demo3ServerDlg(CWnd* pParent = NULL);	// standard constructor
	CListenSocket m_srvrSocket;
// Dialog Data
	//{{AFX_DATA(CCh14Demo3ServerDlg)
	enum { IDD = IDD_CH14DEMO3SERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCh14Demo3ServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCh14Demo3ServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CH14DEMO3SERVERDLG_H__2E1F8D51_8C7C_44B4_AA95_323095F1C578__INCLUDED_)
