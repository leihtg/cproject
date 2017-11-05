// DrawTextView.h : interface of the CDrawTextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWTEXTVIEW_H__16A4F1F5_FFAE_413E_82E5_26DCA980004B__INCLUDED_)
#define AFX_DRAWTEXTVIEW_H__16A4F1F5_FFAE_413E_82E5_26DCA980004B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawTextView : public CView
{
protected: // create from serialization only
	CDrawTextView();
	DECLARE_DYNCREATE(CDrawTextView)

// Attributes
public:
	CDrawTextDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawTextView)
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
	virtual ~CDrawTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawTextView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawTextView.cpp
inline CDrawTextDoc* CDrawTextView::GetDocument()
   { return (CDrawTextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWTEXTVIEW_H__16A4F1F5_FFAE_413E_82E5_26DCA980004B__INCLUDED_)
