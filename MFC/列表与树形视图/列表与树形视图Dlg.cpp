// 列表与树形视图Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "列表与树形视图.h"
#include "列表与树形视图Dlg.h"

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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGING, IDC_LIST1, OnItemchangingList1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
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
	m_ImageList.Create(IDB_BITMAP1,16,4,RGB(12,34,56));
	m_list.SetImageList(&m_ImageList,LVSIL_SMALL);
	CString field[3]={"姓名","性别","组别"};
	for(int k=0;k<3;k++){
		m_list.InsertColumn(k,field[k],LVCFMT_LEFT,70);
	}
	
	m_tree.SetImageList(&m_ImageList,TVSIL_NORMAL);
	CString m_TreeHeader[2]={"性别","组别"};
	HTREEITEM hParentItem[2];
	for(int i=0;i<2;i++){
		hParentItem[i]=m_tree.InsertItem(m_TreeHeader[i],2,3,TVI_ROOT);
	}
	HTREEITEM men=m_tree.InsertItem("男",2,3,hParentItem[0]);
	m_tree.SetItemData(men,(DWORD)0);
	HTREEITEM w=	m_tree.InsertItem("女",2,3,hParentItem[0]);
	m_tree.SetItemData(w,(DWORD)1);

	HTREEITEM cz=m_tree.InsertItem("初中组",2,3,hParentItem[1]);
	m_tree.SetItemData(cz,(DWORD)2);
	HTREEITEM gz=m_tree.InsertItem("高中组",2,3,hParentItem[1]);
	m_tree.SetItemData(gz,(DWORD)3);
	m_tree.Select(w,TVGN_CARET);
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

void CMyDlg::OnItemchangingList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here


	
	*pResult = 0;
}

void CMyDlg::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	HTREEITEM hSelectItem=m_tree.GetSelectedItem();
	DWORD value=m_tree.GetItemData(hSelectItem);
	switch(value){
	case 0:
		 {
			 m_list.DeleteAllItems();
			 m_list.InsertItem(0,"李玉刚",0);
			 m_list.SetItemText(0,1,"男");
			 m_list.SetItemText(0,2,"初中组");
			 m_list.InsertItem(1,"李小明",0);
			 m_list.SetItemText(1,1,"男");
			 m_list.SetItemText(1,2,"高中组");
			 break;
		 }
	case 1:
		 {
			 m_list.DeleteAllItems();
			 m_list.InsertItem(0,"张旭",1);
			 m_list.SetItemText(0,1,"女");
			 m_list.SetItemText(0,2,"初中组");
			 m_list.InsertItem(1,"刘丽娜",1);
			 m_list.SetItemText(1,1,"女");
			 m_list.SetItemText(1,2,"高中组");
			 break;
		 }
	case 2:
		{
			m_list.DeleteAllItems();
			 m_list.InsertItem(0,"李玉刚",0);
			 m_list.SetItemText(0,1,"男");
			 m_list.SetItemText(0,2,"初中组");
			 m_list.InsertItem(1,"张旭",1);
			 m_list.SetItemText(1,1,"女");
			 m_list.SetItemText(1,2,"初中组");
			 break;
		   }
	case 3:
		{
			 m_list.DeleteAllItems();
			 m_list.InsertItem(0,"刘丽娜",1);
			 m_list.SetItemText(0,1,"女");
			 m_list.SetItemText(0,2,"高中组");
			 m_list.InsertItem(1,"李小明",0);
			 m_list.SetItemText(1,1,"男");
			 m_list.SetItemText(1,2,"高中组");
			 break;
		}
	}

	


	*pResult = 0;
}

void CMyDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
		for(int i=0;i<m_list.GetItemCount();i++){
		if(m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED){
			CString str=m_list.GetItemText(i,0);
			CString str1=m_list.GetItemText(i,1);
			CString str2=m_list.GetItemText(i,2);
			AfxMessageBox("姓名:"+str+"  性别:"+str1+"  组别:"+str2);
			break;
		}
	}
	*pResult = 0;
}
