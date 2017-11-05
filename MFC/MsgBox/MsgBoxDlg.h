// MsgBoxDlg.h : header file
//

#if !defined(AFX_MSGBOXDLG_H__204E81B0_9C63_441D_AA90_61060643D197__INCLUDED_)
#define AFX_MSGBOXDLG_H__204E81B0_9C63_441D_AA90_61060643D197__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMsgBoxDlg dialog

class CMsgBoxDlg : public CDialog
{
// Construction
public:
	CMsgBoxDlg(CWnd* pParent = NULL);	// standard constructor
	COLORREF crColor;
	CFont fnt;
	int i;
// Dialog Data
	//{{AFX_DATA(CMsgBoxDlg)
	enum { IDD = IDD_MSGBOX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMsgBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnFile();
	afx_msg void OnFont();
	afx_msg void OnPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGBOXDLG_H__204E81B0_9C63_441D_AA90_61060643D197__INCLUDED_)
