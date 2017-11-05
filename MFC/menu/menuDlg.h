// menuDlg.h : header file
//

#if !defined(AFX_MENUDLG_H__6129289B_E486_4788_AC2A_F843124BADA7__INCLUDED_)
#define AFX_MENUDLG_H__6129289B_E486_4788_AC2A_F843124BADA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMenuDlg dialog

class CMenuDlg : public CDialog
{
// Construction
public:
	CMenu m_menu;
	CMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMenuDlg)
	enum { IDD = IDD_MENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnA11();
	afx_msg void OnA2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUDLG_H__6129289B_E486_4788_AC2A_F843124BADA7__INCLUDED_)
