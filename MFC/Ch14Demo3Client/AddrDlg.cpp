// AddrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ch14Demo3Client.h"
#include "AddrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddrDlg dialog


CAddrDlg::CAddrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddrDlg)
	m_Addr = _T("");
	//}}AFX_DATA_INIT
}


void CAddrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddrDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Addr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddrDlg, CDialog)
	//{{AFX_MSG_MAP(CAddrDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddrDlg message handlers


void CAddrDlg::OnOk() 
{
	CDialog::OnOK();	
}
