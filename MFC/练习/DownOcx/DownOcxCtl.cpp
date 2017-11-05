// DownOcxCtl.cpp : Implementation of the CDownOcxCtrl ActiveX Control class.

#include "stdafx.h"
#include "DownOcx.h"
#include "DownOcxCtl.h"
#include "DownOcxPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CDownOcxCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDownOcxCtrl, COleControl)
	//{{AFX_MSG_MAP(CDownOcxCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CDownOcxCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CDownOcxCtrl)
	DISP_FUNCTION(CDownOcxCtrl, "DownLoad", DownLoad, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CDownOcxCtrl, COleControl)
	//{{AFX_EVENT_MAP(CDownOcxCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CDownOcxCtrl, 1)
	PROPPAGEID(CDownOcxPropPage::guid)
END_PROPPAGEIDS(CDownOcxCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDownOcxCtrl, "DOWNOCX.DownOcxCtrl.1",
	0xd5e7bb0c, 0xad13, 0x4f3c, 0xae, 0xe5, 0x1d, 0x4d, 0x24, 0x58, 0, 0x63)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CDownOcxCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DDownOcx =
		{ 0xcfe5f26b, 0xe523, 0x4241, { 0xb6, 0x99, 0xd2, 0x79, 0xe9, 0x24, 0, 0xc1 } };
const IID BASED_CODE IID_DDownOcxEvents =
		{ 0xc3d640d0, 0xc01b, 0x4fba, { 0x96, 0x5c, 0xc2, 0x6, 0xdc, 0x22, 0xfc, 0x7f } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwDownOcxOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CDownOcxCtrl, IDS_DOWNOCX, _dwDownOcxOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CDownOcxCtrl::CDownOcxCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CDownOcxCtrl

BOOL CDownOcxCtrl::CDownOcxCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_DOWNOCX,
			IDB_DOWNOCX,
			afxRegApartmentThreading,
			_dwDownOcxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxCtrl::CDownOcxCtrl - Constructor

CDownOcxCtrl::CDownOcxCtrl()
{
	InitializeIIDs(&IID_DDownOcx, &IID_DDownOcxEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxCtrl::~CDownOcxCtrl - Destructor

CDownOcxCtrl::~CDownOcxCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxCtrl::OnDraw - Drawing function

void CDownOcxCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxCtrl::DoPropExchange - Persistence support

void CDownOcxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxCtrl::OnResetState - Reset control to default state

void CDownOcxCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxCtrl message handlers

void CDownOcxCtrl::DownLoad() 
{
	// TODO: Add your dispatch handler code here
	CInternetSession session;
	CInternetFile *webfile;
	webfile=(CInternetFile*)session.OpenURL("http://pic1.win4000.com/wallpaper/c/53d715bd3a34b.jpg");
	if(webfile){
		char c[2048];
		int i=0;
		CFile file("C:\\Users\\Thinkpad\\Desktop\\a.jpg",CFile::modeCreate|CFile::modeWrite);
		while((i=webfile->Read(c,2048))!=0){
			file.Write(c,i);
		}
		file.Close();
	}

}
