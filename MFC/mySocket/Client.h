#if !defined(AFX_CLIENT_H__D42705B2_3B05_4545_8CF5_EC4CF10DCB81__INCLUDED_)
#define AFX_CLIENT_H__D42705B2_3B05_4545_8CF5_EC4CF10DCB81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Client.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClient dialog

class CClient : public CDialog
{
// Construction
public:
	CClient(CWnd* pParent = NULL);   // standard constructor
	CTime time;
	CSocket m_socket;
// Dialog Data
	//{{AFX_DATA(CClient)
	enum { IDD = idd_client };
	CListBox	m_list;
	CIPAddressCtrl	m_serverIP;
	int		m_serverPort;
	CString	m_text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClient)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClient)
	afx_msg void OnOpen();
	afx_msg void OnClose();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENT_H__D42705B2_3B05_4545_8CF5_EC4CF10DCB81__INCLUDED_)
