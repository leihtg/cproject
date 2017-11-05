// FeiqModule.cpp : implementation file
//

#include "stdafx.h"
#include "FeiqModule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "..\include\FQEventSinkImp.h"



IMPLEMENT_DYNCREATE(CFeiqModule, CCmdTarget)
DELEGATE_DUAL_INTERFACE(CFeiqModule, FQModule)
DELEGATE_DUAL_INTERFACE(CFeiqModule, MenuSink)

CFeiqModule::CFeiqModule()
{
	m_ptrMenu = NULL;
	m_ptrModuleSite = NULL;
	m_ptrRoot = NULL;

	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

CFeiqModule::~CFeiqModule()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}


void CFeiqModule::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CFeiqModule, CCmdTarget)
	//{{AFX_MSG_MAP(CFeiqModule)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFeiqModule, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CFeiqModule)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IFeiqModule to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

static const IID IID_IFeiqModule =
{ 0xf3e8a6d9, 0xe29, 0x462b, { 0x87, 0xaf, 0xbe, 0x0, 0x5e, 0x23, 0x3, 0x2c } };

BEGIN_INTERFACE_MAP(CFeiqModule, CCmdTarget)
	INTERFACE_PART(CFeiqModule, IID_IFeiqModule, Dispatch)
	INTERFACE_PART(CFeiqModule, IID_IFQModule, FQModule)
	INTERFACE_PART(CFeiqModule, IID_IFQUICommand, MenuSink)
END_INTERFACE_MAP()


IMPLEMENT_OLECREATE(CFeiqModule, "FeiQ.FeiqModule", 0xb1aff1d3, 0x8814, 0x43cd, 0x9a, 0xdd, 0xf7, 0xa5, 0x54, 0x10, 0xe6, 0x4e)


STDMETHODIMP CFeiqModule::XFQModule::raw_OnLoad(IDispatch* FQModuleSite)
{
	METHOD_PROLOGUE(CFeiqModule, FQModule)

	return pThis->OnLoad(FQModuleSite);
}

STDMETHODIMP CFeiqModule::XFQModule::raw_OnUnload()
{
	METHOD_PROLOGUE(CFeiqModule, FQModule)

	return pThis->OnUnload();
}

STDMETHODIMP CFeiqModule::XFQModule::raw_OnConfig()
{
	METHOD_PROLOGUE(CFeiqModule, FQModule)

	return pThis->OnConfig();
}

STDMETHODIMP CFeiqModule::XFQModule::get_Identifier(BSTR* pVal)
{
	METHOD_PROLOGUE(CFeiqModule, FQModule)

	return pThis->get_Identifier(pVal);
}


STDMETHODIMP CFeiqModule::XFQModule::get_Name(BSTR* pVal)
{
	METHOD_PROLOGUE(CFeiqModule, FQModule)

	return pThis->get_Name(pVal);
}

STDMETHODIMP CFeiqModule::XFQModule::get_Description(BSTR* pVal)
{
	METHOD_PROLOGUE(CFeiqModule, FQModule)

	return pThis->get_Description(pVal);
}

STDMETHODIMP CFeiqModule::XFQModule::get_Author(BSTR* pVal)
{
	METHOD_PROLOGUE(CFeiqModule, FQModule)

	return pThis->get_Author(pVal);
}

HRESULT CFeiqModule::get_Identifier(BSTR* pVal)
{
	if (NULL == pVal)
	{
		ASSERT(FALSE);
		return E_INVALIDARG;
	}

	*pVal = CString(FQ_MODULE_IDENTIFIER_PLUGINFEEDBACK).AllocSysString();

	return S_OK;
}

HRESULT CFeiqModule::get_Name(BSTR* pVal)
{
	if (NULL == pVal)
	{
		ASSERT(FALSE);
		return E_INVALIDARG;
	}

	*pVal = CString(FQ_MODULE_NAME_PLUGINFEEDBACK).AllocSysString();

	return S_OK;
}

HRESULT CFeiqModule::get_Description(BSTR* pVal)
{
	if (NULL == pVal)
	{
		ASSERT(FALSE);
		return E_INVALIDARG;
	}

	*pVal = CString(FQ_MODULE_DESCRIPTION_PLUGINFEEDBACK).AllocSysString();

	return S_OK;
}


HRESULT CFeiqModule::get_Author(BSTR* pVal)
{
	if (NULL == pVal)
	{
		ASSERT(FALSE);
		return E_INVALIDARG;
	}

	*pVal = CString(FQ_MODULE_AUTHOR_PLUGINFEEDBACK).AllocSysString();

	return S_OK;
}

HRESULT CFeiqModule::OnLoad(IDispatch* FQModuleSite)
{

	if (NULL == FQModuleSite)
	{
		ASSERT(FALSE);
		return E_INVALIDARG;
	}

	FQ_TRY
	{
		
		m_ptrModuleSite = FQModuleSite;
		m_ptrModuleSite->get_FQRoot(&m_ptrRoot);

		CComBSTR identeriferMenu("FeiQ.Menu");
		m_ptrMenu =  m_ptrRoot->Module[(_bstr_t)identeriferMenu];
		IFQUICommand* pUICmd = dynamic_cast<IFQUICommand* >(&m_xMenuSink);
		m_AddMenuID = m_ptrMenu->AddItem(FQ_UI_TYPE_TRAY_MENU, "退出(&C)", pUICmd, "lei||", 0);
		/*
		菜单Text说明:
		形式如 ||测试Group||@@||测试 其中 || 和 @@ 可选。|| 表示分隔符。在名称前加 || 表示在添加的菜单项上面添加分隔符. 
		在名称前后 || 表示在添加的菜单项下面添加分隔符. @@ 是上下级菜单的关系。例子中测试菜单的父菜单是测试Group。当测试Group不存在时，程序会自动创建这组菜单
		*/
		
		m_ModuleSiteEventSink.HookEvent(evt_OnDataReceived, this, &CFeiqModule::OnDataReceived);
		m_ModuleSiteEventSink.HookEvent(evt_OnSendDataResult, this, &CFeiqModule::OnSendDataResult);
		m_ModuleSiteEventSink.HookEvent(evt_OnViewData, this, &CFeiqModule::OnViewData);
	
		if (!m_ModuleSiteEventSink.Advise(m_ptrModuleSite))
		{
			throw FQ_UNSPECIFIC_ERROR;
		}

		m_RootEventSink.HookEvent(evt_OnUserEnter, this, &CFeiqModule::OnUserEnter);
		m_RootEventSink.HookEvent(evt_OnUserExit, this, &CFeiqModule::OnUserExit);
		m_RootEventSink.HookEvent(evt_OnSkinChange, this, &CFeiqModule::OnSkinChange);
		m_RootEventSink.HookEvent(evt_BeforeRecvMsg, this, &CFeiqModule::BeforeRecvMsg);
		m_RootEventSink.HookEvent(evt_OnFolderBarChange, this, &CFeiqModule::OnFolderBarChange);
	
		if (!m_RootEventSink.Advise(m_ptrRoot))
		{
			throw FQ_UNSPECIFIC_ERROR;
		}
		
		return S_OK;
	}
	FQ_CATCH_ALL(return E_FAIL)
}

HRESULT CFeiqModule::OnUnload()
{
	IFQUICommand* pUICmd = dynamic_cast<IFQUICommand* >(&m_xMenuSink);
	if(m_ptrMenu)
	{
		m_ptrMenu->DelItem(FQ_UI_TYPE_TRAY_MENU, m_AddMenuID, pUICmd);
		
	}

	m_ModuleSiteEventSink.Unadvise();
	m_ModuleSiteEventSink.UnhookEvent(evt_OnDataReceived, this, &CFeiqModule::OnDataReceived);
	m_ModuleSiteEventSink.UnhookEvent(evt_OnViewData, this, &CFeiqModule::OnViewData);

	m_RootEventSink.Unadvise();
	m_RootEventSink.UnhookEvent(evt_OnUserEnter, this, &CFeiqModule::OnUserEnter);
	m_RootEventSink.UnhookEvent(evt_OnUserExit, this, &CFeiqModule::OnUserExit);
	m_RootEventSink.UnhookEvent(evt_OnSkinChange, this, &CFeiqModule::OnSkinChange);
	m_RootEventSink.UnhookEvent(evt_BeforeRecvMsg, this, &CFeiqModule::BeforeRecvMsg);
	m_RootEventSink.UnhookEvent(evt_OnFolderBarChange, this, &CFeiqModule::OnFolderBarChange);
	return S_OK;
}

HRESULT CFeiqModule::OnConfig()
{
	//在这里可实现对插件功能的设置，及设置参数的保存及读取
	return S_OK;
}


HRESULT CFeiqModule::OnSendDataResult(LPCTSTR Sender, LPCTSTR key, enum FQ_SENDDATA_RESULT nResult)
{
	//当发送数据后，有返回结果的时候，激发此事件
	return S_OK;
}

HRESULT CFeiqModule::OnDataReceived(LPCTSTR key)
{
	//当接收到数据包的时候，激发此事件
	return S_OK;
}

HRESULT CFeiqModule::OnViewData(LPCTSTR key, LPCTSTR Result)
{
	//当在OnDataReceived 中，没有将Key中的数据包从队列中删除的话，将弹出一个提示框，用户点击提示框的按钮时，将触发OnViewData事件
	return S_OK;
}

HRESULT CFeiqModule::XMenuSink::raw_OnInvoke(enum FQ_UI_TYPE Type, long Id, VARIANT Parameter)
{	
	METHOD_PROLOGUE(CFeiqModule, MenuSink)
	pThis->MenuOnInvoke(Type, Id, Parameter);
	return S_OK;	
}


HRESULT CFeiqModule::XMenuSink::raw_OnQueryState(enum FQ_UI_TYPE Type, long Id, VARIANT Parameter,
                                 BSTR * bstrText,
                                 enum FQ_UI_ITEM_STATE * State )
{
	METHOD_PROLOGUE(CFeiqModule, MenuSink)
	
	return S_OK;
}

HRESULT CFeiqModule::MenuOnInvoke(enum FQ_UI_TYPE Type, long Id, VARIANT Parameter )
{
	//点击自定义的菜单后，会触发此事件
	return S_OK;
}

HRESULT CFeiqModule::OnUserEnter(LPCTSTR userMemoName, LPCTSTR userNickName, LPCTSTR userHostName, LPCTSTR userLoginName, LPCTSTR userMemoGroupName, LPCTSTR userGroupName, LPCTSTR userIP, LPCTSTR userMAC)
{
	//用户上线事件
	return S_OK;
}
HRESULT CFeiqModule::OnUserExit(LPCTSTR userMemoName, LPCTSTR userNickName, LPCTSTR userHostName, LPCTSTR userLoginName, LPCTSTR userMemoGroupName, LPCTSTR userGroupName, LPCTSTR userIP, LPCTSTR userMAC)
{
	//用户下线事件
	return S_OK;
}

HRESULT CFeiqModule::BeforeRecvMsg(LPCTSTR Memo, LPCTSTR Host, LPCTSTR Group, LPCTSTR IP, LPCTSTR MAC, LPCTSTR sendMsg, LPCTSTR font, enum FQ_BEFORERECVMSG_RESULT *pResult)
{
	//接收到消息之前触发此事
	*pResult = FQ_BEFORERECVMSG_RESULT_NORMAL;
	return S_OK;
}

HRESULT CFeiqModule::OnSkinChange(COLORREF clrFrame, COLORREF clrFont, COLORREF clrLeftTop, COLORREF clrRightBtm)
{
	//皮肤颜色改变事件
	return S_OK;
}

HRESULT CFeiqModule::OnFolderBarChange(LONG nBeforeBarIndex, LONG nNowBarIndex)
{
	//主对话框抽屉栏改变事件
	return S_OK;
}


