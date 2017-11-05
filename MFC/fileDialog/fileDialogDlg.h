// fileDialogDlg.h : header file
//

#if !defined(AFX_FILEDIALOGDLG_H__222314A2_0B8D_46D4_8229_D2C0EE1C2286__INCLUDED_)
#define AFX_FILEDIALOGDLG_H__222314A2_0B8D_46D4_8229_D2C0EE1C2286__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileDialogDlg dialog

class CFileDialogDlg : public CDialog
{
// Construction
public:
	CFileDialogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileDialogDlg)
	enum { IDD = IDD_FILEDIALOG_DIALOG };
	CStatic	m_savePath;
	CEdit	m_fileText;
	CStatic	m_openPath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEDIALOGDLG_H__222314A2_0B8D_46D4_8229_D2C0EE1C2286__INCLUDED_)
