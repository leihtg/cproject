// UseOcxDoc.h : interface of the CUseOcxDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEOCXDOC_H__4F127E07_52A3_4CA8_9389_5FBE15FC4C76__INCLUDED_)
#define AFX_USEOCXDOC_H__4F127E07_52A3_4CA8_9389_5FBE15FC4C76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUseOcxDoc : public CDocument
{
protected: // create from serialization only
	CUseOcxDoc();
	DECLARE_DYNCREATE(CUseOcxDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseOcxDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseOcxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseOcxDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEOCXDOC_H__4F127E07_52A3_4CA8_9389_5FBE15FC4C76__INCLUDED_)
