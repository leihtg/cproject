// ¶àÏß³ÌDlg.h : header file
//

#if !defined(AFX_DLG_H__3905851E_E45E_4476_BEFA_08D1ADB10D63__INCLUDED_)
#define AFX_DLG_H__3905851E_E45E_4476_BEFA_08D1ADB10D63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxinet.h>
#define M_P WM_USER+100
/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
typedef struct ThreadInfo{
	CString url;
	CString filePath;
	CInternetFile* webfile;
	CProgressCtrl*	progress;

	HWND hwnd;
} threadInfo,*pThread;
class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor
	CInternetSession session;
	threadInfo thread;
// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CProgressCtrl	m_progress;
	CString	m_url;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDownLoad();
	afx_msg void showProgress(WPARAM w,LPARAM lp);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__3905851E_E45E_4476_BEFA_08D1ADB10D63__INCLUDED_)
