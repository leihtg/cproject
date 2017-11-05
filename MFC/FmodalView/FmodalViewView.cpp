// FmodalViewView.cpp : implementation of the CFmodalViewView class
//

#include "stdafx.h"
#include "FmodalView.h"

#include "FmodalViewDoc.h"
#include "FmodalViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_SET_COLOR WM_USER+100	
/////////////////////////////////////////////////////////////////////////////
// CFmodalViewView

IMPLEMENT_DYNCREATE(CFmodalViewView, CView)

BEGIN_MESSAGE_MAP(CFmodalViewView, CView)
	//{{AFX_MSG_MAP(CFmodalViewView)
	ON_WM_RBUTTONDOWN()
	ON_MESSAGE(WM_SET_COLOR,OnSetColor)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewView construction/destruction

CFmodalViewView::CFmodalViewView()
{
	// TODO: add construction code here
	r=128;
	g=b=0;
}

CFmodalViewView::~CFmodalViewView()
{
}

BOOL CFmodalViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	pDialog=new CBrushColorDlg(this);

	if(pDialog!=NULL){
		BOOL ret=	pDialog->Create(IDD_DIALOG1,this);
		if(!ret){
			AfxMessageBox("Error creating Dialog");
		}
	}else{
		AfxMessageBox("创建失败!");
	}
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewView drawing

void CFmodalViewView::OnDraw(CDC* pDC)
{
	CFmodalViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CBrush mybrush(RGB(r,g,b));
	CBrush *oldbrush;
	oldbrush=pDC->SelectObject(&mybrush);

	pDC->Ellipse(10,10,200,120);
	pDC->SelectObject(oldbrush);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewView printing

BOOL CFmodalViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFmodalViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFmodalViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewView diagnostics

#ifdef _DEBUG
void CFmodalViewView::AssertValid() const
{
	CView::AssertValid();
}

void CFmodalViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFmodalViewDoc* CFmodalViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFmodalViewDoc)));
	return (CFmodalViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewView message handlers

void CFmodalViewView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	pDialog->ShowWindow(SW_HIDE);
	CRect dlgRect;
	pDialog->GetWindowRect(&dlgRect);
	ClientToScreen(&point);

	pDialog->MoveWindow(point.x,point.y,dlgRect.Width(),dlgRect.Height());

	pDialog->m_blue=b;
	pDialog->m_green=g;
	pDialog->m_red=r;
	pDialog->UpdateData(false);
	pDialog->ShowWindow(SW_SHOW);
	CView::OnRButtonDown(nFlags, point);
}

void CFmodalViewView::OnSetColor(WPARAM sP,LPARAM lP){
	r=pDialog->m_red;
	g=pDialog->m_green;
	b=pDialog->m_blue;
	Invalidate();//更新视图
}