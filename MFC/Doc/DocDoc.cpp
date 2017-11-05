// DocDoc.cpp : implementation of the CDocDoc class
//

#include "stdafx.h"
#include "Doc.h"

#include "DocDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocDoc

IMPLEMENT_DYNCREATE(CDocDoc, CDocument)

BEGIN_MESSAGE_MAP(CDocDoc, CDocument)
	//{{AFX_MSG_MAP(CDocDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocDoc construction/destruction

CDocDoc::CDocDoc()
{
	// TODO: add one-time construction code here

}

CDocDoc::~CDocDoc()
{
}

BOOL CDocDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDocDoc serialization

void CDocDoc::Serialize(CArchive& ar)
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
// CDocDoc diagnostics

#ifdef _DEBUG
void CDocDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDocDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDocDoc commands
