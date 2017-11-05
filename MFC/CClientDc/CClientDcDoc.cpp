// CClientDcDoc.cpp : implementation of the CCClientDcDoc class
//

#include "stdafx.h"
#include "CClientDc.h"

#include "CClientDcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCClientDcDoc

IMPLEMENT_DYNCREATE(CCClientDcDoc, CDocument)

BEGIN_MESSAGE_MAP(CCClientDcDoc, CDocument)
	//{{AFX_MSG_MAP(CCClientDcDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCClientDcDoc construction/destruction

CCClientDcDoc::CCClientDcDoc()
{
	// TODO: add one-time construction code here

}

CCClientDcDoc::~CCClientDcDoc()
{
}

BOOL CCClientDcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCClientDcDoc serialization

void CCClientDcDoc::Serialize(CArchive& ar)
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
// CCClientDcDoc diagnostics

#ifdef _DEBUG
void CCClientDcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCClientDcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCClientDcDoc commands
