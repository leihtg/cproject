// 线程通信Dlg.h : header file
//

#if !defined(AFX_DLG_H__3A0D185D_C0F2_4C33_B9B5_313D0CE6FDB7__INCLUDED_)
#define AFX_DLG_H__3A0D185D_C0F2_4C33_B9B5_313D0CE6FDB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
struct NumInfo{
	CEdit* pedit;
	HWND hwnd;
};
class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CEdit	m_Num;
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	NumInfo numinfo;
	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	afx_msg void OnMsg();
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStar();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__3A0D185D_C0F2_4C33_B9B5_313D0CE6FDB7__INCLUDED_)
