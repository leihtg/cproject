// UrlDownPpg.cpp : Implementation of the CUrlDownPropPage property page class.

#include "stdafx.h"
#include "UrlDown.h"
#include "UrlDownPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CUrlDownPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CUrlDownPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CUrlDownPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CUrlDownPropPage, "URLDOWN.UrlDownPropPage.1",
	0x53a59434, 0x4bfc, 0x4c4c, 0x9a, 0x2f, 0x5d, 0x11, 0x43, 0xd6, 0xfe, 0xa3)


/////////////////////////////////////////////////////////////////////////////
// CUrlDownPropPage::CUrlDownPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CUrlDownPropPage

BOOL CUrlDownPropPage::CUrlDownPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_URLDOWN_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CUrlDownPropPage::CUrlDownPropPage - Constructor

CUrlDownPropPage::CUrlDownPropPage() :
	COlePropertyPage(IDD, IDS_URLDOWN_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CUrlDownPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CUrlDownPropPage::DoDataExchange - Moves data between page and properties

void CUrlDownPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CUrlDownPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CUrlDownPropPage message handlers
