// ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"
#include "processdlg.h"
#include "showThread.h"

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
// CChatDlg dialog

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
: CDialog(CChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialog)
	//{{AFX_MSG_MAP(CChatDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_RECVDATA, recvData)
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	ON_COMMAND(id_sendfile, Onsendfile)
	ON_UPDATE_COMMAND_UI(id_sendfile, OnUpdatesendfile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDlg message handlers

BOOL CChatDlg::OnInitDialog()
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
	InitSocket();
	RecvMsg *msg = new RecvMsg;
	msg->hwnd = m_hWnd;
	msg->socket = m_socket;
	HANDLE hThread = CreateThread(NULL, 0, RecvProc, (LPVOID)msg, 0, NULL);
	CloseHandle(hThread);

	((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->SetAddress(htonl(GetIP()));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

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
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

BOOL CChatDlg::InitSocket()
{
	m_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == m_socket){
		AfxMessageBox(L"创建socket失败！");
		return false;
	}
	SOCKADDR_IN addrSock;
	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(6666);
	addrSock.sin_addr.S_un.S_addr = INADDR_ANY;

	int ret = bind(m_socket, (SOCKADDR*)&addrSock, sizeof(SOCKADDR));
	if (ret == SOCKET_ERROR){
		AfxMessageBox(L"绑定socket失败！");
		return false;
	}

	return true;


}

DWORD WINAPI CChatDlg::RecvProc(LPVOID lp)
{
	RecvMsg* rm = (RecvMsg*)lp;
	SOCKET s = rm->socket;
	HWND h = rm->hwnd;

	SOCKADDR_IN addr;
	int len = sizeof(addr);

	char recvBuf[1024];
	char tempBuf[1100];
	memset(recvBuf, 0, sizeof(recvBuf));
	memset(tempBuf, 0, sizeof(tempBuf));
	int retval;
	while (true){
		retval = recvfrom(s, recvBuf, sizeof(recvBuf), 0, (SOCKADDR*)&addr, &len);
		if (SOCKET_ERROR == retval){
			break;
		}
		sprintf(tempBuf, "%s说：%s", inet_ntoa(addr.sin_addr), recvBuf);
		::PostMessage(h, WM_RECVDATA, 0, (LPARAM)tempBuf);
	}
	return 0;
}
LRESULT CChatDlg::recvData(WPARAM wp, LPARAM lp){
	CString msg = (char*)lp;
	CString temp;
	CEdit *ce = (CEdit*)GetDlgItem(IDC_EDIT_RECV);
	GetDlgItemText(IDC_EDIT_RECV, temp);
	temp += msg + "\r\n";
	SetDlgItemText(IDC_EDIT_RECV, temp);

	ce->LineScroll(ce->GetLineCount());
	return 0;
}

void CChatDlg::OnBtnSend()
{
	DWORD adds;
	((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->GetAddress(adds);
	SOCKADDR_IN addrTo;
	addrTo.sin_family = AF_INET;
	addrTo.sin_port = htons(6666);
	addrTo.sin_addr.S_un.S_addr = htonl(adds);

	CString strSend;
	GetDlgItemText(IDC_EDIT_SEND, strSend);
	int size = WideCharToMultiByte(CP_ACP, 0, strSend, -1, NULL, 0, NULL, NULL);
	if (size <= 1)return;
	char* ch = new char[size + 1];
	WideCharToMultiByte(CP_ACP, 0, strSend, -1, ch, size, NULL, NULL);
	sendto(m_socket, ch, size, 0, (SOCKADDR*)&addrTo, sizeof(SOCKADDR));
	SetDlgItemText(IDC_EDIT_SEND, _T(""));
}
DWORD CChatDlg::GetIP(){
	char name[256];
	gethostname(name, sizeof(name));
	HOSTENT *ht = gethostbyname(name);
	char* lpAddr = ht->h_addr_list[0];
	in_addr inAddr;
	memcpy(&inAddr, lpAddr, sizeof(inAddr));
	return inet_addr(inet_ntoa(inAddr));
}

void CChatDlg::Onsendfile()
{
	CWinThread *pThread = AfxBeginThread(RUNTIME_CLASS(CShowThread), 0, 0, NULL);
}

void CChatDlg::OnUpdatesendfile(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(true);
}
