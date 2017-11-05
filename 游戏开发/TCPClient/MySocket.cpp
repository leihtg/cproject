// MySocket.cpp: implementation of the CMySocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TCPClient.h"
#include "TCPClientDlg.h"
#include "MySocket.h"

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

void CMySocket::SetParent(CDialog *pDlg){
	m_pDlg=(CTCPClientDlg*)pDlg;
}
void CMySocket::OnReceive(int errCode){
	((CTCPClientDlg*)m_pDlg)->OnReceive();
}
void CMySocket::OnClose(int errCode){
	((CTCPClientDlg*)m_pDlg)->OnCls();
}
