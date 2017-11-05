// DrawTextDoc.cpp : implementation of the CDrawTextDoc class
//

#include "stdafx.h"
#include "DrawText.h"

#include "DrawTextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawTextDoc

IMPLEMENT_DYNCREATE(CDrawTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawTextDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawTextDoc construction/destruction

CDrawTextDoc::CDrawTextDoc()
{
	// TODO: add one-time construction code here

}

CDrawTextDoc::~CDrawTextDoc()
{
}

BOOL CDrawTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawTextDoc serialization

void CDrawTextDoc::Serialize(CArchive& ar)
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
// CDrawTextDoc diagnostics

#ifdef _DEBUG
void CDrawTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawTextDoc commands
