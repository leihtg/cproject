#if !defined(AFX_OCXDOWNPPG_H__5A73B279_0978_48BA_A3AD_AA97CF522823__INCLUDED_)
#define AFX_OCXDOWNPPG_H__5A73B279_0978_48BA_A3AD_AA97CF522823__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OcxDownPpg.h : Declaration of the COcxDownPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// COcxDownPropPage : See OcxDownPpg.cpp.cpp for implementation.

class COcxDownPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(COcxDownPropPage)
	DECLARE_OLECREATE_EX(COcxDownPropPage)

// Constructor
public:
	COcxDownPropPage();

// Dialog Data
	//{{AFX_DATA(COcxDownPropPage)
	enum { IDD = IDD_PROPPAGE_OCXDOWN };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(COcxDownPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXDOWNPPG_H__5A73B279_0978_48BA_A3AD_AA97CF522823__INCLUDED)
