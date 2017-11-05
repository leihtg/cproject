// DocView.cpp : implementation of the CDocView class
//

#include "stdafx.h"
#include "Doc.h"

#include "DocDoc.h"
#include "DocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocView

IMPLEMENT_DYNCREATE(CDocView, CView)

BEGIN_MESSAGE_MAP(CDocView, CView)
	//{{AFX_MSG_MAP(CDocView)
	ON_COMMAND(circle, Oncircle)
	ON_COMMAND(rec, Onrec)
	ON_UPDATE_COMMAND_UI(circle, OnUpdatecircle)
	ON_UPDATE_COMMAND_UI(rec, OnUpdaterec)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocView construction/destruction

CDocView::CDocView()
{
	// TODO: add construction code here
	m_nDdrawtype=0;
}

CDocView::~CDocView()
{
}

BOOL CDocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDocView drawing

void CDocView::OnDraw(CDC* pDC)
{
	CDocDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDocView printing

BOOL CDocView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDocView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDocView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDocView diagnostics

#ifdef _DEBUG
void CDocView::AssertValid() const
{
	CView::AssertValid();
}

void CDocView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDocDoc* CDocView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocDoc)));
	return (CDocDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDocView message handlers

void CDocView::Oncircle() 
{
	// TODO: Add your command handler code here
	m_nDdrawtype=1;
	CDC *pDc=GetDC();
	CRect rect(100,0,300,200);
	CBrush brush(RGB(180,180,180));
	pDc->FillRect(rect,&brush);
	pDc->Ellipse(160,10,260,110);
	pDc->TextOut(120,120,"绘制直径为100个像素的圆");
	ReleaseDC(pDc);
}

void CDocView::Onrec() 
{
	// TODO: Add your command handler code here
	m_nDdrawtype=2;
	CDC *pDc=GetDC();
	CRect rect(100,0,300,200);
	CBrush brush(RGB(180,180,180));
	pDc->FillRect(rect,&brush);
	pDc->Rectangle(160,10,260,110);
	pDc->TextOut(120,120,"绘制连长为100的正方形");
	ReleaseDC(pDc);
}

void CDocView::OnUpdatecircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nDdrawtype==1);
}

void CDocView::OnUpdaterec(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nDdrawtype==2);
}

void CDocView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu;
	menu.LoadMenu(pop);
	CMenu *pM=menu.GetSubMenu(0);
	CPoint pt;
	GetCursorPos(&pt);
	pM->TrackPopupMenu(TPM_LEFTBUTTON,pt.x,pt.y,this);
	

	
	CView::OnRButtonDown(nFlags, point);
}
