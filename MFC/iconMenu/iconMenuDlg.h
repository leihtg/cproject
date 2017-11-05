// iconMenuDlg.h : header file
//

#if !defined(AFX_ICONMENUDLG_H__E6F8F2C2_17AE_4EE1_A83F_8DB57F922102__INCLUDED_)
#define AFX_ICONMENUDLG_H__E6F8F2C2_17AE_4EE1_A83F_8DB57F922102__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIconMenuDlg dialog

class CIconMenuDlg : public CDialog
{
// Construction
public:
	CIconMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIconMenuDlg)
	enum { IDD = IDD_ICONMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIconMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONMENUDLG_H__E6F8F2C2_17AE_4EE1_A83F_8DB57F922102__INCLUDED_)
