// OcxDownCtl.cpp : Implementation of the COcxDownCtrl ActiveX Control class.

#include "stdafx.h"
#include "OcxDown.h"
#include "OcxDownCtl.h"
#include "OcxDownPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COcxDownCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map
 
BEGIN_MESSAGE_MAP(COcxDownCtrl, COleControl)
	//{{AFX_MSG_MAP(COcxDownCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(COcxDownCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(COcxDownCtrl)
	DISP_FUNCTION(COcxDownCtrl, "download", download, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(COcxDownCtrl, "CCC", CCC, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(COcxDownCtrl, "AboutBoxa", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(COcxDownCtrl, COleControl)
	//{{AFX_EVENT_MAP(COcxDownCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(COcxDownCtrl, 1)
	PROPPAGEID(COcxDownPropPage::guid)
END_PROPPAGEIDS(COcxDownCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COcxDownCtrl, "OCXDOWN.OcxDownCtrl.1",
	0xcf31aed0, 0x797a, 0x416e, 0x83, 0x5c, 0x37, 0x4e, 0xd2, 0x57, 0x84, 0x51)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(COcxDownCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DOcxDown =
		{ 0x167f18a0, 0xe691, 0x4dad, { 0xbd, 0x37, 0x63, 0xb1, 0x30, 0x8b, 0xae, 0x7b } };
const IID BASED_CODE IID_DOcxDownEvents =
		{ 0xbd13c918, 0xbb1d, 0x4c27, { 0x83, 0x5b, 0xb6, 0xfb, 0xa1, 0x7a, 0x1c, 0x37 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwOcxDownOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(COcxDownCtrl, IDS_OCXDOWN, _dwOcxDownOleMisc)


/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl::COcxDownCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for COcxDownCtrl

BOOL COcxDownCtrl::COcxDownCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_OCXDOWN,
			IDB_OCXDOWN,
			afxRegApartmentThreading,
			_dwOcxDownOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl::COcxDownCtrl - Constructor

COcxDownCtrl::COcxDownCtrl()
{
	InitializeIIDs(&IID_DOcxDown, &IID_DOcxDownEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl::~COcxDownCtrl - Destructor

COcxDownCtrl::~COcxDownCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl::OnDraw - Drawing function

void COcxDownCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
//	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
//	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl::DoPropExchange - Persistence support

void COcxDownCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl::OnResetState - Reset control to default state

void COcxDownCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl::AboutBox - Display an "About" box to the user

void COcxDownCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_OCXDOWN);
	dlgAbout.DoModal();
}

void COcxDownCtrl::download(){
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
/////////////////////////////////////////////////////////////////////////////
// COcxDownCtrl message handlers



void COcxDownCtrl::CCC() 
{
	// TODO: Add your dispatch handler code here

}
