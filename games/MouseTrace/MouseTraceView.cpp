// MouseTraceView.cpp : implementation of the CMouseTraceView class
//

#include "stdafx.h"
#include "MouseTrace.h"

#include "MouseTraceDoc.h"
#include "MouseTraceView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceView

IMPLEMENT_DYNCREATE(CMouseTraceView, CView)

BEGIN_MESSAGE_MAP(CMouseTraceView, CView)
	//{{AFX_MSG_MAP(CMouseTraceView)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceView construction/destruction

CMouseTraceView::CMouseTraceView()
{
	// TODO: add construction code here

}

CMouseTraceView::~CMouseTraceView()
{
}

BOOL CMouseTraceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceView drawing

void CMouseTraceView::OnDraw(CDC* pDC)
{
	CMouseTraceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(50,100,m_showMsg);
}

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceView diagnostics

#ifdef _DEBUG
void CMouseTraceView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseTraceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseTraceDoc* CMouseTraceView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseTraceDoc)));
	return (CMouseTraceDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceView message handlers

void CMouseTraceView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_showMsg.Format("x=%d,y=%d",point.x,point.y);
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
