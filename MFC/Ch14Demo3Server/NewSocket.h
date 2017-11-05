#if !defined(AFX_NEWSOCKET_H__E91BE46E_2D68_4E7D_B13C_F9E115E9715A__INCLUDED_)
#define AFX_NEWSOCKET_H__E91BE46E_2D68_4E7D_B13C_F9E115E9715A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CNewSocket command target

class CNewSocket : public CAsyncSocket
{
// Attributes
public:
	UINT m_nLength;
	char m_szBuffer[4096];
// Operations
public:
	CNewSocket();
	virtual ~CNewSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CNewSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWSOCKET_H__E91BE46E_2D68_4E7D_B13C_F9E115E9715A__INCLUDED_)
