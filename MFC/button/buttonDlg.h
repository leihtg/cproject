// buttonDlg.h : header file
//

#if !defined(AFX_BUTTONDLG_H__9E4FDA8A_9788_46EB_9B0C_04E6EF536525__INCLUDED_)
#define AFX_BUTTONDLG_H__9E4FDA8A_9788_46EB_9B0C_04E6EF536525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CButtonDlg dialog

class CButtonDlg : public CDialog
{
// Construction
public:
	CButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CButtonDlg)
	enum { IDD = IDD_BUTTON_DIALOG };
	CButton	m_ok;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONDLG_H__9E4FDA8A_9788_46EB_9B0C_04E6EF536525__INCLUDED_)
