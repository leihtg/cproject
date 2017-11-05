// 自定义发送窗口消息Dlg.h : header file
//

#if !defined(AFX_DLG_H__14F4F2B9_2039_4214_962B_786700E30E9E__INCLUDED_)
#define AFX_DLG_H__14F4F2B9_2039_4214_962B_786700E30E9E__INCLUDED_

#include "messagelistbox.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	LRESULT OnMessageSelChange(WPARAM wParam,LPARAM lParam);
	LRESULT OnMessageDblclk(WPARAM wParam,LPARAM lParam);
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CMessageListBox	m_listbox;
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__14F4F2B9_2039_4214_962B_786700E30E9E__INCLUDED_)
