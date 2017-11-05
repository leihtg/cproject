#if !defined(AFX_OCXDOWNCTL_H__030B9F78_4F20_4DB1_9F8F_AB82ADDFAA3B__INCLUDED_)
#define AFX_OCXDOWNCTL_H__030B9F78_4F20_4DB1_9F8F_AB82ADDFAA3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxinet.h>

// OcxDownCtl.h : Declaration of the COcxDownCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl : See OcxDownCtl.cpp for implementation.

class COcxDownCtrl : public COleControl
{
	DECLARE_DYNCREATE(COcxDownCtrl)

// Constructor
public:
	COcxDownCtrl();
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxDownCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~COcxDownCtrl();

	DECLARE_OLECREATE_EX(COcxDownCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(COcxDownCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(COcxDownCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(COcxDownCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(COcxDownCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(COcxDownCtrl)
	afx_msg void download();
	afx_msg void CCC();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	
	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(COcxDownCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:

	
	enum {
	//{{AFX_DISP_ID(COcxDownCtrl)
	dispidDownload = 1L,
	dispidCCC = 2L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXDOWNCTL_H__030B9F78_4F20_4DB1_9F8F_AB82ADDFAA3B__INCLUDED)
