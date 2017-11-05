// labelDlg.h : header file
//

#if !defined(AFX_LABELDLG_H__EE5A064A_48F0_4A65_B7FE_9FB2C55107C9__INCLUDED_)
#define AFX_LABELDLG_H__EE5A064A_48F0_4A65_B7FE_9FB2C55107C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLabelDlg dialog

class CLabelDlg : public CDialog
{
// Construction
public:
	CLabelDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLabelDlg)
	enum { IDD = IDD_LABEL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLabelDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSTATICd();
	afx_msg void OnSTATICaaa();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABELDLG_H__EE5A064A_48F0_4A65_B7FE_9FB2C55107C9__INCLUDED_)
