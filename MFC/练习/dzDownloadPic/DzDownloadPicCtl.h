#if !defined(AFX_DZDOWNLOADPICCTL_H__DD0982D4_55D4_4F12_8F5F_16585E23DC7E__INCLUDED_)
#define AFX_DZDOWNLOADPICCTL_H__DD0982D4_55D4_4F12_8F5F_16585E23DC7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxinet.h>
// DzDownloadPicCtl.h : Declaration of the CDzDownloadPicCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicCtrl : See DzDownloadPicCtl.cpp for implementation.

class CDzDownloadPicCtrl : public COleControl
{
	DECLARE_DYNCREATE(CDzDownloadPicCtrl)

// Constructor
public:
	CDzDownloadPicCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDzDownloadPicCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CDzDownloadPicCtrl();

	DECLARE_OLECREATE_EX(CDzDownloadPicCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CDzDownloadPicCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CDzDownloadPicCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CDzDownloadPicCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CDzDownloadPicCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CDzDownloadPicCtrl)
	afx_msg BOOL getPic(LPCTSTR remoteUrl, LPCTSTR localPath);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CDzDownloadPicCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CDzDownloadPicCtrl)
	dispidGetPic = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DZDOWNLOADPICCTL_H__DD0982D4_55D4_4F12_8F5F_16585E23DC7E__INCLUDED)
