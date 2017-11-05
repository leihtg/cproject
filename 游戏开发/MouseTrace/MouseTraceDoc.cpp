// MouseTraceDoc.cpp : implementation of the CMouseTraceDoc class
//

#include "stdafx.h"
#include "MouseTrace.h"

#include "MouseTraceDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceDoc

IMPLEMENT_DYNCREATE(CMouseTraceDoc, CDocument)

BEGIN_MESSAGE_MAP(CMouseTraceDoc, CDocument)
	//{{AFX_MSG_MAP(CMouseTraceDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceDoc construction/destruction

CMouseTraceDoc::CMouseTraceDoc()
{
	// TODO: add one-time construction code here

}

CMouseTraceDoc::~CMouseTraceDoc()
{
}

BOOL CMouseTraceDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMouseTraceDoc serialization

void CMouseTraceDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceDoc diagnostics

#ifdef _DEBUG
void CMouseTraceDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMouseTraceDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMouseTraceDoc commands
