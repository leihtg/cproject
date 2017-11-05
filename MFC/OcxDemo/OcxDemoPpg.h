#if !defined(AFX_OCXDEMOPPG_H__347E1C95_9BEA_451C_9B90_C080DAC301BB__INCLUDED_)
#define AFX_OCXDEMOPPG_H__347E1C95_9BEA_451C_9B90_C080DAC301BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OcxDemoPpg.h : Declaration of the COcxDemoPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// COcxDemoPropPage : See OcxDemoPpg.cpp.cpp for implementation.

class COcxDemoPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(COcxDemoPropPage)
	DECLARE_OLECREATE_EX(COcxDemoPropPage)

// Constructor
public:
	COcxDemoPropPage();

// Dialog Data
	//{{AFX_DATA(COcxDemoPropPage)
	enum { IDD = IDD_PROPPAGE_OCXDEMO };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(COcxDemoPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXDEMOPPG_H__347E1C95_9BEA_451C_9B90_C080DAC301BB__INCLUDED)
