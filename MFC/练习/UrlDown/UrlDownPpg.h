#if !defined(AFX_URLDOWNPPG_H__C46E55CB_3300_470A_885A_B08E1CA1779C__INCLUDED_)
#define AFX_URLDOWNPPG_H__C46E55CB_3300_470A_885A_B08E1CA1779C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// UrlDownPpg.h : Declaration of the CUrlDownPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CUrlDownPropPage : See UrlDownPpg.cpp.cpp for implementation.

class CUrlDownPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CUrlDownPropPage)
	DECLARE_OLECREATE_EX(CUrlDownPropPage)

// Constructor
public:
	CUrlDownPropPage();

// Dialog Data
	//{{AFX_DATA(CUrlDownPropPage)
	enum { IDD = IDD_PROPPAGE_URLDOWN };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CUrlDownPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_URLDOWNPPG_H__C46E55CB_3300_470A_885A_B08E1CA1779C__INCLUDED)
