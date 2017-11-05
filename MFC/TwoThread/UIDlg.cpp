// UIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TwoThread.h"
#include "UIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUIDlg dialog


CUIDlg::CUIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUIDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUIDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUIDlg, CDialog)
	//{{AFX_MSG_MAP(CUIDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnStart)
	ON_BN_CLICKED(IDC_BUTTON2, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUIDlg message handlers

void CUIDlg::OnStart() 
{
	for(int i=0;i<=100;i++){
		m_progress.SetPos(i);
		Sleep(200);
	}
	OnOk();
}


BOOL CUIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_progress.SetRange(0,100);
	return TRUE;
}

void CUIDlg::OnOk() 
{
	CDialog::OnOK();	
}
