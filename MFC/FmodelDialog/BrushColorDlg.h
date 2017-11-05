#if !defined(AFX_BRUSHCOLORDLG_H__E18952CD_E276_407E_91C1_7EC0DFB18DA3__INCLUDED_)
#define AFX_BRUSHCOLORDLG_H__E18952CD_E276_407E_91C1_7EC0DFB18DA3__INCLUDED_
#include WM_SET_COLOR WM_USER+100
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BrushColorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBrushColorDlg dialog

class CBrushColorDlg : public CDialog
{
// Construction
public:
	CBrushColorDlg(CWnd* pParent = NULL);   // standard constructor
	CWnd* m_pParent;
// Dialog Data
	//{{AFX_DATA(CBrushColorDlg)
	enum { IDD = IDD_DIALOG1 };
	int		m_red;
	int		m_green;
	int		m_blue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrushColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBrushColorDlg)
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRUSHCOLORDLG_H__E18952CD_E276_407E_91C1_7EC0DFB18DA3__INCLUDED_)
