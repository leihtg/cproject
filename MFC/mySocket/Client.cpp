// Client.cpp : implementation file
//

#include "stdafx.h"
#include "mySocket.h"
#include "Client.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClient dialog


CClient::CClient(CWnd* pParent /*=NULL*/)
	: CDialog(CClient::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClient)
	m_serverPort = 0;
	m_text = _T("");
	//}}AFX_DATA_INIT
}


void CClient::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClient)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_IPADDRESS1, m_serverIP);
	DDX_Text(pDX, IDC_EDIT2, m_serverPort);
	DDX_Text(pDX, IDC_EDIT3, m_text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClient, CDialog)
	//{{AFX_MSG_MAP(CClient)
	ON_BN_CLICKED(IDC_open, OnOpen)
	ON_BN_CLICKED(IDC_close, OnClose)
	ON_BN_CLICKED(IDC_send, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClient message handlers

void CClient::OnOpen() 
{
	UpdateData();
	BYTE nf1,nf2,nf3,nf4; 
	m_serverIP.GetAddress(nf1,nf2,nf3,nf4); 
	CString ip; 
	ip.Format("%d.%d.%d.%d",nf1,nf2,nf3,nf4);//这里的nf得到的值是IP值了. 

	
		if(m_socket.Connect(ip,m_serverPort)){
			GetDlgItem(IDC_open)->EnableWindow(false);
			GetDlgItem(IDC_close)->EnableWindow(true);
			GetDlgItem(IDC_send)->EnableWindow(true);
		
			CString str;
			str=time.GetCurrentTime().Format("%H:%M:%S");
			m_list.InsertString(0,str+"-成功连接服务器！");
			UpdateData(false);
		}else{
			AfxMessageBox("连接服务器失败！");
		}

}

void CClient::OnClose() 
{
	m_socket.Close();
	CString str=time.GetCurrentTime().Format("%H:%M:%S");
	m_list.InsertString(0,str+"-关闭连接");
	GetDlgItem(IDC_open)->EnableWindow(true);
	GetDlgItem(IDC_close)->EnableWindow(false);
	GetDlgItem(IDC_send)->EnableWindow(false);
}

void CClient::OnSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_socket.Send(m_text,m_text.GetLength());
	CString str=time.GetCurrentTime().Format("%H:%M:%S");
	m_list.InsertString(0,str+"-"+m_text);
}
