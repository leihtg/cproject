// Server.cpp : implementation file
//

#include "stdafx.h"
#include "mySocket.h"
#include "Server.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServer dialog


CServer::CServer(CWnd* pParent /*=NULL*/)
	: CDialog(CServer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServer)
	m_port = 0;
	m_text = _T("");
	//}}AFX_DATA_INIT

}


void CServer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServer)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_port);
	DDX_Text(pDX, IDC_EDIT2, m_text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CServer, CDialog)
	//{{AFX_MSG_MAP(CServer)
	ON_BN_CLICKED(IDC_listen, OnListen)
	ON_BN_CLICKED(IDC_close, OnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServer message handlers

void CServer::OnListen() 
{
	UpdateData();
	if(m_socketListen.Create(m_port,SOCK_STREAM)){
	//	m_socketListen.Bind(m_port);
		if(m_socketListen.Listen()){
			GetDlgItem(IDC_listen)->EnableWindow(false);
			GetDlgItem(IDC_close)->EnableWindow(true);
			GetDlgItem(IDC_send)->EnableWindow(true);

			if(m_socketListen.Accept(m_socket)){
				CString ip;
				UINT port;
				m_socket.GetPeerName(ip,port);
				CString s;
				s.Format("%d",port);
				
				m_list.AddString(ip+":"+s+"-已接入！");
			}
		}
	}else{
		AfxMessageBox("ServerSocket创建失败！");
	}
}

BOOL CServer::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_listen)->EnableWindow(true);
	GetDlgItem(IDC_close)->EnableWindow(false);
	GetDlgItem(IDC_send)->EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CServer::OnClose() 
{
	m_socket.Close();
	GetDlgItem(IDC_listen)->EnableWindow(true);
	GetDlgItem(IDC_close)->EnableWindow(false);
	GetDlgItem(IDC_send)->EnableWindow(false);	
}
