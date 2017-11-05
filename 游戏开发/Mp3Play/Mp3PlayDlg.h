// Mp3PlayDlg.h : header file
//

#if !defined(AFX_MP3PLAYDLG_H__B96BEEDE_1227_44C4_9303_0100937BE6AA__INCLUDED_)
#define AFX_MP3PLAYDLG_H__B96BEEDE_1227_44C4_9303_0100937BE6AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyPlayerControl.h"
/////////////////////////////////////////////////////////////////////////////
// CMp3PlayDlg dialog

class CMp3PlayDlg : public CDialog
{
// Construction
public:
	CMp3PlayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMp3PlayDlg)
	enum { IDD = IDD_MP3PLAY_DIALOG };
	CSliderCtrl	m_process;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMp3PlayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	private:
		CMyPlayerControl m_myPlayerControl;
		CString m_strFileName;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMp3PlayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenBtn();
	afx_msg void OnPauseBtn();
	afx_msg void OnPlayBtn();
	afx_msg void OnStopBtn();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3PLAYDLG_H__B96BEEDE_1227_44C4_9303_0100937BE6AA__INCLUDED_)
