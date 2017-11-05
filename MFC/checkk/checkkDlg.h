// checkkDlg.h : header file
//

#if !defined(AFX_CHECKKDLG_H__396F6DB4_7CC3_43C0_B8B5_51D63B8BBE08__INCLUDED_)
#define AFX_CHECKKDLG_H__396F6DB4_7CC3_43C0_B8B5_51D63B8BBE08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCheckkDlg dialog

class CCheckkDlg : public CDialog
{
// Construction
public:
	CCheckkDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCheckkDlg)
	enum { IDD = IDD_CHECKK_DIALOG };
	CButton	m_math;
	CButton	m_chinese;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCheckkDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKKDLG_H__396F6DB4_7CC3_43C0_B8B5_51D63B8BBE08__INCLUDED_)
