// MySocket.h: interface for the CMySocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSOCKET_H__16659CD2_4CF4_448E_BBA1_11CE2AB796CB__INCLUDED_)
#define AFX_MYSOCKET_H__16659CD2_4CF4_448E_BBA1_11CE2AB796CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMySocket : public CAsyncSocket  
{
public:
	void SetParent(CDialog *pDlg);
	CMySocket();
	virtual ~CMySocket();
protected:
	virtual void OnClose(int errCode);
	virtual void OnReceive(int errCode);
private:
	CDialog *m_pDlg;
};

#endif // !defined(AFX_MYSOCKET_H__16659CD2_4CF4_448E_BBA1_11CE2AB796CB__INCLUDED_)
