// PlaySoundDemoDlg.h : header file
//

#if !defined(AFX_PLAYSOUNDDEMODLG_H__041F7E8C_5BA0_46E1_9CAE_07FCAF1F1554__INCLUDED_)
#define AFX_PLAYSOUNDDEMODLG_H__041F7E8C_5BA0_46E1_9CAE_07FCAF1F1554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPlaySoundDemoDlg dialog

class CPlaySoundDemoDlg : public CDialog
{
// Construction
public:
	CPlaySoundDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPlaySoundDemoDlg)
	enum { IDD = IDD_PLAYSOUNDDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaySoundDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlaySoundDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlaySound();
	afx_msg void OnPlayMusic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYSOUNDDEMODLG_H__041F7E8C_5BA0_46E1_9CAE_07FCAF1F1554__INCLUDED_)
