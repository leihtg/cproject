// FmodelDialogDlg.h : header file
//

#if !defined(AFX_FMODELDIALOGDLG_H__2F027D3E_6398_4B18_929F_9D26AB7928BB__INCLUDED_)
#define AFX_FMODELDIALOGDLG_H__2F027D3E_6398_4B18_929F_9D26AB7928BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFmodelDialogDlg dialog

class CFmodelDialogDlg : public CDialog
{
// Construction
public:
	CFmodelDialogDlg(CWnd* pParent = NULL);	// standard constructor
	int r,g,b;
// Dialog Data
	//{{AFX_DATA(CFmodelDialogDlg)
	enum { IDD = IDD_FMODELDIALOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFmodelDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFmodelDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FMODELDIALOGDLG_H__2F027D3E_6398_4B18_929F_9D26AB7928BB__INCLUDED_)
