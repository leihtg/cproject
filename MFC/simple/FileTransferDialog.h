#pragma once
#include "afxwin.h"
#include "resource.h"
#include "afxcmn.h"
class CFileTransferDialog : public CDialogEx
{
public:
	CFileTransferDialog(CWnd* pParent = NULL);	// 标准构造函数
	enum {IDD = IDD_DIALOG1};
	~CFileTransferDialog();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDropFiles(HDROP hDropInfo);
//	CListBox files;
	virtual void DoDataExchange(CDataExchange* pDX);
private:
//	CListBox files;
public:
	virtual BOOL OnInitDialog();
	CEdit msg;
	afx_msg void OnBnClickedSend();
	void scan(CString dir);
	void sendFile();
	CString m_ip;
	int m_port;
	CListCtrl files;
	CString m_fpath;
};

