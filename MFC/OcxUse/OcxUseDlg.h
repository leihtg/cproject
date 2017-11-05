// OcxUseDlg.h : header file
//
//{{AFX_INCLUDES()
#include "ocxdemo.h"
//}}AFX_INCLUDES

#if !defined(AFX_OCXUSEDLG_H__FB5CCBE3_EAC9_49C8_9F90_24F000A8F9A9__INCLUDED_)
#define AFX_OCXUSEDLG_H__FB5CCBE3_EAC9_49C8_9F90_24F000A8F9A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COcxUseDlg dialog

class COcxUseDlg : public CDialog
{
// Construction
public:
	COcxUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COcxUseDlg)
	enum { IDD = IDD_OCXUSE_DIALOG };
	COcxDemo	m_OcxDemo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COcxUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXUSEDLG_H__FB5CCBE3_EAC9_49C8_9F90_24F000A8F9A9__INCLUDED_)
