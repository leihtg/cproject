// »­Í¼1View.h : interface of the CMy1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1VIEW_H__FD108685_39AE_4BB3_9B5C_945652E94E5B__INCLUDED_)
#define AFX_1VIEW_H__FD108685_39AE_4BB3_9B5C_945652E94E5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1View : public CView
{
protected: // create from serialization only
	CMy1View();
	DECLARE_DYNCREATE(CMy1View)

// Attributes
public:
	CMy1Doc* GetDocument();
	int m_drawtype;
// Operations
public:
	CPoint ptstar,ptend;
	BOOL bMove,bDown;
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1View)
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
	virtual ~CMy1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1View)
	afx_msg void Oncancel();
	afx_msg void Onclear();
	afx_msg void Ondrawcircle();
	afx_msg void OnUpdatedrawcircle(CCmdUI* pCmdUI);
	afx_msg void Ondrawline();
	afx_msg void OnUpdatedrawline(CCmdUI* pCmdUI);
	afx_msg void Ondrawrect();
	afx_msg void OnUpdatedrawrect(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in »­Í¼1View.cpp
inline CMy1Doc* CMy1View::GetDocument()
   { return (CMy1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1VIEW_H__FD108685_39AE_4BB3_9B5C_945652E94E5B__INCLUDED_)
