// FontDlg.h : header file
//

#if !defined(AFX_FONTDLG_H__0C5C5241_1F5A_4B28_B466_EA43543976B2__INCLUDED_)
#define AFX_FONTDLG_H__0C5C5241_1F5A_4B28_B466_EA43543976B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFontDlg dialog

class CFontDlg : public CDialog
{
// Construction
public:
	CFont m_font;
	CFontDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFontDlg)
	enum { IDD = IDD_FONT_DIALOG };
	CEdit	m_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onfont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTDLG_H__0C5C5241_1F5A_4B28_B466_EA43543976B2__INCLUDED_)
