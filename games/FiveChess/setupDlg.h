#if !defined(AFX_SETUPDLG_H__67D4DE91_C41B_46D1_8302_E83D0230BACA__INCLUDED_)
#define AFX_SETUPDLG_H__67D4DE91_C41B_46D1_8302_E83D0230BACA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// setupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CsetupDlg dialog

class CsetupDlg : public CDialog
{
// Construction
public:
	CsetupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CsetupDlg)
	enum { IDD = IDD_DIALOG1 };
	CIPAddressCtrl	m_ip_addr;
	UINT	m_net_port;
	//}}AFX_DATA
public:
	BOOL m_isHost;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CsetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CsetupDlg)
	afx_msg void OnHostOption();
	afx_msg void OnClientOption();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETUPDLG_H__67D4DE91_C41B_46D1_8302_E83D0230BACA__INCLUDED_)
