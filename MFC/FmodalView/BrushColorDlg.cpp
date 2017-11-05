// BrushColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FmodalView.h"
#include "BrushColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrushColorDlg dialog


CBrushColorDlg::CBrushColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrushColorDlg::IDD, pParent)
{
	ASSERT(pParent);
	m_pParent=pParent;
	//{{AFX_DATA_INIT(CBrushColorDlg)
	m_red = 0;
	m_green = 0;
	m_blue = 0;
	//}}AFX_DATA_INIT
}


void CBrushColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBrushColorDlg)
	DDX_Text(pDX, IDC_EDIT1, m_red);
	DDV_MinMaxInt(pDX, m_red, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_green);
	DDV_MinMaxInt(pDX, m_green, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_blue);
	DDV_MinMaxInt(pDX, m_blue, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBrushColorDlg, CDialog)
	//{{AFX_MSG_MAP(CBrushColorDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrushColorDlg message handlers
#define WM_SET_COLOR WM_USER+100	
void CBrushColorDlg::OnOK() 
{
	UpdateData();
	m_pParent->SendMessage(WM_SET_COLOR,(WPARAM)this);
}
