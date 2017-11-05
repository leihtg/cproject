// »­Í¼1Doc.cpp : implementation of the CMy1Doc class
//

#include "stdafx.h"
#include "»­Í¼1.h"

#include "»­Í¼1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1Doc

IMPLEMENT_DYNCREATE(CMy1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy1Doc, CDocument)
	//{{AFX_MSG_MAP(CMy1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1Doc construction/destruction

CMy1Doc::CMy1Doc()
{
	// TODO: add one-time construction code here

}

CMy1Doc::~CMy1Doc()
{
}

BOOL CMy1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy1Doc serialization

void CMy1Doc::Serialize(CArchive& ar)
{
	int count;
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		count=m_graphlist.GetCount();
		ar<<count;
		POSITION pos=m_graphlist.GetHeadPosition();
		for(int i=0;i<count;i++){
			CGraph* m_pGraph=(CGraph*)m_graphlist.GetNext(pos);
			ar<<m_pGraph->m_star;
			ar<<m_pGraph->m_end;
			ar<<m_pGraph->m_type;
		}
	}
	else
	{
		// TODO: add loading code here
		if(!m_graphlist.IsEmpty()){
			m_graphlist.RemoveAll();
		}
		ar>>count;
		for(int i=0;i<count;i++){
			CGraph* m_pGraph=new CGraph();
			ar>>m_pGraph->m_star;
			ar>>m_pGraph->m_end;
			ar>>m_pGraph->m_type;
			m_graphlist.AddTail(m_pGraph);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy1Doc diagnostics

#ifdef _DEBUG
void CMy1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1Doc commands

void CMy1Doc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CDocument::DeleteContents();
}
