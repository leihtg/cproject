
// simpleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "simple.h"
#include "simpleDlg.h"
#include "afxdialogex.h"
#include "RegHandle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CsimpleDlg 对话框



CsimpleDlg::CsimpleDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CsimpleDlg::IDD, pParent), name(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsimpleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PATH, name);
	DDV_MaxChars(pDX, name, 255);
	DDX_Control(pDX, IDC_PATHS, paths);
}

BEGIN_MESSAGE_MAP(CsimpleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//	ON_WM_DROPFILES()
	//	ON_WM_HELPINFO()
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CsimpleDlg 消息处理程序

BOOL CsimpleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CsimpleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CsimpleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CsimpleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CsimpleDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN){
		if (pMsg->wParam == VK_RETURN&&GetDlgItem(IDC_PATH) == GetFocus()){
			UpdateData(TRUE);
			while (paths.GetCount()){
				paths.DeleteString(0);
			}
			CRegHandle cReg;
			CString str = cReg.queryKey(name);
			int start = 0;
			int pos = 0;
			while ((pos = str.Find(_T(";"), start)) != -1)
			{
				paths.InsertString(0, str.Mid(start, pos - start));
				start = pos + 1;
			}
			str = str.Mid(start);
			if (str != _T("")){
				paths.InsertString(0, str);
			}

		}
		if (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN){
			return true;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CsimpleDlg::OnDropFiles(HDROP hDropInfo)
{
	TCHAR szFileName[MAX_PATH];
	int iFileNumber;

	// 得到拖拽操作中的文件个数
	iFileNumber = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	for (int i = 0; i < iFileNumber; i++)
	{
		// 得到每个文件名
		DragQueryFile(hDropInfo, i, szFileName, MAX_PATH);

		/*if (FindString(0, szFileName) != LB_ERR)
		continue;*/

		// 把文件名添加到list中
		paths.InsertString(0, szFileName);
	}
	DragFinish(hDropInfo);
}
