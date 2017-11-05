// ScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RegularDll.h"
#include "ScoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg dialog


CScoreDlg::CScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScoreDlg)
	m_score1 = 0.0;
	m_scroe2 = 0.0;
	//}}AFX_DATA_INIT
}


void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoreDlg)
	DDX_Text(pDX, IDC_EDIT1, m_score1);
	DDX_Text(pDX, IDC_EDIT2, m_scroe2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CScoreDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg message handlers

void CScoreDlg::OnCheck() 
{
	if((m_score1*0.45+m_scroe2*0.55)>=65){
		AfxMessageBox("恭喜，你被录取了！");

	}else if(m_scroe2>=85){
		AfxMessageBox("恭喜你，被录取了，文化课需要提高哦！");
	}
	else{
		AfxMessageBox("抱歉，继续努力吧！");
	}
}
