// TimeCtl.cpp : Implementation of the CTimeCtrl ActiveX Control class.

#include "stdafx.h"
#include "time.h"
#include "TimeCtl.h"
#include "TimePpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTimeCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTimeCtrl, COleControl)
	//{{AFX_MSG_MAP(CTimeCtrl)
	ON_WM_TIMER()
	ON_WM_ACTIVATE()
	ON_WM_DESTROY()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CTimeCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CTimeCtrl)
	DISP_PROPERTY_NOTIFY(CTimeCtrl, "interval", m_interval, OnIntervalChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CTimeCtrl, "myTestVar", m_myTestVar, OnMyTestVarChanged, VT_I4)
	DISP_FUNCTION(CTimeCtrl, "Hello", Hello, VT_EMPTY, VTS_NONE)
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CTimeCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTimeCtrl, COleControl)
	//{{AFX_EVENT_MAP(CTimeCtrl)
	EVENT_CUSTOM("NewMinute", FireNewMinute, VTS_NONE)
	EVENT_STOCK_CLICK()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTimeCtrl, 2)
	PROPPAGEID(CTimePropPage::guid)
	PROPPAGEID(CLSID_CColorPropPage);
END_PROPPAGEIDS(CTimeCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTimeCtrl, "TIME.TimeCtrl.1",
	0x7f53fa32, 0x8c1c, 0x462a, 0x9b, 0xe8, 0x70, 0x11, 0x2f, 0x44, 0xb5, 0x41)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTimeCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTime =
		{ 0x204c1ed0, 0xc9e0, 0x4ac1, { 0xbe, 0xaa, 0xd5, 0xaf, 0x18, 0x24, 0x1e, 0xf1 } };
const IID BASED_CODE IID_DTimeEvents =
		{ 0xfa62694a, 0x55e7, 0x4509, { 0x9c, 0x54, 0x24, 0x82, 0x18, 0x4d, 0xb8, 0x6a } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTimeOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTimeCtrl, IDS_TIME, _dwTimeOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::CTimeCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTimeCtrl

BOOL CTimeCtrl::CTimeCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_TIME,
			IDB_TIME,
			afxRegApartmentThreading,
			_dwTimeOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::CTimeCtrl - Constructor

CTimeCtrl::CTimeCtrl()
{
	InitializeIIDs(&IID_DTime, &IID_DTimeEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::~CTimeCtrl - Destructor

CTimeCtrl::~CTimeCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnDraw - Drawing function

void CTimeCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
//	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
//	pdc->Ellipse(rcBounds);
	CBrush brush(TranslateColor(GetBackColor()));

	pdc->FillRect(rcBounds,&brush);
	pdc->SetBkMode(TRANSPARENT);
	pdc->SetTextColor(TranslateColor(GetForeColor()));
	CTime time=CTime::GetCurrentTime();
	if(0==time.GetSecond()){
		FireNewMinute();
	}
	CString str=time.Format("%H:%M:%S");
	pdc->TextOut(0,0,str);
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::DoPropExchange - Persistence support

void CTimeCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

		

	// TODO: Call PX_ functions for each persistent custom property.
	PX_Short(pPX,"interval",m_interval,1000);
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnResetState - Reset control to default state

void CTimeCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::AboutBox - Display an "About" box to the user

void CTimeCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_TIME);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl message handlers

void CTimeCtrl::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(AmbientUserMode())
	Invalidate();
	
	COleControl::OnTimer(nIDEvent);
}

void CTimeCtrl::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	COleControl::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	
}

void CTimeCtrl::OnDestroy() 
{
	COleControl::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

int CTimeCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1,m_interval,NULL);
	return 0;
}

void CTimeCtrl::OnIntervalChanged() 
{
	// TODO: Add notification handler code
	if(m_interval<0||m_interval>6000){
		m_interval=1000;
	}else{
		m_interval=m_interval/1000*1000;
	}
	KillTimer(1);
	SetTimer(1,m_interval,NULL);
	BoundPropertyChanged(0x1);
	SetModifiedFlag();
}

void CTimeCtrl::Hello() 
{
	// TODO: Add your dispatch handler code here
	MessageBox("Hello World!");
}

void CTimeCtrl::OnMyTestVarChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}
