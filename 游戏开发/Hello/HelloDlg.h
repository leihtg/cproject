// HelloDlg.h : header file
//

#if !defined(AFX_HELLODLG_H__133F73C4_1543_4806_A257_DAD8C6E72F14__INCLUDED_)
#define AFX_HELLODLG_H__133F73C4_1543_4806_A257_DAD8C6E72F14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHelloDlg dialog

class CHelloDlg : public CDialog
{
// Construction
public:
	CHelloDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHelloDlg)
	enum { IDD = IDD_HELLO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHelloDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLODLG_H__133F73C4_1543_4806_A257_DAD8C6E72F14__INCLUDED_)
