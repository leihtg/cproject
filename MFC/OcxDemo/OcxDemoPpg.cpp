// OcxDemoPpg.cpp : Implementation of the COcxDemoPropPage property page class.

#include "stdafx.h"
#include "OcxDemo.h"
#include "OcxDemoPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COcxDemoPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COcxDemoPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(COcxDemoPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COcxDemoPropPage, "OCXDEMO.OcxDemoPropPage.1",
	0x3a2af393, 0xc54f, 0x42a8, 0xad, 0xa, 0xda, 0xf, 0x18, 0xf2, 0x96, 0x16)


/////////////////////////////////////////////////////////////////////////////
// COcxDemoPropPage::COcxDemoPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for COcxDemoPropPage

BOOL COcxDemoPropPage::COcxDemoPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_OCXDEMO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// COcxDemoPropPage::COcxDemoPropPage - Constructor

COcxDemoPropPage::COcxDemoPropPage() :
	COlePropertyPage(IDD, IDS_OCXDEMO_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(COcxDemoPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// COcxDemoPropPage::DoDataExchange - Moves data between page and properties

void COcxDemoPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(COcxDemoPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// COcxDemoPropPage message handlers
