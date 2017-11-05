// MenuIcon.cpp : implementation file
//

#include "stdafx.h"
#include "iconMenu.h"
#include "MenuIcon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuIcon dialog


CMenuIcon::CMenuIcon(CWnd* pParent /*=NULL*/)
	: CDialog(CMenuIcon::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMenuIcon)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMenuIcon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMenuIcon)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMenuIcon, CDialog)
	//{{AFX_MSG_MAP(CMenuIcon)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuIcon message handlers
