// CClientDcDoc.h : interface of the CCClientDcDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CCLIENTDCDOC_H__019DEA76_AB41_4377_8570_C2445ECD836E__INCLUDED_)
#define AFX_CCLIENTDCDOC_H__019DEA76_AB41_4377_8570_C2445ECD836E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCClientDcDoc : public CDocument
{
protected: // create from serialization only
	CCClientDcDoc();
	DECLARE_DYNCREATE(CCClientDcDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCClientDcDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCClientDcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCClientDcDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CCLIENTDCDOC_H__019DEA76_AB41_4377_8570_C2445ECD836E__INCLUDED_)
