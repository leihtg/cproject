// CClientDcView.h : interface of the CCClientDcView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CCLIENTDCVIEW_H__0FBDD0C8_CF37_4713_A5AA_364CA9BA4A73__INCLUDED_)
#define AFX_CCLIENTDCVIEW_H__0FBDD0C8_CF37_4713_A5AA_364CA9BA4A73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCClientDcView : public CView
{
protected: // create from serialization only
	CCClientDcView();
	DECLARE_DYNCREATE(CCClientDcView)

// Attributes
public:
	CCClientDcDoc* GetDocument();
	int check;
	CPoint orgin;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCClientDcView)
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
	virtual ~CCClientDcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCClientDcView)
	afx_msg void OnclientDc();
	afx_msg void OnUpdateclientDc(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in CClientDcView.cpp
inline CCClientDcDoc* CCClientDcView::GetDocument()
   { return (CCClientDcDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CCLIENTDCVIEW_H__0FBDD0C8_CF37_4713_A5AA_364CA9BA4A73__INCLUDED_)
