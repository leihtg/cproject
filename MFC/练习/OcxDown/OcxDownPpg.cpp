// OcxDownPpg.cpp : Implementation of the COcxDownPropPage property page class.

#include "stdafx.h"
#include "OcxDown.h"
#include "OcxDownPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COcxDownPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COcxDownPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(COcxDownPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COcxDownPropPage, "OCXDOWN.OcxDownPropPage.1",
	0xf54bedaa, 0xa369, 0x45d7, 0x9b, 0xd2, 0x7b, 0x4c, 0xdb, 0x5b, 0x8c, 0xcf)


/////////////////////////////////////////////////////////////////////////////
// COcxDownPropPage::COcxDownPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for COcxDownPropPage

BOOL COcxDownPropPage::COcxDownPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_OCXDOWN_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// COcxDownPropPage::COcxDownPropPage - Constructor

COcxDownPropPage::COcxDownPropPage() :
	COlePropertyPage(IDD, IDS_OCXDOWN_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(COcxDownPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// COcxDownPropPage::DoDataExchange - Moves data between page and properties

void COcxDownPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(COcxDownPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// COcxDownPropPage message handlers
