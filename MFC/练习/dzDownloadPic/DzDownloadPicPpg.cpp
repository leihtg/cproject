// DzDownloadPicPpg.cpp : Implementation of the CDzDownloadPicPropPage property page class.

#include "stdafx.h"
#include "dzDownloadPic.h"
#include "DzDownloadPicPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CDzDownloadPicPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDzDownloadPicPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CDzDownloadPicPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDzDownloadPicPropPage, "DZDOWNLOADPIC.DzDownloadPicPropPage.1",
	0xdb41eb3d, 0x728c, 0x45e7, 0xa3, 0x10, 0xa6, 0x45, 0x2e, 0x27, 0x9e, 0xdd)


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicPropPage::CDzDownloadPicPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CDzDownloadPicPropPage

BOOL CDzDownloadPicPropPage::CDzDownloadPicPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_DZDOWNLOADPIC_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicPropPage::CDzDownloadPicPropPage - Constructor

CDzDownloadPicPropPage::CDzDownloadPicPropPage() :
	COlePropertyPage(IDD, IDS_DZDOWNLOADPIC_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CDzDownloadPicPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicPropPage::DoDataExchange - Moves data between page and properties

void CDzDownloadPicPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CDzDownloadPicPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CDzDownloadPicPropPage message handlers
