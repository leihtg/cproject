// TimePpg.cpp : Implementation of the CTimePropPage property page class.

#include "stdafx.h"
#include "time.h"
#include "TimePpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTimePropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTimePropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CTimePropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTimePropPage, "TIME.TimePropPage.1",
	0xb2f3d302, 0xcbab, 0x429d, 0xa7, 0xa0, 0xbb, 0x6a, 0xbe, 0xf, 0xe1, 0x46)


/////////////////////////////////////////////////////////////////////////////
// CTimePropPage::CTimePropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTimePropPage

BOOL CTimePropPage::CTimePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TIME_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTimePropPage::CTimePropPage - Constructor

CTimePropPage::CTimePropPage() :
	COlePropertyPage(IDD, IDS_TIME_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CTimePropPage)
	m_updateInterval = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTimePropPage::DoDataExchange - Moves data between page and properties

void CTimePropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CTimePropPage)
	DDP_Text(pDX, IDC_EDIT_INTERVAL, m_updateInterval, _T("interval") );
	DDX_Text(pDX, IDC_EDIT_INTERVAL, m_updateInterval);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTimePropPage message handlers
