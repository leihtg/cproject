// CCritical线程同步Dlg.h : header file
//

#if !defined(AFX_CCRITICALDLG_H__FF91D806_D1E0_4E0D_B4E4_9D78F2A267B0__INCLUDED_)
#define AFX_CCRITICALDLG_H__FF91D806_D1E0_4E0D_B4E4_9D78F2A267B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCCriticalDlg dialog

class CCCriticalDlg : public CDialog
{
// Construction
public:
	CCCriticalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCCriticalDlg)
	enum { IDD = IDD_CCRITICAL_DIALOG };
	CEdit	m_ReadEdit;
	CEdit	m_WriteEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCCriticalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCCriticalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStarw();
	afx_msg void OnStopW();
	afx_msg void OnStarr();
	afx_msg void OnStopr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CCRITICALDLG_H__FF91D806_D1E0_4E0D_B4E4_9D78F2A267B0__INCLUDED_)
