// OcxDlg.h : header file
//
//{{AFX_INCLUDES()
#include "intelligentocx.h"
//}}AFX_INCLUDES

#if !defined(AFX_OCXDLG_H__BD90799C_971D_4EAB_87AB_BD9890D78806__INCLUDED_)
#define AFX_OCXDLG_H__BD90799C_971D_4EAB_87AB_BD9890D78806__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COcxDlg dialog

class COcxDlg : public CDialog
{
// Construction
public:
	COcxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COcxDlg)
	enum { IDD = IDD_OCX_DIALOG };
	CIntelligentOcx	m_ctrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COcxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXDLG_H__BD90799C_971D_4EAB_87AB_BD9890D78806__INCLUDED_)
