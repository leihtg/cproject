// TCPServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TCPServer.h"
#include "TCPServerDlg.h"

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
// CTCPServerDlg dialog

CTCPServerDlg::CTCPServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTCPServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTCPServerDlg)
	m_szRecv = _T("");
	m_szSend = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTCPServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCPServerDlg)
	DDX_Text(pDX, IDC_EDIT1, m_szRecv);
	DDX_Text(pDX, IDC_EDIT2, m_szSend);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTCPServerDlg, CDialog)
	//{{AFX_MSG_MAP(CTCPServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnSend)
	ON_BN_CLICKED(IDC_BUTTON1, OnAcceptBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPServerDlg message handlers

BOOL CTCPServerDlg::OnInitDialog()
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
	
	m_sockListen.setParent(this);
	m_sockServer.setParent(this);
	m_sockListen.Create(10000);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTCPServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTCPServerDlg::OnPaint() 
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
HCURSOR CTCPServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTCPServerDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int nSendLen=m_sockServer.Send((void*)m_szSend.GetBuffer(0),m_szSend.GetLength());
	if(nSendLen>0){
		AfxMessageBox("发送成功！");

	}else{
		AfxMessageBox("发送失败!");
	}
	
}

void CTCPServerDlg::OnAcceptBtn() 
{
	// TODO: Add your control notification handler code here
	m_sockListen.Listen();
}

void CTCPServerDlg::OnAccept(){
	SOCKADDR sockAddr;
	int nSockAddrLen=sizeof(SOCKADDR);
	CString tmp;
	if(m_sockListen.Accept(m_sockServer,&sockAddr,&nSockAddrLen)){
		tmp.Format("有客户端连接，来自%d.%d.%d.%d\r\n",(UCHAR)sockAddr.sa_data[2],(UCHAR)sockAddr.sa_data[3],(UCHAR)sockAddr.sa_data[4],(UCHAR)sockAddr.sa_data[5]);
		m_szRecv+=tmp;
		UpdateData(FALSE);
	}
}

void CTCPServerDlg::OnReceive(){
	BYTE byBuf[1024]={0};
	int nRecvLen=0;
	nRecvLen=m_sockServer.Receive(byBuf,sizeof(byBuf));
	CString tmp;
	if(nRecvLen>0){
		UpdateData();
		tmp.Format("%s\r\n",byBuf);
		m_szRecv+=tmp;
		UpdateData(FALSE);
	}else{
		AfxMessageBox("收到的数据有问题!");
	}
}

void CTCPServerDlg::OnClose(){
	UpdateData();
	m_sockServer.Close();
}
