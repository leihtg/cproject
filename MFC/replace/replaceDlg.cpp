// replaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "replace.h"
#include "replaceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static UINT WM_FINDMESSAGE=RegisterWindowMessage(FINDMSGSTRING);
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReplaceDlg dialog

CReplaceDlg::CReplaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReplaceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReplaceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReplaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReplaceDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReplaceDlg, CDialog)
	//{{AFX_MSG_MAP(CReplaceDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_replace, Onreplace)
	ON_REGISTERED_MESSAGE(WM_FINDMESSAGE, OnFindReplace)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReplaceDlg message handlers

BOOL CReplaceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReplaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CReplaceDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
 
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CReplaceDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReplaceDlg::Onreplace() 
{
	dlg=new CFindReplaceDialog;
	dlg->Create(FALSE,NULL);
	dlg->ShowWindow(SW_SHOW);	
}
long CReplaceDlg::OnFindReplace(WPARAM wParam,LPARAM lParam){
	CString strText,repText;
	strText=dlg->GetFindString();
	CString str;
	m_Edit.GetWindowText(str);
	if(dlg->ReplaceCurrent()){
		find=FALSE;
	}else{
		find=TRUE;
	}
	int len;
	if(dlg->ReplaceAll()){
		repText=dlg->GetReplaceString();
		len=repText.GetLength();
		str.Replace(strText,repText);
		m_Edit.SetWindowText(str);
	}
	if(find){
		len=strText.GetLength();
	}else{
		CString left,right;
		int num =strText.GetLength();
		int strnum=str.GetLength();
		int index;
		int ret=str.Find(strText,0);
		if(ret<0)return 1;
		if(!degree)index=str.Find(strText,nindex);
		else if(nindex-rindex>=0)
			index=str.Find(strText,nindex-rindex);
		else{
			nindex=rindex;
			return 1;
		}
		degree=TRUE;
		left=str.Left(index);
		right=str.Right(strnum-index-num);
		repText=dlg->GetReplaceString();
		len=repText.GetLength();
		rindex=len;
		str=left+repText+right;
		m_Edit.SetWindowText(str);
	}
	int index=str.Find(strText,nindex);
	m_Edit.SetSel(index,index+len);
	nindex=index+len;
	m_Edit.SetFocus();
	return 0;
}
