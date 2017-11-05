#if !defined(AFX_SCOREDLG_H__90F03D59_63B0_42AD_B012_869C4579C1A6__INCLUDED_)
#define AFX_SCOREDLG_H__90F03D59_63B0_42AD_B012_869C4579C1A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg dialog

class CScoreDlg : public CDialog
{
// Construction
public:
	CScoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScoreDlg)
	enum { IDD = IDD_DIALOG1 };
	double	m_score1;
	double	m_scroe2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScoreDlg)
	afx_msg void OnCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOREDLG_H__90F03D59_63B0_42AD_B012_869C4579C1A6__INCLUDED_)
