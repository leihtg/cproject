// TwoThreadDoc.cpp : implementation of the CTwoThreadDoc class
//

#include "stdafx.h"
#include "TwoThread.h"

#include "TwoThreadDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadDoc

IMPLEMENT_DYNCREATE(CTwoThreadDoc, CDocument)

BEGIN_MESSAGE_MAP(CTwoThreadDoc, CDocument)
	//{{AFX_MSG_MAP(CTwoThreadDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadDoc construction/destruction

CTwoThreadDoc::CTwoThreadDoc()
{
	// TODO: add one-time construction code here

}

CTwoThreadDoc::~CTwoThreadDoc()
{
}

BOOL CTwoThreadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTwoThreadDoc serialization

void CTwoThreadDoc::Serialize(CArchive& ar)
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
// CTwoThreadDoc diagnostics

#ifdef _DEBUG
void CTwoThreadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTwoThreadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTwoThreadDoc commands
