// FmodalViewDoc.h : interface of the CFmodalViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FMODALVIEWDOC_H__47F5E4E8_622B_4640_9B7C_6A17DA545D74__INCLUDED_)
#define AFX_FMODALVIEWDOC_H__47F5E4E8_622B_4640_9B7C_6A17DA545D74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFmodalViewDoc : public CDocument
{
protected: // create from serialization only
	CFmodalViewDoc();
	DECLARE_DYNCREATE(CFmodalViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFmodalViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFmodalViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFmodalViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FMODALVIEWDOC_H__47F5E4E8_622B_4640_9B7C_6A17DA545D74__INCLUDED_)
