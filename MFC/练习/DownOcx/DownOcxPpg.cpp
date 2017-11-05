// DownOcxPpg.cpp : Implementation of the CDownOcxPropPage property page class.

#include "stdafx.h"
#include "DownOcx.h"
#include "DownOcxPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CDownOcxPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDownOcxPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CDownOcxPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDownOcxPropPage, "DOWNOCX.DownOcxPropPage.1",
	0xe2bafdfb, 0xda83, 0x4ba4, 0x91, 0xa4, 0x73, 0x86, 0x2b, 0xf3, 0x84, 0x51)


/////////////////////////////////////////////////////////////////////////////
// CDownOcxPropPage::CDownOcxPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CDownOcxPropPage

BOOL CDownOcxPropPage::CDownOcxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_DOWNOCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxPropPage::CDownOcxPropPage - Constructor

CDownOcxPropPage::CDownOcxPropPage() :
	COlePropertyPage(IDD, IDS_DOWNOCX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CDownOcxPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxPropPage::DoDataExchange - Moves data between page and properties

void CDownOcxPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CDownOcxPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CDownOcxPropPage message handlers
