#if !defined(AFX_SHOWTHREAD_H__9F84A466_2B8B_4EB1_86CF_839C49C11E00__INCLUDED_)
#define AFX_SHOWTHREAD_H__9F84A466_2B8B_4EB1_86CF_839C49C11E00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowThread.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CShowThread thread

class CShowThread : public CWinThread
{
	DECLARE_DYNCREATE(CShowThread)
protected:
	CShowThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CShowThread();

	// Generated message map functions
	//{{AFX_MSG(CShowThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWTHREAD_H__9F84A466_2B8B_4EB1_86CF_839C49C11E00__INCLUDED_)
