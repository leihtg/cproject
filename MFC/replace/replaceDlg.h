// replaceDlg.h : header file
//

#if !defined(AFX_REPLACEDLG_H__FFC0D8C8_E916_4BBD_A32F_8E9AC9C0DCCE__INCLUDED_)
#define AFX_REPLACEDLG_H__FFC0D8C8_E916_4BBD_A32F_8E9AC9C0DCCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReplaceDlg dialog

class CReplaceDlg : public CDialog
{
// Construction
public:
	CFindReplaceDialog* dlg;
	CReplaceDlg(CWnd* pParent = NULL);	// standard constructor
int nindex;
int rindex;
BOOL degree;
BOOL find;
// Dialog Data
	//{{AFX_DATA(CReplaceDlg)
	enum { IDD = IDD_REPLACE_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReplaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReplaceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onreplace();
	afx_msg long OnFindReplace(WPARAM wParam,LPARAM lParam);
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPLACEDLG_H__FFC0D8C8_E916_4BBD_A32F_8E9AC9C0DCCE__INCLUDED_)
