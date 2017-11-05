// FiveChessDlg.h : header file
//

#if !defined(AFX_FIVECHESSDLG_H__E8D804C5_6679_46EE_946A_FE0D1469E04C__INCLUDED_)
#define AFX_FIVECHESSDLG_H__E8D804C5_6679_46EE_946A_FE0D1469E04C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFiveChessDlg dialog

class CFiveChessDlg : public CDialog
{
// Construction
public:
	CFiveChessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFiveChessDlg)
	enum { IDD = IDD_FIVECHESS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveChessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFiveChessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUpdateNewGameMenu(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawGameMenu(CCmdUI* pCmdUI);
	afx_msg void OnUpdateExitGameMenu(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVECHESSDLG_H__E8D804C5_6679_46EE_946A_FE0D1469E04C__INCLUDED_)
