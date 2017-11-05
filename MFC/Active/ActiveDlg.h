// ActiveDlg.h : header file
//

#if !defined(AFX_ACTIVEDLG_H__EDCB0A2C_958C_42D7_9AF4_CBB95816A250__INCLUDED_)
#define AFX_ACTIVEDLG_H__EDCB0A2C_958C_42D7_9AF4_CBB95816A250__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CActiveDlg dialog

class CActiveDlg : public CDialog
{
// Construction
public:
	CActiveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CActiveDlg)
	enum { IDD = IDD_ACTIVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CActiveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACTIVEDLG_H__EDCB0A2C_958C_42D7_9AF4_CBB95816A250__INCLUDED_)
