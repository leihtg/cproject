// MyExcelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyExcel.h"
#include "MyExcelDlg.h"
#include "excel.h"


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
// CMyExcelDlg dialog

CMyExcelDlg::CMyExcelDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMyExcelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyExcelDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyExcelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyExcelDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyExcelDlg, CDialog)
//{{AFX_MSG_MAP(CMyExcelDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
ON_WM_DROPFILES()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyExcelDlg message handlers

BOOL CMyExcelDlg::OnInitDialog()
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

void CMyExcelDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyExcelDlg::OnPaint() 
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
HCURSOR CMyExcelDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyExcelDlg::OnButton1() 
{
	//Workbooks—>Workbook —>Worksheets—>Worksheet —>Range
	_Application app;		//Excel应用程序接口
	Workbooks books;		//工作薄集合
	_Workbook book;		//工作薄
	Worksheets sheets;		//工作表集合
	_Worksheet sheet;		//工作表
	Range range;			//Excel中针对单元格的操作都应先获取其对应的Range对象
	Font font;
	Range cols;
	/*
	COleVariant类为VARIANT数据类型的包装，在自动化程序中，通常都使用
	VARIANT数据类型进行参数传递。故下列程序中，函数参数都是通过COleVariant
	类来转换了的。
	*/
	//covOptional 可选参数的VARIANT类型
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	if( !app.CreateDispatch("Excel.Application") ){
		this->MessageBox("无法创建Excel应用！");
		return;
	}
	//获取工作薄集合
	books=app.GetWorkbooks();
	//添加一个工作薄
	book=books.Add(covOptional);
	//获取工作表集合
	sheets=book.GetSheets();
	//获取第一个工作表
	sheet=sheets.GetItem(COleVariant((short)1));
	//选择工作表中A1:A1单元格区域
	range=sheet.GetRange(COleVariant("A1"),COleVariant("D1"));
	//设置A1=HELLO EXCEL!"
	range.SetValue2(COleVariant("HELLO EXCEL!"));
	//调整格式，设置粗体
	font=range.GetFont();
	font.SetBold(COleVariant((short)TRUE));
	//选择A2单元格，插入一个公式"=RAND()*100000"，并设置A2数字格式为货币形式
	range=sheet.GetRange(COleVariant("A2"),COleVariant("A2"));
	range.SetFormula(COleVariant("=RAND()*100000"));
	range.SetNumberFormat(COleVariant("$0.00"));
	//选择A:A列，设置宽度为自动适应
	cols=range.GetEntireColumn();
	cols.AutoFit();
	//显示Excel表格，并设置状态为用户可控制
	app.SetVisible(TRUE);
	app.SetUserControl(TRUE);
	

}

void CMyExcelDlg::OnDropFiles(HDROP hDropInfo){
	char szFileName[200];
	int iFileNumber;
	iFileNumber=DragQueryFile(hDropInfo,0xFFFFFFFF,NULL,0);
	for(int i=0;i<iFileNumber;i++){
		DragQueryFile(hDropInfo,i,szFileName,200);
		if(m_list.FindString(0,szFileName)!=LB_ERR)continue;
		m_list.AddString(szFileName);
	}
}

void CMyExcelDlg::OnButton2() 
{
	_Application app;		//Excel应用程序接口
	Workbooks books;		//工作薄集合
		_Workbook book;		//工作薄

	CString strPath; 
	strPath += "C:\\Users\\Thinkpad\\Desktop\\Book5.xls"; // 模板的路径 
	CFileFind filefind; 
	if( !filefind.FindFile(strPath) ) 
	{ 
		AfxMessageBox( "没有找到模版文档，请其查找" ); 
		return;
	} 
	LPDISPATCH lpDisp; 	//接口指针
	books=app.GetWorkbooks();
	COleVariant covOptional;
	lpDisp = books.Open(strPath,
		covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional, covOptional, covOptional,
		covOptional, covOptional
		);					//与的不同，是个参数的，直接在后面加了两个covOptional成功了
	book.AttachDispatch(lpDisp);	
}
