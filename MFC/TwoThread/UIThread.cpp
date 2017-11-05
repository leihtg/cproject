// UIThread.cpp : implementation file
//

#include "stdafx.h"
#include "TwoThread.h"
#include "UIThread.h"
#include "UIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUIThread

IMPLEMENT_DYNCREATE(CUIThread, CWinThread)

CUIThread::CUIThread()
{
}

CUIThread::~CUIThread()
{
}

BOOL CUIThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	CUIDlg *dlg=new CUIDlg;
	dlg->Create(IDD_DIALOG1);
	dlg->ShowWindow(SW_SHOW);
	m_pMainWnd=dlg;
	return TRUE;
}

int CUIThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	if(m_pMainWnd!=NULL){
		delete m_pMainWnd;
	}
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUIThread, CWinThread)
	//{{AFX_MSG_MAP(CUIThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUIThread message handlers
