#if !defined(AFX_URLDOWNCTL_H__94BD65C2_009B_4BBF_B4AE_4708CF4657DE__INCLUDED_)
#define AFX_URLDOWNCTL_H__94BD65C2_009B_4BBF_B4AE_4708CF4657DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxinet.h>
#define IDC_MM WM_USER +0x1001
// UrlDownCtl.h : Declaration of the CUrlDownCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CUrlDownCtrl : See UrlDownCtl.cpp for implementation.

class CUrlDownCtrl : public COleControl
{
	DECLARE_DYNCREATE(CUrlDownCtrl)

// Constructor
public:
	CUrlDownCtrl();
	void click();
	CButton btn;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUrlDownCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CUrlDownCtrl();

	DECLARE_OLECREATE_EX(CUrlDownCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CUrlDownCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CUrlDownCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CUrlDownCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CUrlDownCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CUrlDownCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CUrlDownCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
		afx_msg void download();
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CUrlDownCtrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_URLDOWNCTL_H__94BD65C2_009B_4BBF_B4AE_4708CF4657DE__INCLUDED)
