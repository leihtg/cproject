#if !defined(AFX_DZDOWNLOADPICPPG_H__D3F690A3_0498_4DAC_80E2_A980CD77B00A__INCLUDED_)
#define AFX_DZDOWNLOADPICPPG_H__D3F690A3_0498_4DAC_80E2_A980CD77B00A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DzDownloadPicPpg.h : Declaration of the CDzDownloadPicPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicPropPage : See DzDownloadPicPpg.cpp.cpp for implementation.

class CDzDownloadPicPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CDzDownloadPicPropPage)
	DECLARE_OLECREATE_EX(CDzDownloadPicPropPage)

// Constructor
public:
	CDzDownloadPicPropPage();

// Dialog Data
	//{{AFX_DATA(CDzDownloadPicPropPage)
	enum { IDD = IDD_PROPPAGE_DZDOWNLOADPIC };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CDzDownloadPicPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DZDOWNLOADPICPPG_H__D3F690A3_0498_4DAC_80E2_A980CD77B00A__INCLUDED)
