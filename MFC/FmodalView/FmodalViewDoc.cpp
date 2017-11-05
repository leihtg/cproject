// FmodalViewDoc.cpp : implementation of the CFmodalViewDoc class
//

#include "stdafx.h"
#include "FmodalView.h"

#include "FmodalViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewDoc

IMPLEMENT_DYNCREATE(CFmodalViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CFmodalViewDoc, CDocument)
	//{{AFX_MSG_MAP(CFmodalViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewDoc construction/destruction

CFmodalViewDoc::CFmodalViewDoc()
{
	// TODO: add one-time construction code here

}

CFmodalViewDoc::~CFmodalViewDoc()
{
}

BOOL CFmodalViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFmodalViewDoc serialization

void CFmodalViewDoc::Serialize(CArchive& ar)
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
// CFmodalViewDoc diagnostics

#ifdef _DEBUG
void CFmodalViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFmodalViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFmodalViewDoc commands
