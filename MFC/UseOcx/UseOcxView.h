// UseOcxView.h : interface of the CUseOcxView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEOCXVIEW_H__94EA4148_A059_4E8C_9963_E3E29059A604__INCLUDED_)
#define AFX_USEOCXVIEW_H__94EA4148_A059_4E8C_9963_E3E29059A604__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUseOcxView : public CView
{
protected: // create from serialization only
	CUseOcxView();
	DECLARE_DYNCREATE(CUseOcxView)

// Attributes
public:
	CUseOcxDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseOcxView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseOcxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseOcxView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UseOcxView.cpp
inline CUseOcxDoc* CUseOcxView::GetDocument()
   { return (CUseOcxDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEOCXVIEW_H__94EA4148_A059_4E8C_9963_E3E29059A604__INCLUDED_)
