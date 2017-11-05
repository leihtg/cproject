// setupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FiveChess.h"
#include "setupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CsetupDlg dialog


CsetupDlg::CsetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CsetupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CsetupDlg)
	m_net_port = 0;
	//}}AFX_DATA_INIT
}


void CsetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CsetupDlg)
	DDX_Control(pDX, IDC_IP_ADDRESS_EDIT, m_ip_addr);
	DDX_Text(pDX, IDC_NET_PORT_EDIT, m_net_port);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CsetupDlg, CDialog)
	//{{AFX_MSG_MAP(CsetupDlg)
	ON_BN_CLICKED(IDC_HOST_OPTION, OnHostOption)
	ON_BN_CLICKED(IDC_CLIENT_OPTION, OnClientOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CsetupDlg message handlers

void CsetupDlg::OnHostOption() 
{
	// TODO: Add your control notification handler code here
	char str[128]={0};
	m_ip_addr.EnableWindow(FALSE);
	GetPrivateProfileString("HOST","IP","",str,127,".\\config.ini");
	m_ip_addr.SetWindowText(str);
	memset(str,0,128);

	GetPrivateProfileString("HOST","PORT","5000",str,127,".\\config.ini");
	m_net_port=atoi(str);
	m_isHost=TRUE;
	UpdateData(FALSE);
}

void CsetupDlg::OnClientOption() 
{
	// TODO: Add your control notification handler code here
	char str[128]={0};
	m_ip_addr.EnableWindow(TRUE);
	GetPrivateProfileString("CLIENT","IP","",str,127,".\\config.ini");
	m_ip_addr.SetWindowText(str);
	memset(str,0,128);

	GetPrivateProfileString("CLIENT","PORT","5000",str,127,".\\config.ini");
	m_net_port=atoi(str);
	m_isHost=FALSE;
	UpdateData(FALSE);
}

void CsetupDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString strIP;
	CString strPort;
	UpdateData(TRUE);
	m_ip_addr.GetWindowText(strIP);
	strPort.Format("%d",m_net_port);
	if(m_isHost){
		WritePrivateProfileString("HOST","PORT",strPort,".\\config.ini");
	}else{
		WritePrivateProfileString("CLIENT","IP",strIP,".\\config.ini");
		WritePrivateProfileString("CLIENT","PORT",strPort,".\\config.ini");
	}
	CDialog::OnOK();
}

void CsetupDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
