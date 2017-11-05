// MsgBoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MsgBox.h"
#include "MsgBoxDlg.h"

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
// CMsgBoxDlg dialog

CMsgBoxDlg::CMsgBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMsgBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMsgBoxDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	i=0;


}

void CMsgBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsgBoxDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMsgBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CMsgBoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnFile)
	ON_BN_CLICKED(IDC_BUTTON2, OnFont)
	ON_BN_CLICKED(IDC_BUTTON3, OnPrint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsgBoxDlg message handlers

BOOL CMsgBoxDlg::OnInitDialog()
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

void CMsgBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMsgBoxDlg::OnPaint() 
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
HCURSOR CMsgBoxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMsgBoxDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CColorDialog dlg(crColor,CC_FULLOPEN);
	if(dlg.DoModal()==IDOK){
		crColor=dlg.GetColor();
		CBrush brush(crColor);
		CClientDC d(AfxGetMainWnd());
		d.SelectObject(&brush);
		d.Ellipse(10,10,200,120);
		
		
		
	}
	
}

void CMsgBoxDlg::OnFile() 
{
	
	CFileDialog dlg(true,".txt","hello.txt",OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,"*.*|*.*||");	
	if(dlg.DoModal()==IDOK){
		CString p=dlg.GetFileName();
		SetWindowText(p);
	}
}

void CMsgBoxDlg::OnFont() 
{
	
	LOGFONT lf;
	memset(&lf,0,sizeof(LOGFONT));
	if(i!=0){
		fnt.GetLogFont(&lf);
	}
	i++;
	CFontDialog dlg(&lf,CF_EFFECTS|CF_SCREENFONTS,0,this);	
	if(dlg.DoModal()==IDOK){
		LOGFONT n;
		dlg.GetCurrentFont(&n);

		fnt.DeleteObject();
		fnt.CreateFontIndirect(&n);
		
		CClientDC dc(this);	
		
		dc.SelectObject(&fnt);
		
		dc.TextOut(100,100,"使用字体对话框");
		
	}
}

void CMsgBoxDlg::OnPrint() 
{
	CPrintDialog dlg(false,PD_PAGENUMS|PD_USEDEVMODECOPIES);
	dlg.m_pd.nMinPage=dlg.m_pd.nFromPage=1;
	dlg.m_pd.nMaxPage=dlg.m_pd.nToPage=10;
	if(dlg.DoModal()==IDOK){
		int from_page,to_page;
		if(dlg.PrintAll()){
			from_page=dlg.m_pd.nMinPage;
			to_page=dlg.m_pd.nMaxPage;
		}
		else if(dlg.PrintRange()){
			from_page=dlg.GetFromPage();
			to_page=dlg.GetToPage();
		}else if(dlg.PrintSelection()){
			from_page=to_page=-1;
		}

	}
}
