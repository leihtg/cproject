// UseOcxView.cpp : implementation of the CUseOcxView class
//

#include "stdafx.h"
#include "UseOcx.h"

#include "UseOcxDoc.h"
#include "UseOcxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseOcxView

IMPLEMENT_DYNCREATE(CUseOcxView, CView)

BEGIN_MESSAGE_MAP(CUseOcxView, CView)
	//{{AFX_MSG_MAP(CUseOcxView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseOcxView construction/destruction

CUseOcxView::CUseOcxView()
{
	// TODO: add construction code here

}

CUseOcxView::~CUseOcxView()
{
}

BOOL CUseOcxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUseOcxView drawing

void CUseOcxView::OnDraw(CDC* pDC)
{
	CUseOcxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CUseOcxView printing

BOOL CUseOcxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUseOcxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUseOcxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CUseOcxView diagnostics

#ifdef _DEBUG
void CUseOcxView::AssertValid() const
{
	CView::AssertValid();
}

void CUseOcxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUseOcxDoc* CUseOcxView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseOcxDoc)));
	return (CUseOcxDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseOcxView message handlers
