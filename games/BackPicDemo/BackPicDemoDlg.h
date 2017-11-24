// BackPicDemoDlg.h : header file
//

#if !defined(AFX_BACKPICDEMODLG_H__671E7416_9AF6_47F1_BFE0_8A6B4E224454__INCLUDED_)
#define AFX_BACKPICDEMODLG_H__671E7416_9AF6_47F1_BFE0_8A6B4E224454__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBackPicDemoDlg dialog

class CBackPicDemoDlg : public CDialog
{
// Construction
public:
	CBackPicDemoDlg(CWnd* pParent = NULL);	// standard constructor
	CBrush m_brBk;
// Dialog Data
	//{{AFX_DATA(CBackPicDemoDlg)
	enum { IDD = IDD_BACKPICDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackPicDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBackPicDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKPICDEMODLG_H__671E7416_9AF6_47F1_BFE0_8A6B4E224454__INCLUDED_)
