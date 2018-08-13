
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
	DDX_Control(pDX, IDC_USER_LIST, m_userList);
}

BEGIN_MESSAGE_MAP(CsimpleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	ON_COMMAND(IDM_DELETE, &CsimpleDlg::OnDelete)
	ON_MESSAGE(WM_RECEIVEBROCAST, &CsimpleDlg::OnReceivebrocast)
	ON_BN_CLICKED(IDC_BUTTON1, &CsimpleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CsimpleDlg::OnBnClickedButton2)
	ON_MESSAGE(MM_WIM_DATA, &CsimpleDlg::OnMmWimData)
	ON_MESSAGE(WIM_DATA, &CsimpleDlg::OnWimData)
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
	ChangeWindowMessageFilter(WM_SETTINGCHANGE, MSGFLT_ADD);
	ChangeWindowMessageFilter(WM_DROPFILES, MSGFLT_ADD);
	ChangeWindowMessageFilter(0x0049, MSGFLT_ADD); //0x0049==WM_COPYGLOBALDATA
	// ::DragAcceptFiles(m_hWnd, TRUE); // 对话框程序可在其【属性】-【行为】-【Accept Files】置为【True】，而不用调用此行。反之则可，两者可选其一嘛~~~

	m_userList.InsertColumn(0, _T("用户"),LVCFMT_LEFT,100);
	//::SendMessage(m_userList.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);
	InitBroadSocket();
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
				paths.AddString(str.Mid(start, pos - start));
				start = pos + 1;
			}
			str = str.Mid(start);
			if (str != _T("")){
				paths.AddString(str);
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
		paths.AddString(szFileName);
	}
	DragFinish(hDropInfo);
	doSetKey();
}


void CsimpleDlg::OnDelete()
{
	// TODO:  在此添加命令处理程序代码
	int index = paths.GetCurSel();
	CString str;
	paths.GetText(index, str);
	str.Insert(0, _T("确定删除:\n"));

	int ret = MessageBox(str, _T("提示"), MB_OKCANCEL | MB_ICONWARNING);
	if (IDOK == ret){
		paths.DeleteString(index);
		doSetKey();
	}
}

void CsimpleDlg::doSetKey(){
	UpdateData(TRUE);
	if (name == _T("")){
		return;
	}
	CRegHandle reg;
	CString str;

	BOOL flag = reg.setKey(name, paths);
	str.Format(_T("环境变量[%s]设置[%s]"), name, flag ? _T("成功") : _T("失败"));
	MessageBox(str);
}

void CsimpleDlg::InitBroadSocket(){
	broadcast = socket(AF_INET, SOCK_DGRAM, 0);
	if (broadcast == INVALID_SOCKET)
	{
		MessageBox(_T("创建socket失败"), _T("联网失败"), MB_OK);
		return;
	}
	u_long flag = 0;
	if (SOCKET_ERROR == ioctlsocket(broadcast, FIONBIO, &flag)){
		MessageBox(_T("设置socket阻塞失败"), _T("联网失败"), MB_OK);
		return;
	}
	SOCKADDR_IN local;
	local.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	local.sin_family = AF_INET;
	local.sin_port = htons(7777);

	//bool optVal = true;
	//if (SOCKET_ERROR == setsockopt(broadcast, SOL_SOCKET, SO_BROADCAST, (const char*)&optVal, sizeof(optVal))){
	//	MessageBox(_T("设置socket广播失败"), _T("联网失败"), MB_OK);
	//	return;
	//}

	if (SOCKET_ERROR == bind(broadcast, (sockaddr*)&local, sizeof(local))){
		MessageBox(_T("绑定socket失败"), _T("联网失败"), MB_OK);
		return;
	}



	//创建线程
	RECVPARAM* param = new RECVPARAM;
	param->socket = broadcast;
	param->hWnd = this->m_hWnd;
	CreateThread(NULL, NULL, recvFromProc, (LPVOID*)param, NULL, NULL);
}

DWORD WINAPI CsimpleDlg::recvFromProc(LPVOID lpParameter){
	RECVPARAM* param = (RECVPARAM*)lpParameter;
	SOCKET s = param->socket;
	HWND hwnd = param->hWnd;
	delete param;
	char buf[1024] = { 0 };
	SOCKADDR_IN from;
	int len = sizeof(from), ret = 0;
	while (true){
		ret = recvfrom(s, buf, sizeof(buf), NULL, (sockaddr*)&from, &len);
		if (ret == SOCKET_ERROR){
			//出错
			ret = WSAGetLastError();
			CString str;
			str.Format(_T("recvFrom错误[%d]"), ret);
			::MessageBox(hwnd, str, NULL, NULL);
			break;
		}
		else if (ret == 0)
		{
			//正常关闭
			continue;
		}
		memset(buf + ret, NULL, 2);
		::PostMessage(hwnd, WM_RECEIVEBROCAST, (WPARAM)&from, (LPARAM)buf);

	}
	return -1;
}

afx_msg LRESULT CsimpleDlg::OnReceivebrocast(WPARAM wParam, LPARAM lParam)
{
	LPCCH msg = (LPCCH)lParam;
	int len = MultiByteToWideChar(CP_ACP, 0, msg, strlen(msg), NULL, 0);
	//为宽字节字符数组申请空间，数组大小为按字节计算的多字节字符大小
	TCHAR *buf = new TCHAR[len];
	MultiByteToWideChar(CP_ACP, 0, msg, strlen(msg), buf, len);

	SOCKADDR_IN* addr = (SOCKADDR_IN*)wParam;
	char* host = inet_ntoa(addr->sin_addr);
	USHORT port = ntohs(addr->sin_port);
	CString str;
	str.Format(_T("%s[%d]:\t%s\n"), CString(host), port, CString(buf, len));
	paths.InsertString(0, str);
	return 0;
}


void CsimpleDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CSoundRecord record(m_hWnd);
	record.beginRecord();
}


void CsimpleDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CSoundRecord record(m_hWnd);
	record.soundPlay();
}


afx_msg LRESULT CsimpleDlg::OnMmWimData(WPARAM wParam, LPARAM lParam)
{
	
	MessageBox(_T("hehe"));
	return 0;
}


afx_msg LRESULT CsimpleDlg::OnWimData(WPARAM wParam, LPARAM lParam)
{
	MessageBox(_T("full"));
	return 0;
}
