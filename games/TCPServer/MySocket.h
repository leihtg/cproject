// MySocket.h: interface for the CMySocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSOCKET_H__569C97E2_E02B_4573_BAC6_5F5DDEF93973__INCLUDED_)
#define AFX_MYSOCKET_H__569C97E2_E02B_4573_BAC6_5F5DDEF93973__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMySocket : public CAsyncSocket  
{
public:
	void setParent(CDialog *pDlg);
	CMySocket();
	virtual ~CMySocket();

protected:
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnAccept(int nErrorCode);

private:
	CDialog *m_pDlg;
};

#endif // !defined(AFX_MYSOCKET_H__569C97E2_E02B_4573_BAC6_5F5DDEF93973__INCLUDED_)
