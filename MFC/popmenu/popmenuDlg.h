// popmenuDlg.h : header file
//

#if !defined(AFX_POPMENUDLG_H__B80182ED_722A_4D2B_B0E1_562058B79E24__INCLUDED_)
#define AFX_POPMENUDLG_H__B80182ED_722A_4D2B_B0E1_562058B79E24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPopmenuDlg dialog

class CPopmenuDlg : public CDialog
{
// Construction
public:
	CMenu m_menu;
	CPopmenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPopmenuDlg)
	enum { IDD = IDD_POPMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopmenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPopmenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPMENUDLG_H__B80182ED_722A_4D2B_B0E1_562058B79E24__INCLUDED_)
