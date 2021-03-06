#pragma once

#include "FQEventSink.cpp"


BEGIN_IMPLEMENT_FQ_EVENT_SINK(ModuleSite, DIID__IFQModuleSiteEvents)
	IMPLEMENT_FQ_EVENT(ModuleSite, 1, OnDataReceived, "OnDataReceived", VT_I4, VTS_BSTR)
	IMPLEMENT_FQ_EVENT(ModuleSite, 2, OnViewData, "OnViewData", VT_I4, VTS_BSTR VTS_BSTR)
	IMPLEMENT_FQ_EVENT(ModuleSite, 3, OnSendDataResult, "OnSendDataResult", VT_I4, VTS_BSTR VTS_BSTR VTS_I4)
END_IMPLEMENT_FQ_EVENT_SINK()

BEGIN_IMPLEMENT_FQ_EVENT_SINK(Root, DIID__IFQRootEvents)
	IMPLEMENT_FQ_EVENT(Root, 1, OnUserEnter, "OnUserEnter", VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	IMPLEMENT_FQ_EVENT(Root, 2, OnUserExit, "OnUserExit", VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	IMPLEMENT_FQ_EVENT(Root, 3, OnSkinChange, "OnSkinChange", VT_I4, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	IMPLEMENT_FQ_EVENT(Root, 4, OnFolderBarChange, "OnFolderBarChange", VT_I4, VTS_I4 VTS_I4)
	IMPLEMENT_FQ_EVENT(Root, 5, BeforeRecvMsg, "BeforeRecvMsg", VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4)
END_IMPLEMENT_FQ_EVENT_SINK()
