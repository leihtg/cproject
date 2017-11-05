// MyPlayerControl.cpp: implementation of the CMyPlayerControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Mp3Play.h"
#include "MyPlayerControl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyPlayerControl::CMyPlayerControl()
{

}

CMyPlayerControl::~CMyPlayerControl()
{
	Close();
}

DWORD CMyPlayerControl::GetLength(DWORD dwItem){
	MCI_STATUS_PARMS mcistatusparms;
	mcistatusparms.dwCallback=(DWORD)m_hWnd;
	mcistatusparms.dwItem=dwItem;
	mcistatusparms.dwReturn=0;
	mciSendCommand(mciOpen.wDeviceID,MCI_STATUS,MCI_STATUS_ITEM,(DWORD)&mcistatusparms);
	return mcistatusparms.dwReturn;
}

BOOL CMyPlayerControl::Open(LPCSTR lpFileName){
	if(mciOpen.wDeviceID){
		Close();//如果有打开的MCI设备就关闭
	}
	mciOpen.lpstrDeviceType=NULL;//初始化MCI_OPEN_PARMS结构中的文件类型
	mciOpen.lpstrElementName=lpFileName;//播放文件路径
	if(mciSendCommand(0,MCI_OPEN,MCI_DEVTYPE_WAVEFORM_AUDIO,(DWORD)&mciOpen)){
		return FALSE;
	}
	dwFrom=MCI_MAKE_HMS(0,0,0);//起始位置为0
	return TRUE;
}

void CMyPlayerControl::Play(){
	MCI_PLAY_PARMS mciplayparms;
	DWORD cdlen=GetLength(MCI_STATUS_LENGTH);
	DWORD cdto=MCI_MAKE_HMS(MCI_HMS_HOUR(cdlen),MCI_HMS_MINUTE(cdlen),MCI_HMS_SECOND(cdlen));
	mciplayparms.dwCallback=NULL;
	mciplayparms.dwFrom=dwFrom;
	mciplayparms.dwTo=cdto;
	if(mciOpen.wDeviceID!=0){
		mciSendCommand(mciOpen.wDeviceID,MCI_PLAY,MCI_TO|MCI_FROM,(DWORD)(LPVOID)&mciplayparms);

	}
}

void CMyPlayerControl::Close(){
	if(mciOpen.wDeviceID){
		mciSendCommand(mciOpen.wDeviceID,MCI_CLOSE,NULL,NULL);
	}

}
void CMyPlayerControl::Stop(){
	if(mciOpen.wDeviceID){
		mciSendCommand(mciOpen.wDeviceID,MCI_STOP,NULL,NULL);
		mciSendCommand(mciOpen.wDeviceID,MCI_SEEK,MCI_SEEK_TO_START,NULL);

	}
	dwFrom=MCI_MAKE_HMS(0,0,0);
}

void CMyPlayerControl::Pause(){
	if(mciOpen.wDeviceID){
		DWORD dwsf=GetLength(MCI_STATUS_POSITION);
		dwFrom=MCI_MAKE_MSF(MCI_MSF_MINUTE(dwsf),MCI_MSF_SECOND(dwsf),MCI_MSF_FRAME(dwsf));
		mciSendCommand(mciOpen.wDeviceID,MCI_PAUSE,NULL,NULL);
	}
}
void CMyPlayerControl::SetWindowHwnd(HWND hWnd){
	m_hWnd=hWnd;
}