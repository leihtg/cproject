// FmodalViewView.h : interface of the CFmodalViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FMODALVIEWVIEW_H__07CA0B62_FC06_4CE1_88EA_06FB7A534AF2__INCLUDED_)
#define AFX_FMODALVIEWVIEW_H__07CA0B62_FC06_4CE1_88EA_06FB7A534AF2__INCLUDED_
#include "BrushColorDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFmodalViewView : public CView
{
protected: // create from serialization only
	CFmodalViewView();
	DECLARE_DYNCREATE(CFmodalViewView)

// Attributes
public:
	CFmodalViewDoc* GetDocument();
	int r,g,b;
	CBrushColorDlg* pDialog;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFmodalViewView)
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
	virtual ~CFmodalViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFmodalViewView)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetColor(WPARAM wP,LPARAM lP);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FmodalViewView.cpp
inline CFmodalViewDoc* CFmodalViewView::GetDocument()
   { return (CFmodalViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FMODALVIEWVIEW_H__07CA0B62_FC06_4CE1_88EA_06FB7A534AF2__INCLUDED_)
