#if !defined(AFX_TIMEPPG_H__9977A2CA_CA5D_4F29_AA1D_D3DDA5A7F842__INCLUDED_)
#define AFX_TIMEPPG_H__9977A2CA_CA5D_4F29_AA1D_D3DDA5A7F842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TimePpg.h : Declaration of the CTimePropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CTimePropPage : See TimePpg.cpp.cpp for implementation.

class CTimePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTimePropPage)
	DECLARE_OLECREATE_EX(CTimePropPage)

// Constructor
public:
	CTimePropPage();

// Dialog Data
	//{{AFX_DATA(CTimePropPage)
	enum { IDD = IDD_PROPPAGE_TIME };
	short	m_updateInterval;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CTimePropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEPPG_H__9977A2CA_CA5D_4F29_AA1D_D3DDA5A7F842__INCLUDED)
