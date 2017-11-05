// DynamicPicDemoDlg.h : header file
//

#if !defined(AFX_DYNAMICPICDEMODLG_H__7A97017D_BEE7_43FB_8A91_993AB099A7D9__INCLUDED_)
#define AFX_DYNAMICPICDEMODLG_H__7A97017D_BEE7_43FB_8A91_993AB099A7D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDynamicPicDemoDlg dialog

class CDynamicPicDemoDlg : public CDialog
{
// Construction
public:
	CDynamicPicDemoDlg(CWnd* pParent = NULL);	// standard constructor
	CBitmap m_bmp;
// Dialog Data
	//{{AFX_DATA(CDynamicPicDemoDlg)
	enum { IDD = IDD_DYNAMICPICDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicPicDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDynamicPicDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICPICDEMODLG_H__7A97017D_BEE7_43FB_8A91_993AB099A7D9__INCLUDED_)
