// TwoThreadView.cpp : implementation of the CTwoThreadView class
//

#include "stdafx.h"
#include "TwoThread.h"
#include "UIThread.h"
#include "UIDlg.h"

#include "TwoThreadDoc.h"
#include "TwoThreadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadView

IMPLEMENT_DYNCREATE(CTwoThreadView, CView)

BEGIN_MESSAGE_MAP(CTwoThreadView, CView)
	//{{AFX_MSG_MAP(CTwoThreadView)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_COMMAND(a, Ona)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadView construction/destruction

CTwoThreadView::CTwoThreadView()
{
	// TODO: add construction code here

}

CTwoThreadView::~CTwoThreadView()
{
}

BOOL CTwoThreadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadView drawing

void CTwoThreadView::OnDraw(CDC* pDC)
{
	CTwoThreadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadView printing

BOOL CTwoThreadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTwoThreadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTwoThreadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadView diagnostics

#ifdef _DEBUG
void CTwoThreadView::AssertValid() const
{
	CView::AssertValid();
}

void CTwoThreadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTwoThreadDoc* CTwoThreadView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTwoThreadDoc)));
	return (CTwoThreadDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadView message handlers

void CTwoThreadView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1){
		CClientDC dc(this);
		CFont myfont;
		CFont *oldfont;
		LOGFONT font;
		memset(&font,0,sizeof(LOGFONT));
		font.lfHeight=50;
		font.lfWeight=600;
		strcpy(font.lfFaceName,"Arail");
		myfont.CreateFontIndirect(&font);
		oldfont=dc.SelectObject(&myfont);
		CTime m_time;
		m_time=CTime::GetCurrentTime();
		CString str=m_time.Format("当前时间：%H:%M:%S");
		dc.TextOut(40,70,str);
		dc.SelectObject(oldfont);
	}
	CView::OnTimer(nIDEvent);
}

int CTwoThreadView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	SetTimer(1,1000,NULL);	
	return 0;
}

void CTwoThreadView::Ona() 
{
	//CWinThread *pThread=
	//	AfxBeginThread(RUNTIME_CLASS(CUIThread),0,0,NULL);
	CUIThread *thread=new CUIThread();
	thread->CreateThread();
/*	CUIDlg *pDlg=new CUIDlg;
	pDlg->Create(IDD_DIALOG1);
	pDlg->ShowWindow(SW_SHOW);
	*/
}
