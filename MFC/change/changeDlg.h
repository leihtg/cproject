// changeDlg.h : header file
//

#if !defined(AFX_CHANGEDLG_H__BE3E4B5C_D800_4F8E_8443_B1414D94C8F0__INCLUDED_)
#define AFX_CHANGEDLG_H__BE3E4B5C_D800_4F8E_8443_B1414D94C8F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeDlg dialog

class CChangeDlg : public CDialog
{
// Construction
public:
	CFindReplaceDialog* dlg;
	CChangeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeDlg)
	enum { IDD = IDD_CHANGE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onreplace();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEDLG_H__BE3E4B5C_D800_4F8E_8443_B1414D94C8F0__INCLUDED_)
