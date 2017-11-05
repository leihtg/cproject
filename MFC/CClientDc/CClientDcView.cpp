// CClientDcView.cpp : implementation of the CCClientDcView class
//

#include "stdafx.h"
#include "CClientDc.h"

#include "CClientDcDoc.h"
#include "CClientDcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCClientDcView

IMPLEMENT_DYNCREATE(CCClientDcView, CView)

BEGIN_MESSAGE_MAP(CCClientDcView, CView)
	//{{AFX_MSG_MAP(CCClientDcView)
	ON_COMMAND(clientDc, OnclientDc)
	ON_UPDATE_COMMAND_UI(clientDc, OnUpdateclientDc)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCClientDcView construction/destruction

CCClientDcView::CCClientDcView()
{
	// TODO: add construction code here
	check=0;
}

CCClientDcView::~CCClientDcView()
{
}

BOOL CCClientDcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCClientDcView drawing

void CCClientDcView::OnDraw(CDC* pDC)
{
	CCClientDcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCClientDcView printing

BOOL CCClientDcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCClientDcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCClientDcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCClientDcView diagnostics

#ifdef _DEBUG
void CCClientDcView::AssertValid() const
{
	CView::AssertValid();
}

void CCClientDcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCClientDcDoc* CCClientDcView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCClientDcDoc)));
	return (CCClientDcDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCClientDcView message handlers

void CCClientDcView::OnclientDc() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	CPen pen1;
	pen1.CreatePen(PS_SOLID,0,RGB(255,0,0));
	CPen *poldPen=dc.SelectObject(&pen1);
	dc.SelectStockObject(GRAY_BRUSH);
	CRect rect1(0,0,120,90);
	dc.Rectangle(&rect1);
	check=1;
}

void CCClientDcView::OnUpdateclientDc(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(check==1);
}
