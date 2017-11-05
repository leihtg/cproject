// timeTestDlg.h : header file
//

#if !defined(AFX_TIMETESTDLG_H__CB308A78_A2FB_4055_BEA9_FD9F2B2B5D64__INCLUDED_)
#define AFX_TIMETESTDLG_H__CB308A78_A2FB_4055_BEA9_FD9F2B2B5D64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimeTestDlg dialog
#include "time.h"
class CTimeTestDlg : public CDialog
{
// Construction
public:
	CTimeTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeTestDlg)
	enum { IDD = IDD_TIMETEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimeTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnNewMinuteTimectrl1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMETESTDLG_H__CB308A78_A2FB_4055_BEA9_FD9F2B2B5D64__INCLUDED_)
