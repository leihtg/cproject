// ThreadDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadDemo.h"
#include "ThreadDemoDlg.h"

#ifdef _DEBUG 
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CThreadDemoDlg dialog

CThreadDemoDlg::CThreadDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadDemoDlg)
	DDX_Control(pDX, IDC_PROGRESS3, m_progress3);
	DDX_Control(pDX, IDC_PROGRESS2, m_progress2);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(s1, OnStart1)
	ON_BN_CLICKED(s2, Ons2)
	ON_BN_CLICKED(s3, Ons3)
	ON_BN_CLICKED(p1, Onp1)
	ON_BN_CLICKED(p2, Onp2)
	ON_BN_CLICKED(p3, Onp3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadDemoDlg message handlers

BOOL CThreadDemoDlg::OnInitDialog()
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
	m_progress1.SetRange(0,200);
	m_progress2.SetRange(0,200);
	m_progress3.SetRange(0,200);
	GetDlgItem(p1)->EnableWindow(false);
	GetDlgItem(p2)->EnableWindow(false);
	GetDlgItem(p3)->EnableWindow(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CThreadDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThreadDemoDlg::OnPaint() 
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
HCURSOR CThreadDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
DWORD WINAPI ThreadFun(LPVOID pthread){
	lpthread temp=(lpthread)pthread;
	temp->progress->SetPos(temp->pos);
	while(temp->pos<200){
		Sleep(temp->speed);
		temp->pos++;
		temp->progress->SetPos(temp->pos);
		if(temp->pos==200){
			temp->pos=0;
		}
	}
	return true;
}

void CThreadDemoDlg::OnStart1() 
{
	DWORD ThreadID;
	DWORD code;
	thread1.progress=&m_progress1;
	thread1.speed=50;
	thread1.pos=0;
	if(!GetExitCodeThread(hThread1,&code)||(code!=STILL_ACTIVE)){
		hThread1=CreateThread(NULL,0,ThreadFun,&thread1,0,&ThreadID);
	}
	GetDlgItem(p1)->EnableWindow(true);
	GetDlgItem(s1)->EnableWindow(false);
}

void CThreadDemoDlg::Ons2() 
{
	// TODO: Add your control notification handler code here
	DWORD ThreadID;
	DWORD code;
	thread2.progress=&m_progress2;
	thread2.speed=50;
	thread2.pos=0;
	if(!GetExitCodeThread(hThread2,&code)||(code!=STILL_ACTIVE)){
		hThread2=CreateThread(NULL,0,ThreadFun,&thread2,0,&ThreadID);
	}
	GetDlgItem(p2)->EnableWindow(true);
	GetDlgItem(s2)->EnableWindow(false);
}

void CThreadDemoDlg::Ons3() 
{
	DWORD ThreadID;
	DWORD code;
	thread3.progress=&m_progress3;
	thread3.speed=50;
	thread3.pos=0;
	if(!GetExitCodeThread(hThread3,&code)||(code!=STILL_ACTIVE)){
		hThread3=CreateThread(NULL,0,ThreadFun,&thread3,0,&ThreadID);
	}
	GetDlgItem(p3)->EnableWindow(true);
	GetDlgItem(s3)->EnableWindow(false);	
}

void CThreadDemoDlg::Onp1() 
{
	DWORD code;
	if(GetExitCodeThread(hThread1,&code)){
		if(code==STILL_ACTIVE){
			TerminateThread(hThread1,0);
			CloseHandle(hThread1);
		}
		
	}
	GetDlgItem(p1)->EnableWindow(false);
	GetDlgItem(s1)->EnableWindow(true);
}

void CThreadDemoDlg::Onp2() 
{
	// TODO: Add your control notification handler code here
	DWORD code;
	if(GetExitCodeThread(hThread2,&code)){
		if(code==STILL_ACTIVE){
			TerminateThread(hThread2,0);
			CloseHandle(hThread2);
		}
		
	}
	GetDlgItem(p2)->EnableWindow(false);
	GetDlgItem(s2)->EnableWindow(true);	
}

void CThreadDemoDlg::Onp3() 
{
	DWORD code;
	if(GetExitCodeThread(hThread3,&code)){
		if(code==STILL_ACTIVE){
			TerminateThread(hThread3,0);
			CloseHandle(hThread3);
		}
		
	}
	GetDlgItem(p3)->EnableWindow(false);
	GetDlgItem(s3)->EnableWindow(true);	
}
