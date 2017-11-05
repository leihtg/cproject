// DownLoadPicDlg.h : header file
//

#if !defined(AFX_DOWNLOADPICDLG_H__8B6082B9_FE53_4D34_A1AD_D32A65E49258__INCLUDED_)
#define AFX_DOWNLOADPICDLG_H__8B6082B9_FE53_4D34_A1AD_D32A65E49258__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxinet.h>
/////////////////////////////////////////////////////////////////////////////
// CDownLoadPicDlg dialog

class CDownLoadPicDlg : public CDialog
{
// Construction
public:
	CDownLoadPicDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDownLoadPicDlg)
	enum { IDD = IDD_DOWNLOADPIC_DIALOG };
	CString	m_url;
	CString	m_test;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownLoadPicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDownLoadPicDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNLOADPICDLG_H__8B6082B9_FE53_4D34_A1AD_D32A65E49258__INCLUDED_)
