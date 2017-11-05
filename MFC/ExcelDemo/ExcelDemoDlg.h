// ExcelDemoDlg.h : header file
//

#if !defined(AFX_EXCELDEMODLG_H__B6E33626_761D_4171_97E9_4E4AA3809D4A__INCLUDED_)
#define AFX_EXCELDEMODLG_H__B6E33626_761D_4171_97E9_4E4AA3809D4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExcelDemoDlg dialog

class CExcelDemoDlg : public CDialog
{
// Construction
public:
	CExcelDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExcelDemoDlg)
	enum { IDD = IDD_EXCELDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExcelDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExcelDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXCELDEMODLG_H__B6E33626_761D_4171_97E9_4E4AA3809D4A__INCLUDED_)
