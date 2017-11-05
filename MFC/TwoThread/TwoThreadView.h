// TwoThreadView.h : interface of the CTwoThreadView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TWOTHREADVIEW_H__AE41B349_292E_45DA_8688_826110A9C014__INCLUDED_)
#define AFX_TWOTHREADVIEW_H__AE41B349_292E_45DA_8688_826110A9C014__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTwoThreadView : public CView
{
protected: // create from serialization only
	CTwoThreadView();
	DECLARE_DYNCREATE(CTwoThreadView)

// Attributes
public:
	CTwoThreadDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTwoThreadView)
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
	virtual ~CTwoThreadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTwoThreadView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void Ona();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TwoThreadView.cpp
inline CTwoThreadDoc* CTwoThreadView::GetDocument()
   { return (CTwoThreadDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TWOTHREADVIEW_H__AE41B349_292E_45DA_8688_826110A9C014__INCLUDED_)
