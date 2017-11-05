// MySocket.cpp: implementation of the CMySocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TCPServer.h"
#include "MySocket.h"
#include "TCPServerDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMySocket::CMySocket()
{

}

CMySocket::~CMySocket()
{

}

void CMySocket::setParent(CDialog *pDlg){
	m_pDlg=(CTCPServerDlg*)pDlg;
}

void CMySocket::OnAccept(int nErrorCode){
	if(nErrorCode==0){
		((CTCPServerDlg*)m_pDlg)->OnAccept();
	}
}

void CMySocket::OnConnect(int nErrorCode){

}

void CMySocket::OnReceive(int nErrorCode){
	((CTCPServerDlg*)m_pDlg)->OnReceive();
}

void CMySocket::OnClose(int nErrorCode){
	((CTCPServerDlg*)m_pDlg)->OnClose();
}