// PicBrowserView.cpp : implementation of the CPicBrowserView class
//

#include "stdafx.h"
#include "PicBrowser.h"

#include "PicBrowserDoc.h"
#include "PicBrowserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView

IMPLEMENT_DYNCREATE(CPicBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CPicBrowserView, CHtmlView)
	//{{AFX_MSG_MAP(CPicBrowserView)
	ON_COMMAND(ID_BROWER_BTN, OnBrowerBtn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView construction/destruction

CPicBrowserView::CPicBrowserView()
{
	// TODO: add construction code here

}

CPicBrowserView::~CPicBrowserView()
{
}

BOOL CPicBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView drawing

void CPicBrowserView::OnDraw(CDC* pDC)
{
	CPicBrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CPicBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("http://www.baidu.com"),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView printing


/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView diagnostics

#ifdef _DEBUG
void CPicBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CPicBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CPicBrowserDoc* CPicBrowserView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPicBrowserDoc)));
	return (CPicBrowserDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserView message handlers

void CPicBrowserView::SetFile(LPCSTR lpFileName)
{
	CString tmp;
	FILE *fp=NULL;
	CString m_TempFile;
	if(lpFileName!=NULL){
		tmp.Format("<html><head><title>图片浏览器</title></head><body><div id=\"image\" class=\"slides\"><img src=\"%s\"</div></body></html>",lpFileName);
		m_TempFile=GetExeFilePath();
		m_TempFile+="\\temp.html";
		fp=fopen(m_TempFile,"w+");
		int nSize=fprintf(fp,"%s",tmp);
		fclose(fp);
	}

}

void CPicBrowserView::OnBrowerBtn() 
{
	// TODO: Add your command handler code here
	CString strFileName;
	CString tmpFilePath;
	CString strFilter("JPEG文件(*.jpg)|*.jpg|动画文件(*.gif)|.gif||");
	CFileDialog OpenDlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,strFilter);
	int nFlags=OpenDlg.DoModal();
	if(nFlags==IDOK){
		strFileName=OpenDlg.GetPathName();
		SetFile(strFileName);
		strFileName=GetExeFilePath();
		strFileName+="\\temp.html";
		tmpFilePath.Format("file:///%s",strFileName);
		Navigate2(tmpFilePath,NULL,NULL);
		Refresh();
	}

}
CString CPicBrowserView::GetExeFilePath(){
	char exeFullPath[1000];
	CString m_TempFile;
	GetModuleFileName(NULL,exeFullPath,1000);
	m_TempFile.Format("%s",exeFullPath);
	exeFullPath[m_TempFile.GetLength()-15]='\0';
	m_TempFile.Format("%s",exeFullPath);
	return m_TempFile;
}