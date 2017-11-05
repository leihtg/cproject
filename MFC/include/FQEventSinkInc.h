#pragma once
#include "FQEventSink.h"


BEGIN_FQ_EVENT_SINK(ModuleSite)
	FQ_EVENT(OnDataReceived, (LPCTSTR key), (key));
	FQ_EVENT(OnViewData, (LPCTSTR key, LPCTSTR Result), (key, Result));
	FQ_EVENT(OnSendDataResult, (LPCTSTR Sender, LPCTSTR key, enum FQ_SENDDATA_RESULT nResult), (Sender, key, nResult));
END_FQ_EVENT_SINK()

BEGIN_FQ_EVENT_SINK(Root)
	FQ_EVENT(OnUserEnter, (LPCTSTR Memo, LPCTSTR Name, LPCTSTR Host, LPCTSTR Login, LPCTSTR MemoGroup, LPCTSTR Group, LPCTSTR IP, LPCTSTR MAC), (Memo, Name, Host, Login, MemoGroup, Group, IP, MAC));
	FQ_EVENT(OnUserExit, (LPCTSTR Memo, LPCTSTR Name, LPCTSTR Host, LPCTSTR Login, LPCTSTR MemoGroup, LPCTSTR Group, LPCTSTR IP, LPCTSTR MAC), (Memo, Name, Host, Login, MemoGroup, Group, IP, MAC));
	FQ_EVENT(OnSkinChange, (COLORREF clrFrame, COLORREF clrFont, COLORREF clrLeftTop, COLORREF clrRightBtm), (clrFrame, clrFont, clrLeftTop, clrRightBtm));
	FQ_EVENT(OnFolderBarChange, (LONG nBeforeBarIndex, LONG nNowBarIndex), (nBeforeBarIndex, nNowBarIndex));
	FQ_EVENT(BeforeRecvMsg, (LPCTSTR Memo, LPCTSTR Host, LPCTSTR Group, LPCTSTR IP, LPCTSTR MAC, LPCTSTR sendMsg, LPCTSTR font, enum FQ_BEFORERECVMSG_RESULT *pResult), (Memo, Host, Group, IP, MAC, sendMsg, font, pResult));
END_FQ_EVENT_SINK()
