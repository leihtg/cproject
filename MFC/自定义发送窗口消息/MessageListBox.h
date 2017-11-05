#if !defined(AFX_MESSAGELISTBOX_H__783C4748_8978_40BE_93D4_1AE7E61F6DA6__INCLUDED_)
#define AFX_MESSAGELISTBOX_H__783C4748_8978_40BE_93D4_1AE7E61F6DA6__INCLUDED_

#define	WM_LBMESSAGE_DBCLCK     WM_USER + 0x1000
#define wm_selchange            WM_USER + 0x1001


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MessageListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMessageListBox window

class CMessageListBox : public CListBox
{
// Construction
public:
	CMessageListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessageListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMessageListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMessageListBox)
	afx_msg void OnDblclk();
	afx_msg void OnSelchange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGELISTBOX_H__783C4748_8978_40BE_93D4_1AE7E61F6DA6__INCLUDED_)
