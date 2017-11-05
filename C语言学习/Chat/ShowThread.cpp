// ShowThread.cpp : implementation file
//

#include "stdafx.h"
#include "Chat.h"
#include "ShowThread.h"
#include "ProcessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowThread

IMPLEMENT_DYNCREATE(CShowThread, CWinThread)

CShowThread::CShowThread()
{
}

CShowThread::~CShowThread()
{
}

BOOL CShowThread::InitInstance()
{
	CProcessDlg *pDlg=new CProcessDlg();
	pDlg->Create(IDD_DIALOG1);
	pDlg->ShowWindow(SW_SHOW);
	m_pMainWnd=pDlg;//将对话框设置为主窗口
	return TRUE;
}

int CShowThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	if(NULL!=m_pMainWnd){
		delete m_pMainWnd;
	}
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CShowThread, CWinThread)
	//{{AFX_MSG_MAP(CShowThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowThread message handlers
