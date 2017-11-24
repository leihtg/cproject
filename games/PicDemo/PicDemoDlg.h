// PicDemoDlg.h : header file
//

#if !defined(AFX_PICDEMODLG_H__4BA3408A_C930_4097_82E4_952B172B48A4__INCLUDED_)
#define AFX_PICDEMODLG_H__4BA3408A_C930_4097_82E4_952B172B48A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPicDemoDlg dialog

class CPicDemoDlg : public CDialog
{
// Construction
public:
	CPicDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPicDemoDlg)
	enum { IDD = IDD_PICDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPicDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICDEMODLG_H__4BA3408A_C930_4097_82E4_952B172B48A4__INCLUDED_)
