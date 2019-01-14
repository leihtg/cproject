#pragma once
#include "afxwin.h"
#include "resource.h"
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
	CListBox files;
public:
	virtual BOOL OnInitDialog();
};

