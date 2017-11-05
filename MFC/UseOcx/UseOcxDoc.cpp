// UseOcxDoc.cpp : implementation of the CUseOcxDoc class
//

#include "stdafx.h"
#include "UseOcx.h"

#include "UseOcxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseOcxDoc

IMPLEMENT_DYNCREATE(CUseOcxDoc, CDocument)

BEGIN_MESSAGE_MAP(CUseOcxDoc, CDocument)
	//{{AFX_MSG_MAP(CUseOcxDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseOcxDoc construction/destruction

CUseOcxDoc::CUseOcxDoc()
{
	// TODO: add one-time construction code here

}

CUseOcxDoc::~CUseOcxDoc()
{
}

BOOL CUseOcxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUseOcxDoc serialization

void CUseOcxDoc::Serialize(CArchive& ar)
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
// CUseOcxDoc diagnostics

#ifdef _DEBUG
void CUseOcxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUseOcxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseOcxDoc commands
