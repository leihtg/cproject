// MyPlayerControl.h: interface for the CMyPlayerControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPLAYERCONTROL_H__1135C51F_50A6_4034_81A4_D095F900C074__INCLUDED_)
#define AFX_MYPLAYERCONTROL_H__1135C51F_50A6_4034_81A4_D095F900C074__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

class CMyPlayerControl  
{
public:
	CMyPlayerControl();
	virtual ~CMyPlayerControl();
public:
	BOOL Open(LPCSTR lpFileName);
	void Play();
	void Close();
	void Stop();
	void Pause();
	DWORD GetLength(DWORD dwItem);
	void SetWindowHwnd(HWND hWnd);
private:
	MCI_OPEN_PARMS mciOpen;//打开设备参数
	HWND m_hWnd;
	DWORD dwFrom;

};

#endif // !defined(AFX_MYPLAYERCONTROL_H__1135C51F_50A6_4034_81A4_D095F900C074__INCLUDED_)
