// netUrlDlg.h : header file
//

#if !defined(AFX_NETURLDLG_H__269E1686_9CB1_4351_834C_6CE0EAB08A91__INCLUDED_)
#define AFX_NETURLDLG_H__269E1686_9CB1_4351_834C_6CE0EAB08A91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetUrlDlg dialog

class CNetUrlDlg : public CDialog
{
// Construction
public:
	CNetUrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNetUrlDlg)
	enum { IDD = IDD_NETURL_DIALOG };
	CString	m_Url;
	CString	m_Text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetUrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetUrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEdit1();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETURLDLG_H__269E1686_9CB1_4351_834C_6CE0EAB08A91__INCLUDED_)
