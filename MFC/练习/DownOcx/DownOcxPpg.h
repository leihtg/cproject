#if !defined(AFX_DOWNOCXPPG_H__0597D725_756E_4812_84B7_20037914CCFC__INCLUDED_)
#define AFX_DOWNOCXPPG_H__0597D725_756E_4812_84B7_20037914CCFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DownOcxPpg.h : Declaration of the CDownOcxPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CDownOcxPropPage : See DownOcxPpg.cpp.cpp for implementation.

class CDownOcxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CDownOcxPropPage)
	DECLARE_OLECREATE_EX(CDownOcxPropPage)

// Constructor
public:
	CDownOcxPropPage();

// Dialog Data
	//{{AFX_DATA(CDownOcxPropPage)
	enum { IDD = IDD_PROPPAGE_DOWNOCX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CDownOcxPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNOCXPPG_H__0597D725_756E_4812_84B7_20037914CCFC__INCLUDED)
