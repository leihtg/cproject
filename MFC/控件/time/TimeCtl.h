#if !defined(AFX_TIMECTL_H__AD358A1B_CF1F_4BAC_908D_CFB75F70B06C__INCLUDED_)
#define AFX_TIMECTL_H__AD358A1B_CF1F_4BAC_908D_CFB75F70B06C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TimeCtl.h : Declaration of the CTimeCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl : See TimeCtl.cpp for implementation.

class CTimeCtrl : public COleControl
{
	DECLARE_DYNCREATE(CTimeCtrl)

// Constructor
public:
	CTimeCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CTimeCtrl();

	DECLARE_OLECREATE_EX(CTimeCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CTimeCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTimeCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CTimeCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CTimeCtrl)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CTimeCtrl)
	short m_interval;
	afx_msg void OnIntervalChanged();
	long m_myTestVar;
	afx_msg void OnMyTestVarChanged();
	afx_msg void Hello();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CTimeCtrl)
	void FireNewMinute()
		{FireEvent(eventidNewMinute,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CTimeCtrl)
	dispidInterval = 1L,
	dispidMyTestVar = 2L,
	dispidHello = 3L,
	eventidNewMinute = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECTL_H__AD358A1B_CF1F_4BAC_908D_CFB75F70B06C__INCLUDED)
