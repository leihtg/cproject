// CCritical线程同步Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "CCritical线程同步.h"
#include "CCritical线程同步Dlg.h"
#include <afxmt.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CCriticalSection g_cs;
int g_data=0;
static HANDLE g_ReadHnd;
static HANDLE g_WriteHnd;
UINT ThreadProcWrite(LPVOID param){
	CEdit* pedit=(CEdit*)param;
	while(true){
		CString str;
		g_cs.Lock();
		g_data++;
		str.Format("%d",g_data);
		pedit->SetWindowText(str);
		::Sleep(1000);
		g_cs.Unlock();
		
	}
	return 0;
}
UINT ThreadProcRead(LPVOID param){
	UINT retval;
	CEdit* pedit=(CEdit*)param;
	while(true){
		g_cs.Lock();
		retval=g_data;
		g_cs.Unlock();
		CString str;
		str.Format("%d",retval);
		pedit->SetWindowText(str);
	}
	return 0;
}
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
// CCCriticalDlg dialog

CCCriticalDlg::CCCriticalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCCriticalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCCriticalDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCCriticalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCCriticalDlg)
	DDX_Control(pDX, IDC_EDIT2, m_ReadEdit);
	DDX_Control(pDX, IDC_EDIT1, m_WriteEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCCriticalDlg, CDialog)
	//{{AFX_MSG_MAP(CCCriticalDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnStarw)
	ON_BN_CLICKED(IDC_BUTTON2, OnStopW)
	ON_BN_CLICKED(IDC_BUTTON3, OnStarr)
	ON_BN_CLICKED(IDC_BUTTON4, OnStopr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCCriticalDlg message handlers

BOOL CCCriticalDlg::OnInitDialog()
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

void CCCriticalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCCriticalDlg::OnPaint() 
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
HCURSOR CCCriticalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCCriticalDlg::OnStarw() 
{
	CWinThread* pThread;
	pThread=AfxBeginThread(ThreadProcWrite,&m_WriteEdit);
	g_WriteHnd=pThread->m_hThread;
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(true);
}

void CCCriticalDlg::OnStopW() 
{
	g_cs.Lock();
	TerminateThread(g_WriteHnd,0);
	g_cs.Unlock();
	m_WriteEdit.SetWindowText("终止写线程");
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
}

void CCCriticalDlg::OnStarr() 
{
	CWinThread* pThread;
	pThread=AfxBeginThread(ThreadProcRead,&m_ReadEdit);
	g_ReadHnd=pThread->m_hThread;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
	
}

void CCCriticalDlg::OnStopr() 
{
	g_cs.Lock();
	TerminateThread(g_ReadHnd,0);
	g_cs.Unlock();
	m_ReadEdit.SetWindowText("终止读线程");
	GetDlgItem(IDC_BUTTON3)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
	
}
