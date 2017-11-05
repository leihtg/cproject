// 鼠标消息处理实例View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "鼠标消息处理实例.h"

#include "鼠标消息处理实例Doc.h"
#include "鼠标消息处理实例View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here
	fDowned=false;
	ptDown.x=0;
	ptDown.y=0;
	ptUp.x=0;
	ptUp.y=0;
}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	m_cursor=(HCURSOR)::LoadImage(cs.hInstance,MAKEINTRESOURCE(IDC_CURSOR1),IMAGE_CURSOR,32,32,LR_CREATEDIBSECTION);
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	fDowned=TRUE;
	ptUp=ptDown=point;
	SetCapture();
	GetClipCursor(&oldrect);
	CRect rect1;
	GetWindowRect(&rect1);
	ClipCursor(&rect1);
	CView::OnLButtonDown(nFlags, point);
}

void CMyView::DrawRect()
{
	CClientDC dc(this);
	CRect rect;
	GetClientRect(rect);
	CBrush brush(RGB(255,255,255));
	dc.FillRect(rect,&brush);
	dc.Rectangle(ptDown.x,ptDown.y,ptUp.x,ptUp.y);

}

void CMyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!fDowned){
	//	HCURSOR cursor=AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	//	SetCursor(cursor);
		SetCursor(m_cursor);
		ptUp=point;
		DrawRect();
	}
	CView::OnMouseMove(nFlags, point);
}

void CMyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(fDowned){
		ptUp=point;
		DrawRect();
		fDowned=FALSE;
	}
	ReleaseCapture();
	ClipCursor(&oldrect);
	CView::OnLButtonUp(nFlags, point);
}
