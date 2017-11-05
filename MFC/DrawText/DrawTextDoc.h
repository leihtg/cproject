// DrawTextDoc.h : interface of the CDrawTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWTEXTDOC_H__E0279156_7724_467A_838D_EA4F6E81AA13__INCLUDED_)
#define AFX_DRAWTEXTDOC_H__E0279156_7724_467A_838D_EA4F6E81AA13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawTextDoc : public CDocument
{
protected: // create from serialization only
	CDrawTextDoc();
	DECLARE_DYNCREATE(CDrawTextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWTEXTDOC_H__E0279156_7724_467A_838D_EA4F6E81AA13__INCLUDED_)
