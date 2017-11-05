// UrlDownCtl.cpp : Implementation of the CUrlDownCtrl ActiveX Control class.

#include "stdafx.h"
#include "UrlDown.h"
#include "UrlDownCtl.h"
#include "UrlDownPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CUrlDownCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CUrlDownCtrl, COleControl)
	//{{AFX_MSG_MAP(CUrlDownCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	ON_BN_CLICKED(IDC_MM,click)
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CUrlDownCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CUrlDownCtrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CUrlDownCtrl, COleControl)
	//{{AFX_EVENT_MAP(CUrlDownCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CUrlDownCtrl, 1)
	PROPPAGEID(CUrlDownPropPage::guid)
END_PROPPAGEIDS(CUrlDownCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CUrlDownCtrl, "URLDOWN.UrlDownCtrl.1",
	0x99b404fb, 0x8b1e, 0x49c5, 0xb0, 0x34, 0x20, 0x7e, 0xa2, 0x59, 0x59, 0x84)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CUrlDownCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DUrlDown =
		{ 0x5667e813, 0xf9da, 0x4076, { 0x92, 0x13, 0x3f, 0x75, 0x27, 0x9e, 0xeb, 0x6f } };
const IID BASED_CODE IID_DUrlDownEvents =
		{ 0x40442815, 0xac5b, 0x49a1, { 0xa1, 0xa9, 0x8a, 0xd7, 0xc9, 0xe0, 0x31, 0x64 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwUrlDownOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CUrlDownCtrl, IDS_URLDOWN, _dwUrlDownOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CUrlDownCtrl::CUrlDownCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CUrlDownCtrl

BOOL CUrlDownCtrl::CUrlDownCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_URLDOWN,
			IDB_URLDOWN,
			afxRegApartmentThreading,
			_dwUrlDownOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CUrlDownCtrl::CUrlDownCtrl - Constructor

CUrlDownCtrl::CUrlDownCtrl()
{
	InitializeIIDs(&IID_DUrlDown, &IID_DUrlDownEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CUrlDownCtrl::~CUrlDownCtrl - Destructor

CUrlDownCtrl::~CUrlDownCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CUrlDownCtrl::OnDraw - Drawing function

void CUrlDownCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
//	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
//	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CUrlDownCtrl::DoPropExchange - Persistence support

void CUrlDownCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CUrlDownCtrl::OnResetState - Reset control to default state

void CUrlDownCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}

void CUrlDownCtrl::download(){
		btn.Create(_T("Ôö¼Ó"),WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,CRect(10,10,60,30),this,IDC_MM);
/*	CInternetSession session;
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
		delete webfile;
		session.Close();
	}
	*/
}

void CUrlDownCtrl::click(){
	MessageBox("hello");
}
/////////////////////////////////////////////////////////////////////////////
// CUrlDownCtrl message handlers
