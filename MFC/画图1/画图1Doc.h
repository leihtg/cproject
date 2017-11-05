// »­Í¼1Doc.h : interface of the CMy1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1DOC_H__0AE2EB69_C348_42E0_B3CF_6F2BB2C90B4D__INCLUDED_)
#define AFX_1DOC_H__0AE2EB69_C348_42E0_B3CF_6F2BB2C90B4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct CGraph{
	CPoint m_star;
	CPoint m_end;
	int m_type;
};

class CMy1Doc : public CDocument
{
protected: // create from serialization only
	CMy1Doc();
	DECLARE_DYNCREATE(CMy1Doc)

// Attributes
public:
	CPtrList m_graphlist;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1DOC_H__0AE2EB69_C348_42E0_B3CF_6F2BB2C90B4D__INCLUDED_)
