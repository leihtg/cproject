// comboxDlg.h : header file
//

#if !defined(AFX_COMBOXDLG_H__0F48CFF9_7772_42D8_B2EE_07775C535E7C__INCLUDED_)
#define AFX_COMBOXDLG_H__0F48CFF9_7772_42D8_B2EE_07775C535E7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CComboxDlg dialog

class CComboxDlg : public CDialog
{
// Construction
public:
	CComboxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CComboxDlg)
	enum { IDD = IDD_COMBOX_DIALOG };
	CComboBox	m_combo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CComboxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOXDLG_H__0F48CFF9_7772_42D8_B2EE_07775C535E7C__INCLUDED_)
