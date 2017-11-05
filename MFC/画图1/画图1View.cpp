// »­Í¼1View.cpp : implementation of the CMy1View class
//

#include "stdafx.h"
#include "»­Í¼1.h"

#include "»­Í¼1Doc.h"
#include "»­Í¼1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1View

IMPLEMENT_DYNCREATE(CMy1View, CView)

BEGIN_MESSAGE_MAP(CMy1View, CView)
	//{{AFX_MSG_MAP(CMy1View)
	ON_COMMAND(id_cancel, Oncancel)
	ON_COMMAND(id_clear, Onclear)
	ON_COMMAND(id_drawcircle, Ondrawcircle)
	ON_UPDATE_COMMAND_UI(id_drawcircle, OnUpdatedrawcircle)
	ON_COMMAND(id_drawline, Ondrawline)
	ON_UPDATE_COMMAND_UI(id_drawline, OnUpdatedrawline)
	ON_COMMAND(id_drawrect, Ondrawrect)
	ON_UPDATE_COMMAND_UI(id_drawrect, OnUpdatedrawrect)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1View construction/destruction

CMy1View::CMy1View()
{
	// TODO: add construction code here

}

CMy1View::~CMy1View()
{
}

BOOL CMy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy1View drawing

void CMy1View::OnDraw(CDC* pDC)
{
	CMy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CBrush *poldBrush;
	poldBrush=(CBrush*)pDC->SelectStockObject(NULL_BRUSH);
	if(!pDoc->m_graphlist.IsEmpty()){
		POSITION pos=pDoc->m_graphlist.GetHeadPosition();
		for(int i=0;i<pDoc->m_graphlist.GetCount();i++){
			CGraph* m_pGraph=(CGraph*)pDoc->m_graphlist.GetNext(pos);
			if(m_pGraph->m_type==0){
				pDC->MoveTo(m_pGraph->m_star);
				pDC->LineTo(m_pGraph->m_end);
			}else if(m_pGraph->m_type==1){
				pDC->Rectangle(m_pGraph->m_star.x,m_pGraph->m_star.y,m_pGraph->m_end.x,m_pGraph->m_end.y);
			}else if(m_pGraph->m_type==2){
				pDC->Ellipse(m_pGraph->m_star.x,m_pGraph->m_star.y,m_pGraph->m_end.x,m_pGraph->m_end.y);
			}
		}
	}
	if(bMove){
		if(m_drawtype==0){
			pDC->MoveTo(ptstar);
			pDC->LineTo(ptend);

		}else if(m_drawtype==1){
			pDC->Rectangle(ptstar.x,ptstar.y,ptend.x,ptend.y);
		}else if(m_drawtype==2){
			pDC->Ellipse(ptstar.x,ptstar.y,ptend.x,ptend.y);
		}
	}
	pDC->SelectObject(poldBrush);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy1View printing

BOOL CMy1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy1View diagnostics

#ifdef _DEBUG
void CMy1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1Doc* CMy1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1Doc)));
	return (CMy1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1View message handlers

void CMy1View::Oncancel() 
{
	// TODO: Add your command handler code here
	CMy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc->m_graphlist.IsEmpty()){
		pDoc->m_graphlist.RemoveTail();
	}
	Invalidate(true);

}

void CMy1View::Onclear() 
{
	// TODO: Add your command handler code here
	CMy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc->m_graphlist.IsEmpty()){
		pDoc->m_graphlist.RemoveAll();
	}
	Invalidate(true);
}

void CMy1View::Ondrawcircle() 
{
	// TODO: Add your command handler code here
	m_drawtype=2;
}

void CMy1View::OnUpdatedrawcircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_drawtype==2);
}

void CMy1View::Ondrawline() 
{
	// TODO: Add your command handler code here
	m_drawtype=0;
}

void CMy1View::OnUpdatedrawline(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_drawtype==0);
}

void CMy1View::Ondrawrect() 
{
	// TODO: Add your command handler code here
	m_drawtype=1;
}

void CMy1View::OnUpdatedrawrect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_drawtype==1);
}

void CMy1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	bDown=true;
	ptstar=point;
	CView::OnLButtonDown(nFlags, point);
}

void CMy1View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	bMove=false;
	bDown=false;
	CMy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	ptend=point;
	CGraph* m_graph=new CGraph;
	if((m_drawtype==0)|(m_drawtype==1)|(m_drawtype==2)){
		m_graph->m_star=ptstar;
		m_graph->m_end=ptend;
		m_graph->m_type=m_drawtype;
		pDoc->m_graphlist.AddTail(m_graph);
		Invalidate(true);
	}
	CView::OnLButtonUp(nFlags, point);
}

void CMy1View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(bDown){
		ptend=point;
		bMove=true;
		Invalidate(true);
	}
	CView::OnMouseMove(nFlags, point);
}
