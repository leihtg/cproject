// 数据库1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "数据库1.h"
#include "数据库1Dlg.h"

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
// CMy1Dlg dialog

CMy1Dlg::CMy1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1Dlg)
	m_StuNo = _T("");
	m_StuName = _T("");
	m_StuAddress = _T("");
	m_StuTel = _T("");
	m_Status = _T("");
	m_radio = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CMy1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_StuNo);
	DDX_Text(pDX, IDC_EDIT2, m_StuName);
	DDX_Text(pDX, IDC_EDIT3, m_StuAddress);
	DDX_Text(pDX, IDC_EDIT4, m_StuTel);
	DDX_Text(pDX, IDC_EDIT5, m_Status);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_add, OnAdd)
	ON_BN_CLICKED(IDC_remove, OnRemove)
	ON_BN_CLICKED(IDC_checkin, OnCheckin)
	ON_BN_CLICKED(IDC_first, OnFirst)
	ON_BN_CLICKED(IDC_next, OnNext)
	ON_BN_CLICKED(IDC_prev, OnPrev)
	ON_BN_CLICKED(IDC_last, OnLast)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1Dlg message handlers

BOOL CMy1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	HRESULT hr;
	try{
		hr=m_pConnection.CreateInstance("ADODB.Connection");
		if(SUCCEEDED(hr)){
			hr=m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=student.mdb","","",adModeUnknown);
			_variant_t RecordsAffected;
			m_pConnection->Execute("create table studentinfo(stuNo text,stuName text,stuAddress text,stuphone text)",&RecordsAffected,adCmdText);
		
		}
		
	}catch(_com_error e){
		CString errormessage;
		errormessage.Format("连接数据库失败！\r\n错误信息：%s",e.ErrorMessage());
		AfxMessageBox(errormessage);
	}
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
	GetDlgItem(IDC_remove)->EnableWindow(false);
	GetDlgItem(IDC_checkin)->EnableWindow(false);
	GetDlgItem(IDC_first)->EnableWindow(false);
	GetDlgItem(IDC_next)->EnableWindow(false);
	GetDlgItem(IDC_prev)->EnableWindow(false);
	GetDlgItem(IDC_last)->EnableWindow(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1Dlg::OnPaint() 
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
HCURSOR CMy1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1Dlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_radio=0;
	GetDlgItem(IDC_add)->EnableWindow(true);
	GetDlgItem(IDC_remove)->EnableWindow(false);
	GetDlgItem(IDC_checkin)->EnableWindow(false);

	GetDlgItem(IDC_first)->EnableWindow(false);
	GetDlgItem(IDC_next)->EnableWindow(false);
	GetDlgItem(IDC_prev)->EnableWindow(false);
	GetDlgItem(IDC_last)->EnableWindow(false);
	
	m_StuNo=m_StuName=m_StuAddress=m_StuTel="";
	UpdateData(false);


}

void CMy1Dlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_radio=1;
	GetDlgItem(IDC_add)->EnableWindow(false);
	GetDlgItem(IDC_remove)->EnableWindow(true);
	GetDlgItem(IDC_checkin)->EnableWindow(false);

	GetDlgItem(IDC_first)->EnableWindow(true);
	GetDlgItem(IDC_next)->EnableWindow(true);
	GetDlgItem(IDC_prev)->EnableWindow(true);
	GetDlgItem(IDC_last)->EnableWindow(true);
	_variant_t RecordsAffected;
	m_pRecordset=m_pConnection->Execute("select count(*) from studentinfo",&RecordsAffected,adCmdText);
	_variant_t vIndex=(long)0;
	_variant_t vCount=m_pRecordset->GetCollect(vIndex);
	count=vCount.lVal;
	m_pRecordset->Close();
	if(count==0){
		GetDlgItem(IDC_remove)->EnableWindow(false);
		GetDlgItem(IDC_first)->EnableWindow(false);
		GetDlgItem(IDC_next)->EnableWindow(false);
		GetDlgItem(IDC_prev)->EnableWindow(false);
		GetDlgItem(IDC_last)->EnableWindow(false);
		
		m_Status="表中没有数据!";
		UpdateData(false);
		return;
	}
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	CString strSQL="select * from studentinfo";
	try{
		m_pRecordset->Open(_bstr_t(strSQL),m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}catch(_com_error e){
		CString strError;
		strError.Format("警告，打开数据表时发生异常，错误信息：%s",e.ErrorMessage());
		AfxMessageBox(strError);
		return;
	}
	m_pRecordset->MoveFirst();
	curNo=1;
	m_Status.Format("共有%d条记录，当前第%d条",count,curNo);
	UpdateData(false);
	ShowRecord();

}
void CMy1Dlg::ShowRecord(){
	m_StuNo=(char*)_bstr_t(m_pRecordset->GetCollect("stuNo"));
	m_StuName=(char*)_bstr_t(m_pRecordset->GetCollect("stuName"));
	m_StuAddress=(char*)_bstr_t(m_pRecordset->GetCollect("stuAddress"));
	m_StuTel=(char*)_bstr_t(m_pRecordset->GetCollect("stuPhone"));
	UpdateData(false);
}
void CMy1Dlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	m_radio=2;
	GetDlgItem(IDC_add)->EnableWindow(false);
	GetDlgItem(IDC_remove)->EnableWindow(false);
	GetDlgItem(IDC_checkin)->EnableWindow(true);

	GetDlgItem(IDC_first)->EnableWindow(true);
	GetDlgItem(IDC_next)->EnableWindow(true);
	GetDlgItem(IDC_prev)->EnableWindow(true);
	GetDlgItem(IDC_last)->EnableWindow(true);

		_variant_t RecordsAffected;
	m_pRecordset=m_pConnection->Execute("select count(*) from studentinfo",&RecordsAffected,adCmdText);
	_variant_t vIndex=(long)0;
	_variant_t vCount=m_pRecordset->GetCollect(vIndex);
	count=vCount.lVal;
	m_pRecordset->Close();
	if(count==0){
		GetDlgItem(IDC_remove)->EnableWindow(false);
		GetDlgItem(IDC_first)->EnableWindow(false);
		GetDlgItem(IDC_next)->EnableWindow(false);
		GetDlgItem(IDC_prev)->EnableWindow(false);
		GetDlgItem(IDC_last)->EnableWindow(false);
		
		m_Status="表中没有数据!";
		UpdateData(false);
		return;
	}
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	CString strSQL="select * from studentinfo";
	try{
		m_pRecordset->Open(_bstr_t(strSQL),m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}catch(_com_error e){
		CString strError;
		strError.Format("警告，打开数据表时发生异常，错误信息：%s",e.ErrorMessage());
		AfxMessageBox(strError);
		return;
	}
	m_pRecordset->MoveFirst();
	curNo=1;
	m_Status.Format("共有%d条记录，当前第%d条",count,curNo);
	UpdateData(false);
	ShowRecord();
}

void CMy1Dlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	_variant_t RecordsAffected;
	UpdateData();
	if(m_StuNo.IsEmpty()){
		AfxMessageBox("学号不能为空！");
		return ;

	}
	CString strSQL;
	strSQL.Format("insert into studentinfo values('%s','%s','%s','%s')",m_StuNo,m_StuName,m_StuAddress,m_StuTel);
	m_pConnection->Execute((_bstr_t)strSQL,&RecordsAffected,adCmdText);
	m_Status="成功添加了一行记录！";
	m_StuNo=m_StuName=m_StuAddress=m_StuTel="";
	UpdateData(false);

}

void CMy1Dlg::OnRemove() 
{
	// TODO: Add your control notification handler code here
	m_pRecordset->Delete(adAffectCurrent);
	m_Status="成功删除了一条记录!";
	count--;
	UpdateData(false);
	OnFirst();
	
}

void CMy1Dlg::OnCheckin() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_pRecordset->PutCollect("stuNo",_variant_t(m_StuNo));
	m_pRecordset->PutCollect("stuName",_variant_t(m_StuName));
	m_pRecordset->PutCollect("stuAddress",_variant_t(m_StuAddress));
	m_pRecordset->PutCollect("stuPhone",_variant_t(m_StuTel));
	m_pRecordset->Update();
	m_Status="成功修改了一条记录!";
	UpdateData(false);
}

void CMy1Dlg::OnFirst() 
{
	// TODO: Add your control notification handler code here
	if(count==0){
		m_StuNo=m_StuName=m_StuAddress=m_StuTel="";
		UpdateData(false);
		GetDlgItem(IDC_remove)->EnableWindow(false);
		GetDlgItem(IDC_first)->EnableWindow(false);
		GetDlgItem(IDC_next)->EnableWindow(false);
		GetDlgItem(IDC_prev)->EnableWindow(false);
		GetDlgItem(IDC_last)->EnableWindow(false);
		return;
	}
	m_pRecordset->MoveFirst();
	curNo=1;
	m_Status.Format("共有%d条记录，当前第%d条",count,curNo);
	//UpdateData(false);
	ShowRecord();

}

void CMy1Dlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	if(curNo<count){
		m_pRecordset->MoveNext();
		curNo++;
		if(m_pRecordset->adoEOF){
			m_pRecordset->MoveLast();
		}
		m_Status.Format("共有%d条记录，当前第%d条",count,curNo);
		ShowRecord();
	}
	

}

void CMy1Dlg::OnPrev() 
{
	// TODO: Add your control notification handler code here
	if(curNo>1){
		m_pRecordset->MovePrevious();
		curNo--;
		if(m_pRecordset->BOF){
			m_pRecordset->MoveFirst();
		}
		m_Status.Format("共有%d条记录，当前第%d条",count,curNo);
		ShowRecord();
	}
}

void CMy1Dlg::OnLast() 
{
	// TODO: Add your control notification handler code here
	m_pRecordset->MoveLast();
	curNo=count;
	m_Status.Format("共有%d条记录，当前第%d条",count,curNo);
	ShowRecord();

}

BOOL CMy1Dlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_pRecordset!=NULL){
		m_pRecordset->Close();
		m_pRecordset=NULL;
	}
	if(m_pConnection!=NULL){
		m_pConnection->Close();
		m_pConnection=NULL;
	}
	return CDialog::DestroyWindow();
}
