// OcxDemoCtl.cpp : Implementation of the COcxDemoCtrl ActiveX Control class.

#include "stdafx.h"
#include "OcxDemo.h"
#include "OcxDemoCtl.h"
#include "OcxDemoPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COcxDemoCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COcxDemoCtrl, COleControl)
	//{{AFX_MSG_MAP(COcxDemoCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	ON_BN_CLICKED(IDC_BTN,add)
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(COcxDemoCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(COcxDemoCtrl)
	DISP_FUNCTION(COcxDemoCtrl, "Create", Create, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(COcxDemoCtrl, "ABCD", ABCD, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(COcxDemoCtrl, COleControl)
	//{{AFX_EVENT_MAP(COcxDemoCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(COcxDemoCtrl, 1)
	PROPPAGEID(COcxDemoPropPage::guid)
END_PROPPAGEIDS(COcxDemoCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COcxDemoCtrl, "OCXDEMO.OcxDemoCtrl.1",
	0x404d4f07, 0xe3d5, 0x41fe, 0x8d, 0x52, 0x98, 0x8e, 0x6f, 0x8d, 0xec, 0xbb)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(COcxDemoCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DOcxDemo =
		{ 0x5b81d1f, 0x8910, 0x4eff, { 0x83, 0xaf, 0x3c, 0xdd, 0x7c, 0xee, 0xd5, 0 } };
const IID BASED_CODE IID_DOcxDemoEvents =
		{ 0x5c23044, 0x7cba, 0x4555, { 0x9c, 0x95, 0x38, 0xc1, 0xa3, 0xc4, 0x76, 0xb8 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwOcxDemoOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(COcxDemoCtrl, IDS_OCXDEMO, _dwOcxDemoOleMisc)


/////////////////////////////////////////////////////////////////////////////
// COcxDemoCtrl::COcxDemoCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for COcxDemoCtrl

BOOL COcxDemoCtrl::COcxDemoCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_OCXDEMO,
			IDB_OCXDEMO,
			afxRegApartmentThreading,
			_dwOcxDemoOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// COcxDemoCtrl::COcxDemoCtrl - Constructor

COcxDemoCtrl::COcxDemoCtrl()
{
	InitializeIIDs(&IID_DOcxDemo, &IID_DOcxDemoEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// COcxDemoCtrl::~COcxDemoCtrl - Destructor

COcxDemoCtrl::~COcxDemoCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// COcxDemoCtrl::OnDraw - Drawing function

void COcxDemoCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
//	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
//	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// COcxDemoCtrl::DoPropExchange - Persistence support

void COcxDemoCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// COcxDemoCtrl::OnResetState - Reset control to default state

void COcxDemoCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
		
	// TODO: Reset any other control state here.
}
/////////////////////////////////////////////////////////////////////////////
// COcxDemoCtrl message handlers

void COcxDemoCtrl::Create() 
{
	// TODO: Add your dispatch handler code here
btn.Create(_T("Ôö¼Ó"),WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,CRect(10,10,60,30),this,IDC_BTN);
}
void COcxDemoCtrl::add(){
	MessageBox("hello");
}

void COcxDemoCtrl::ABCD() 
{
	// TODO: Add your dispatch handler code here

}
