// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Ch14Demo3Client.h"
#include "ClientSocket.h"
#include "Ch14Demo3ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
	m_nLength=0;
	memset(m_szBuffer,0,sizeof(m_szBuffer));
	m_bConnected=FALSE;
}

CClientSocket::~CClientSocket()
{
	if(m_hSocket!=INVALID_SOCKET){
		Close();
	}
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0){
		m_bConnected=TRUE;
		CCh14Demo3ClientApp* pApp=(CCh14Demo3ClientApp*)AfxGetApp();
		CCh14Demo3ClientDlg* pDlg=(CCh14Demo3ClientDlg*)pApp->m_pMainWnd;
		memcpy(m_szBuffer,"Á¬½Óµ½£º",13);
		strncat(m_szBuffer,pDlg->m_szServerAdr,sizeof(pDlg->m_szServerAdr));
		pDlg->m_MsgR.InsertString(0,m_szBuffer);
		pDlg->GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
		AsyncSelect(FD_READ);
	}
	CAsyncSocket::OnConnect(nErrorCode);
}

void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_nLength=Receive(m_szBuffer,sizeof(m_szBuffer),0);
	
	CCh14Demo3ClientApp* pApp=(CCh14Demo3ClientApp*)AfxGetApp();
	CCh14Demo3ClientDlg* pDlg=(CCh14Demo3ClientDlg*)pApp->m_pMainWnd;
	pDlg->m_MsgR.InsertString(0,m_szBuffer);
	memset(m_szBuffer,0,sizeof(m_szBuffer));


	CAsyncSocket::OnReceive(nErrorCode);
}

void CClientSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	Send(m_szBuffer,m_nLength,0);
	m_nLength=0;
	memset(m_szBuffer,0,sizeof(m_szBuffer));
	AsyncSelect(FD_READ);
	CAsyncSocket::OnSend(nErrorCode);
}
