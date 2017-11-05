// MouseTraceDoc.h : interface of the CMouseTraceDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOUSETRACEDOC_H__33FCEACE_01E9_4152_94F4_B4AAB7ED5D17__INCLUDED_)
#define AFX_MOUSETRACEDOC_H__33FCEACE_01E9_4152_94F4_B4AAB7ED5D17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMouseTraceDoc : public CDocument
{
protected: // create from serialization only
	CMouseTraceDoc();
	DECLARE_DYNCREATE(CMouseTraceDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseTraceDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMouseTraceDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMouseTraceDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSETRACEDOC_H__33FCEACE_01E9_4152_94F4_B4AAB7ED5D17__INCLUDED_)
