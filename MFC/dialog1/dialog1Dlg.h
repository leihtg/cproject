// dialog1Dlg.h : header file
//

#if !defined(AFX_DIALOG1DLG_H__1F4D4D40_8F16_4D90_B8D7_69C599CE52EE__INCLUDED_)
#define AFX_DIALOG1DLG_H__1F4D4D40_8F16_4D90_B8D7_69C599CE52EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialog1Dlg dialog

class CDialog1Dlg : public CDialog
{
// Construction
public:
	CDialog1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog1Dlg)
	enum { IDD = IDD_DIALOG1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialog1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreate();
	afx_msg void OnFModal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1DLG_H__1F4D4D40_8F16_4D90_B8D7_69C599CE52EE__INCLUDED_)
