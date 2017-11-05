// ChatDlg.h : header file
//

#if !defined(AFX_CHATDLG_H__6BEC8327_F477_4C65_A5B1_A38E343E571C__INCLUDED_)
#define AFX_CHATDLG_H__6BEC8327_F477_4C65_A5B1_A38E343E571C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_RECVDATA WM_USER+1
/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog
struct RecvMsg{
	HWND hwnd;
	SOCKET socket;
};
class CChatDlg : public CDialog
{
// Construction
public:
	static DWORD WINAPI RecvProc(LPVOID lp);
	BOOL InitSocket();
	CChatDlg(CWnd* pParent = NULL);	// standard constructor
	
	DWORD GetIP();

// Dialog Data
	//{{AFX_DATA(CChatDlg)
	enum { IDD = IDD_CHAT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void recvData(WPARAM wp,LPARAM lp);
	afx_msg void OnBtnSend();
	afx_msg void Onsendfile();
	afx_msg void OnUpdatesendfile(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	SOCKET m_socket;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDLG_H__6BEC8327_F477_4C65_A5B1_A38E343E571C__INCLUDED_)
