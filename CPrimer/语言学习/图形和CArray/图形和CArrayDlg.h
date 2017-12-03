// Í¼ÐÎºÍCArrayDlg.h : header file
//

#if !defined(AFX_CARRAYDLG_H__C3A2F5D1_DB6E_40BF_8708_C5B756954A16__INCLUDED_)
#define AFX_CARRAYDLG_H__C3A2F5D1_DB6E_40BF_8708_C5B756954A16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCArrayDlg dialog

class CCArrayDlg : public CDialog
{
// Construction
public:
	CCArrayDlg(CWnd* pParent = NULL);	// standard constructor

	CString readFile(CString ps);

	void drawPic(CString str);
// Dialog Data
	//{{AFX_DATA(CCArrayDlg)
	enum { IDD = IDD_CARRAY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArrayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCArrayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelectFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAYDLG_H__C3A2F5D1_DB6E_40BF_8708_C5B756954A16__INCLUDED_)
