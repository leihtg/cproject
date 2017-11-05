#if !defined(AFX_OCXDEMOCTL_H__D74A8EAD_969E_4882_89BD_E0A6B92BB536__INCLUDED_)
#define AFX_OCXDEMOCTL_H__D74A8EAD_969E_4882_89BD_E0A6B92BB536__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define IDC_BUTTON_ADD 0x2001 //Ôö¼Ó°´Å¥
// OcxDemoCtl.h : Declaration of the COcxDemoCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// COcxDemoCtrl : See OcxDemoCtl.cpp for implementation.

class COcxDemoCtrl : public COleControl
{
	DECLARE_DYNCREATE(COcxDemoCtrl)
private:
	CButton m_BtnAdd;
	void OnButtonAdd();
// Constructor
public:
	COcxDemoCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxDemoCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~COcxDemoCtrl();

	DECLARE_OLECREATE_EX(COcxDemoCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(COcxDemoCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(COcxDemoCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(COcxDemoCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(COcxDemoCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(COcxDemoCtrl)
	afx_msg void CreateBtnAdd();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(COcxDemoCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(COcxDemoCtrl)
	dispidCreateBtnAdd = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXDEMOCTL_H__D74A8EAD_969E_4882_89BD_E0A6B92BB536__INCLUDED)
