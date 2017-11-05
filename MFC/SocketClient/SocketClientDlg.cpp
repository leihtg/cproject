// SocketClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SocketClient.h"
#include "SocketClientDlg.h"

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
// CSocketClientDlg dialog

CSocketClientDlg::CSocketClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSocketClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSocketClientDlg)
	m_ClinetIp = _T("");
	m_ClientPort = 0;
	m_ServerIp = _T("");
	m_ServerPort = 0;
	m_data = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSocketClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSocketClientDlg)
	DDX_Text(pDX, IDC_EDIT1, m_ClinetIp);
	DDX_Text(pDX, IDC_EDIT2, m_ClientPort);
	DDX_Text(pDX, IDC_EDIT3, m_ServerIp);
	DDX_Text(pDX, IDC_EDIT4, m_ServerPort);
	DDX_Text(pDX, IDC_EDIT5, m_data);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSocketClientDlg, CDialog)
	//{{AFX_MSG_MAP(CSocketClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnReceive)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSocketClientDlg message handlers

BOOL CSocketClientDlg::OnInitDialog()
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

void CSocketClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSocketClientDlg::OnPaint() 
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
HCURSOR CSocketClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSocketClientDlg::OnReceive() 
{
	UpdateData();
	if(m_sockReceive.Create(m_ClientPort,SOCK_DGRAM,NULL)){
		m_sockReceive.Bind(m_ClientPort,m_ClinetIp);
		SetTimer(1,2000,NULL);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(true);

	}else{
		AfxMessageBox("Socket����ʧ�ܣ�");
	}
}

void CSocketClientDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	char szRecv[20];
	int iRecv=m_sockReceive.ReceiveFrom(szRecv,10,m_ServerIp,m_ServerPort,0);
	if(iRecv==-1){
		m_data="û�н��յ����ݣ�";

	}else{
		szRecv[iRecv]=NULL;
		m_data=szRecv;
	}
	UpdateData(false);
	CDialog::OnTimer(nIDEvent);
}

void CSocketClientDlg::OnStop() 
{
	KillTimer(1);
	m_sockReceive.Close();
	m_data="ֹͣ�������ݣ�";
	UpdateData(false);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
}