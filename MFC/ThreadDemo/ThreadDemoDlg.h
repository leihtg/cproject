// ThreadDemoDlg.h : header file
//

#if !defined(AFX_THREADDEMODLG_H__CF119F64_4AC0_420F_9475_940F0D4F0178__INCLUDED_)
#define AFX_THREADDEMODLG_H__CF119F64_4AC0_420F_9475_940F0D4F0178__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadDemoDlg dialog

typedef struct Threadinfo{
	CProgressCtrl *progress;
	int speed;
	int pos;
}thread,*lpthread;



class CThreadDemoDlg : public CDialog
{
// Construction
public:
	CThreadDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadDemoDlg)
	enum { IDD = IDD_THREADDEMO_DIALOG };
	CProgressCtrl	m_progress3;
	CProgressCtrl	m_progress2;
	CProgressCtrl	m_progress1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	thread thread1;
	thread thread2;
	thread thread3;
	HANDLE hThread1;
	HANDLE hThread2;
	HANDLE hThread3;
	// Generated message map functions
	//{{AFX_MSG(CThreadDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart1();
	afx_msg void Ons2();
	afx_msg void Ons3();
	afx_msg void Onp1();
	afx_msg void Onp2();
	afx_msg void Onp3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADDEMODLG_H__CF119F64_4AC0_420F_9475_940F0D4F0178__INCLUDED_)
