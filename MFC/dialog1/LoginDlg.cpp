// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialog1.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_name = _T("");
	m_password = _T("");
	login_num=0;
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnCheck)
	ON_BN_CLICKED(IDC_BUTTON2, OnCanCel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_name=="gaoshou"&&m_password=="abc"){
		AfxMessageBox("登录成功进入程序！",256);
	}else if(login_num<3){
		AfxMessageBox("用户名和密码设置错误！请重新设置");
		login_num++;
		m_name="";
		m_password="";
		UpdateData(false);
		return;
	}else{
		AfxMessageBox("用户名和密码输入错误三次，已被锁定！");
		AfxGetMainWnd()->PostMessage(WM_QUIT);
		EndDialog(IDCANCEL);
	}
	CDialog::OnOK();


}

void CLoginDlg::OnCanCel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
