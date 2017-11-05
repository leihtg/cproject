// Êý¾Ý¿â1Dlg.h : header file
//

#if !defined(AFX_1DLG_H__F2FD7A5D_4F83_4075_B48C_4DD390E0BDDB__INCLUDED_)
#define AFX_1DLG_H__F2FD7A5D_4F83_4075_B48C_4DD390E0BDDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1Dlg dialog

class CMy1Dlg : public CDialog
{
// Construction
public:
	CMy1Dlg(CWnd* pParent = NULL);	// standard constructor
	void ShowRecord();
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	int count;
	int curNo;
// Dialog Data
	//{{AFX_DATA(CMy1Dlg)
	enum { IDD = IDD_MY1_DIALOG };
	CString	m_StuNo;
	CString	m_StuName;
	CString	m_StuAddress;
	CString	m_StuTel;
	CString	m_Status;
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1Dlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnAdd();
	afx_msg void OnRemove();
	afx_msg void OnCheckin();
	afx_msg void OnFirst();
	afx_msg void OnNext();
	afx_msg void OnPrev();
	afx_msg void OnLast();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1DLG_H__F2FD7A5D_4F83_4075_B48C_4DD390E0BDDB__INCLUDED_)
