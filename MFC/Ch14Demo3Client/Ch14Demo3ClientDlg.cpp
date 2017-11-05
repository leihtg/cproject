// Ch14Demo3ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ch14Demo3Client.h"
#include "Ch14Demo3ClientDlg.h"

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
// CCh14Demo3ClientDlg dialog

CCh14Demo3ClientDlg::CCh14Demo3ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCh14Demo3ClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCh14Demo3ClientDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCh14Demo3ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCh14Demo3ClientDlg)
	DDX_Control(pDX, IDC_EDIT1, m_MsgS);
	DDX_Control(pDX, IDC_LIST1, m_MsgR);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCh14Demo3ClientDlg, CDialog)
	//{{AFX_MSG_MAP(CCh14Demo3ClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnConnect)
	ON_BN_CLICKED(IDC_BUTTON2, OnSend)
	ON_BN_CLICKED(IDC_BUTTON3, OnClose)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCh14Demo3ClientDlg message handlers

BOOL CCh14Demo3ClientDlg::OnInitDialog()
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

void CCh14Demo3ClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCh14Demo3ClientDlg::OnPaint() 
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
HCURSOR CCh14Demo3ClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCh14Demo3ClientDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	m_clientSocket.ShutDown(2);
	m_clientSocket.m_hSocket=INVALID_SOCKET;
	m_clientSocket.m_bConnected=FALSE;
	CAddrDlg m_Dlg;
	m_szPort=8080;

	if(m_Dlg.DoModal()==1&&!m_Dlg.m_Addr.IsEmpty()){
	
		memcpy(m_szServerAdr,m_Dlg.m_Addr,sizeof(m_szServerAdr));
	
		SetTimer(1,1000,NULL);
	
		TryCount=0;
		m_MsgS.SetWindowText("正在连接……");
	}else if(m_Dlg.m_Addr.IsEmpty()){
		AfxMessageBox("地址不能为空！");
		return ;
	}
	
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);

}

void CCh14Demo3ClientDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	if(m_clientSocket.m_bConnected){
		m_clientSocket.m_nLength=m_MsgS.GetWindowText(m_clientSocket.m_szBuffer,sizeof(m_clientSocket.m_szBuffer));
		m_clientSocket.AsyncSelect(FD_WRITE);
		m_MsgS.SetWindowText("");
	}
}

void CCh14Demo3ClientDlg::OnClose() 
{
	// TODO: Add your control notification handler code here
	m_clientSocket.ShutDown(2);
	EndDialog(0);
}

void CCh14Demo3ClientDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	if(m_clientSocket.m_hSocket==INVALID_SOCKET){
		BOOL bFlag=m_clientSocket.Create(0,SOCK_STREAM,FD_CONNECT);
		if(!bFlag){
			AfxMessageBox("Socket创建错误！");
			m_clientSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
	m_clientSocket.Connect(m_szServerAdr,m_szPort);
	TryCount++;
	if(TryCount>=10||m_clientSocket.m_bConnected){
		KillTimer(1);
		if(TryCount>=10){
			AfxMessageBox("连接失败！");
			GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
		}
		return;
	}
	CDialog::OnTimer(nIDEvent);
}
