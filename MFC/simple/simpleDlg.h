
// simpleDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "MyListBox.h"
#include "afxcmn.h"
#include "SoundRecord.h"
#include "FileTransferDialog.h"

#define WM_RECEIVEBROCAST WM_USER+1
//心跳检测
#define WM_BEAT_HART      WM_USER+2
//文件发送请求
#define WM_FILE_REQ       WM_USER+3
//文件接收请求
#define WM_FILE_RESP      WM_USER+4
#define BROADCAST_PORT    7777


// CsimpleDlg 对话框
class CsimpleDlg : public CDialogEx
{
private:
	//广播
	SOCKET broadcast;
	CSoundRecord record;
public:
	CsimpleDlg(CWnd* pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_SIMPLE_DIALOG };

protected:
	// 实现
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDropFiles(HDROP hDropInfo);

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString name;
	CMyListBox paths;
	afx_msg void OnDelete();
	void doSetKey();
	void InitBroadSocket();
	static DWORD WINAPI recvFromProc(LPVOID lpParameter);
	static DWORD WINAPI broadCastAddress(LPVOID lpParameter);

protected:
	afx_msg LRESULT OnReceivebrocast(WPARAM wParam, LPARAM lParam);
public:
	// 用户列表
	CListCtrl m_userList;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
protected:
	afx_msg LRESULT OnBeatHart(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnFileReq(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnFileResp(WPARAM wParam, LPARAM lParam);
//	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
public:
//	afx_msg UINT OnNotifyFormat(CWnd *pWnd, UINT nCommand);
	afx_msg void OnDblclkUserList(NMHDR *pNMHDR, LRESULT *pResult);
private:
	CFileTransferDialog* fileDialog;
};
//用户信息
class UserInfo{
public:
	int msgType;//消息类型 0是登录 1是传文件
	char userName[120];
	SOCKADDR_IN addr;
};

struct RECVPARAM{
	SOCKET socket;
	HWND hWnd;
};