// Â¼ÒôDlg.h : header file
//

#if !defined(AFX_DLG_H__13C204DB_5540_4D5A_8D3B_2C40044FC2D3__INCLUDED_)
#define AFX_DLG_H__13C204DB_5540_4D5A_8D3B_2C40044FC2D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	void RecordBegin();
	BOOL InitAudioDevice();
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
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
	afx_msg void OnLuyin();
	afx_msg void OnPlay();

	afx_msg void ON_MM_WIM_OPEN();
	afx_msg void ON_MM_WIM_DATA();
	afx_msg void ON_MM_WIM_CLOSE();
	afx_msg void ON_MM_WOM_OPEN();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__13C204DB_5540_4D5A_8D3B_2C40044FC2D3__INCLUDED_)
