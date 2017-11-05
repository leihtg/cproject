// DzDownloadPicCtl.cpp : Implementation of the CDzDownloadPicCtrl ActiveX Control class.

#include "stdafx.h"
#include "dzDownloadPic.h"
#include "DzDownloadPicCtl.h"
#include "DzDownloadPicPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CDzDownloadPicCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDzDownloadPicCtrl, COleControl)
	//{{AFX_MSG_MAP(CDzDownloadPicCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CDzDownloadPicCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CDzDownloadPicCtrl)
	DISP_FUNCTION(CDzDownloadPicCtrl, "getPic", getPic, VT_BOOL, VTS_BSTR VTS_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CDzDownloadPicCtrl, COleControl)
	//{{AFX_EVENT_MAP(CDzDownloadPicCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CDzDownloadPicCtrl, 1)
	PROPPAGEID(CDzDownloadPicPropPage::guid)
END_PROPPAGEIDS(CDzDownloadPicCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDzDownloadPicCtrl, "DZDOWNLOADPIC.DzDownloadPicCtrl.1",
	0x3d99128, 0x5c3b, 0x4bd0, 0x8a, 0x66, 0xcd, 0x93, 0x21, 0xda, 0x83, 0x8b)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CDzDownloadPicCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DDzDownloadPic =
		{ 0x6da65781, 0x1988, 0x4c7f, { 0xb8, 0xfc, 0xe3, 0xbf, 0x63, 0xc2, 0xf6, 0xeb } };
const IID BASED_CODE IID_DDzDownloadPicEvents =
		{ 0x401fd0bb, 0x355f, 0x497d, { 0xb2, 0x35, 0xca, 0xac, 0x52, 0x94, 0x39, 0x8f } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwDzDownloadPicOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CDzDownloadPicCtrl, IDS_DZDOWNLOADPIC, _dwDzDownloadPicOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicCtrl::CDzDownloadPicCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CDzDownloadPicCtrl

BOOL CDzDownloadPicCtrl::CDzDownloadPicCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_DZDOWNLOADPIC,
			IDB_DZDOWNLOADPIC,
			afxRegApartmentThreading,
			_dwDzDownloadPicOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicCtrl::CDzDownloadPicCtrl - Constructor

CDzDownloadPicCtrl::CDzDownloadPicCtrl()
{
	InitializeIIDs(&IID_DDzDownloadPic, &IID_DDzDownloadPicEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicCtrl::~CDzDownloadPicCtrl - Destructor

CDzDownloadPicCtrl::~CDzDownloadPicCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicCtrl::OnDraw - Drawing function

void CDzDownloadPicCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
//	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
//	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicCtrl::DoPropExchange - Persistence support

void CDzDownloadPicCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicCtrl::OnResetState - Reset control to default state

void CDzDownloadPicCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicCtrl message handlers

BOOL CDzDownloadPicCtrl::getPic(LPCTSTR remoteUrl, LPCTSTR localPath) 
{
	// TODO: Add your dispatch handler code here
	CInternetSession session;
	CInternetFile *webfile=NULL;
	try{
		webfile=(CInternetFile*)session.OpenURL(remoteUrl);
	}catch(CInternetException* p){
		MessageBox("无效的url地址！");
		webfile=NULL;
		p->Delete();
		return FALSE;
	}
	
	if(webfile){
		CFile file(localPath,CFile::modeCreate|CFile::modeWrite);
		char tmp[2048];
		int i=0;
		while((i=webfile->Read(tmp,sizeof(tmp)))!=0){
			file.Write(tmp,i);
		}
		file.Close();
	}
	delete webfile;
	return TRUE;
}
