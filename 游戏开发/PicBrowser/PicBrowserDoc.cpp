// PicBrowserDoc.cpp : implementation of the CPicBrowserDoc class
//

#include "stdafx.h"
#include "PicBrowser.h"

#include "PicBrowserDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserDoc

IMPLEMENT_DYNCREATE(CPicBrowserDoc, CDocument)

BEGIN_MESSAGE_MAP(CPicBrowserDoc, CDocument)
	//{{AFX_MSG_MAP(CPicBrowserDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserDoc construction/destruction

CPicBrowserDoc::CPicBrowserDoc()
{
	// TODO: add one-time construction code here

}

CPicBrowserDoc::~CPicBrowserDoc()
{
}

BOOL CPicBrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPicBrowserDoc serialization

void CPicBrowserDoc::Serialize(CArchive& ar)
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
// CPicBrowserDoc diagnostics

#ifdef _DEBUG
void CPicBrowserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPicBrowserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicBrowserDoc commands
