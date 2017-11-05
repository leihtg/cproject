// socketDlg.h : header file
//

#if !defined(AFX_SOCKETDLG_H__07590E2B_B600_4836_83B8_82B738CE35BD__INCLUDED_)
#define AFX_SOCKETDLG_H__07590E2B_B600_4836_83B8_82B738CE35BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxsock.h>
/////////////////////////////////////////////////////////////////////////////
// CSocketDlg dialog

class CSocketDlg : public CDialog
{
// Construction
public:
	CSocketDlg(CWnd* pParent = NULL);	// standard constructor
	CAsyncSocket socket;
// Dialog Data
	//{{AFX_DATA(CSocketDlg)
	enum { IDD = IDD_SOCKET_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSocketDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSocketDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKETDLG_H__07590E2B_B600_4836_83B8_82B738CE35BD__INCLUDED_)
