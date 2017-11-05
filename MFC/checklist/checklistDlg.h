// checklistDlg.h : header file
//

#if !defined(AFX_CHECKLISTDLG_H__AE16D19D_8CAF_4A1C_828B_8D5A90F408B1__INCLUDED_)
#define AFX_CHECKLISTDLG_H__AE16D19D_8CAF_4A1C_828B_8D5A90F408B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChecklistDlg dialog

class CChecklistDlg : public CDialog
{
// Construction
public:
	CChecklistDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChecklistDlg)
	enum { IDD = IDD_CHECKLIST_DIALOG };
	CCheckListBox	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChecklistDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChecklistDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKLISTDLG_H__AE16D19D_8CAF_4A1C_828B_8D5A90F408B1__INCLUDED_)
