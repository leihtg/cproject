// DrawTextView.cpp : implementation of the CDrawTextView class
//

#include "stdafx.h"
#include "DrawText.h"

#include "DrawTextDoc.h"
#include "DrawTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawTextView

IMPLEMENT_DYNCREATE(CDrawTextView, CView)

BEGIN_MESSAGE_MAP(CDrawTextView, CView)
	//{{AFX_MSG_MAP(CDrawTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawTextView construction/destruction

CDrawTextView::CDrawTextView()
{
	// TODO: add construction code here

}

CDrawTextView::~CDrawTextView()
{
}

BOOL CDrawTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawTextView drawing

void CDrawTextView::OnDraw(CDC* pDC)
{
	CDrawTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CString str="下面的文体显示为采用DrawTextt()函数进行格式化输出：";
	pDC->TextOut(10,10,str);
	CRect rect;
	GetClientRect(&rect);
	CRect textrect(40,50,(rect.Width()-30),rect.Height());
	pDC->SetTextColor(RGB(200,10,10));
	pDC->SetBkColor(TRANSPARENT);
	CString str2="　八方乱，国将亡。    百姓号哭于野，妖魔披衣冠据庙堂。    弱冠书生，何去何从？    仗剑而起诛鬼魅，提笔静坐写文章。    手握乾坤，斩邪留正——    一曲《正气歌》，浩然起苍茫。";
	pDC->DrawText(str2,&textrect,DT_LEFT|DT_WORDBREAK);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawTextView printing

BOOL CDrawTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawTextView diagnostics

#ifdef _DEBUG
void CDrawTextView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawTextDoc* CDrawTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawTextDoc)));
	return (CDrawTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawTextView message handlers
