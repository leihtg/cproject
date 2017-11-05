// DocView.h : interface of the CDocView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCVIEW_H__8E9B64C4_2112_47CC_B28B_AA6263D6DABD__INCLUDED_)
#define AFX_DOCVIEW_H__8E9B64C4_2112_47CC_B28B_AA6263D6DABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDocView : public CView
{
protected: // create from serialization only
	CDocView();
	DECLARE_DYNCREATE(CDocView)

// Attributes
public:
	CDocDoc* GetDocument();
	int m_nDdrawtype;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocView)
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
	virtual ~CDocView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDocView)
	afx_msg void Oncircle();
	afx_msg void Onrec();
	afx_msg void OnUpdatecircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdaterec(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DocView.cpp
inline CDocDoc* CDocView::GetDocument()
   { return (CDocDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCVIEW_H__8E9B64C4_2112_47CC_B28B_AA6263D6DABD__INCLUDED_)
