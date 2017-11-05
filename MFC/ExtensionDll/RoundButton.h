#if !defined(AFX_ROUNDBUTTON_H__1698EDB7_3E09_47E9_9F2A_FB4854059F3C__INCLUDED_)
#define AFX_ROUNDBUTTON_H__1698EDB7_3E09_47E9_9F2A_FB4854059F3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoundButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoundButton window

class CRoundButton : public CButton
{
// Construction
public:
	CRoundButton();

// Attributes
public:
	CRgn m_ValidRegion;
	CPoint m_ptCentre;
	int m_nRadius;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoundButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRoundButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRoundButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROUNDBUTTON_H__1698EDB7_3E09_47E9_9F2A_FB4854059F3C__INCLUDED_)
