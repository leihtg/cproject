// 多线程Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "多线程.h"
#include "多线程Dlg.h"

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
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_url = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Text(pDX, IDC_EDIT1, m_url);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
//{{AFX_MSG_MAP(CMyDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, OnDownLoad)
ON_MESSAGE(M_P,showProgress)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
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
	m_progress.SetRange(0,1000);
	m_url="http://pic1.win4000.com/wallpaper/c/53d715bd3a34b.jpg";
	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlg::OnPaint() 
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
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
int pos=0;
UINT downloadFile(LPVOID pthread){//DWORD WINAPI
	pThread info=(pThread)pthread;
	CInternetFile* webfile=info->webfile;
	CFile file(info->filePath,CFile::modeCreate|CFile::modeWrite);
	
	char tmp[2048];
	int i=0;
	int ps,pe;
	info->progress->GetRange(ps,pe);
	long size=0,totalSize=webfile->SeekToEnd();
	webfile->SeekToBegin();
	
	int pos=0;
	while((i=webfile->Read(tmp,sizeof(tmp)))!=0){
		file.Write(tmp,i);
		//file.Flush();
		size=file.GetLength();
		pos=(int)((float)size*pe/(float)totalSize);
		
	//	info->progress->SetPos(pos);
	::PostMessage(info->hwnd,M_P,pos,0);
	}
	webfile->Close();
	file.Flush();
	file.Close();
	return 0;
}
void CMyDlg::OnDownLoad() 
{
	pos=0;
	UpdateData();
	CInternetFile *webfile=(CInternetFile*)session.OpenURL(m_url);
	CString name=webfile->GetFileName();
	CFileDialog dialog(FALSE,"",name,OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,"图片 (*.jpg)|*.jpg|全部 (*.*)|*.*||",this);
	if(dialog.DoModal()==IDOK){
		thread.filePath=dialog.GetPathName();
		thread.url=m_url;
		thread.webfile=webfile;
		thread.progress=&m_progress;
		
		thread.hwnd=GetSafeHwnd();
//		DWORD threadId;
		//CreateThread(NULL,0,downloadFile,&thread,0,&threadId);
		//CreateThread(NULL,0,showProgress,&m_progress,0,&abc);
	    //AfxBeginThread(showProgress,&m_progress);
		AfxGetApp()->m_bAutoDelete=TRUE;
		AfxBeginThread(downloadFile,&thread);
	}
}
void CMyDlg::showProgress(WPARAM w,LPARAM lp){
	int p=(int)w;
	m_progress.SetPos(p);
}
