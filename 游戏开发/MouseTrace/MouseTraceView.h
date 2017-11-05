// MouseTraceView.h : interface of the CMouseTraceView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOUSETRACEVIEW_H__FD3663A4_83AB_4B1B_B19F_DA3689FFB6C8__INCLUDED_)
#define AFX_MOUSETRACEVIEW_H__FD3663A4_83AB_4B1B_B19F_DA3689FFB6C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMouseTraceView : public CView
{
protected: // create from serialization only
	CMouseTraceView();
	DECLARE_DYNCREATE(CMouseTraceView)

// Attributes
public:
	CMouseTraceDoc* GetDocument();
private:
	CString m_showMsg;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseTraceView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMouseTraceView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMouseTraceView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MouseTraceView.cpp
inline CMouseTraceDoc* CMouseTraceView::GetDocument()
   { return (CMouseTraceDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSETRACEVIEW_H__FD3663A4_83AB_4B1B_B19F_DA3689FFB6C8__INCLUDED_)
