#pragma once

// FeiqModule.h : header file
//


#include "..\include\FQEventSinkInc.h"
/////////////////////////////////////////////////////////////////////////////
// CFeiqModule command target

class CFeiqModule : public CCmdTarget
{
	DECLARE_DYNCREATE(CFeiqModule)
	DECLARE_EVENT_RECEIVER(CFeiqModule)

	CFeiqModule();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFeiqModule)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFeiqModule();

	// Generated message map functions
	//{{AFX_MSG(CFeiqModule)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	BEGIN_DUAL_INTERFACE_PART(FQModule, IFQModule)
	STDMETHOD(raw_OnLoad)(/*[in]*/ IDispatch* FQModuleSite);
	STDMETHOD(raw_OnUnload)();
	STDMETHOD(raw_OnConfig)();
	STDMETHOD(get_Identifier)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Description)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Author)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ModuleSite)(/*[out, retval]*/ IDispatch* *pVal)
	{
		METHOD_PROLOGUE(CFeiqModule, FQModule)
		
		FQ_CHECK_INVALIDARG_NULL(pVal);
		
		*pVal = pThis->m_ptrModuleSite;

		if (*pVal != NULL)
		{
			(*pVal)->AddRef();
		}

		return *pVal != NULL ? S_OK : E_FAIL;
	}
	END_DUAL_INTERFACE_PART(FQModule)	

	BEGIN_DUAL_INTERFACE_PART(MenuSink, IFQUICommand)
    STDMETHOD(raw_OnInvoke)( enum FQ_UI_TYPE Type, long Id, VARIANT Parameter );
    STDMETHOD(raw_OnQueryState) (enum FQ_UI_TYPE Type, long Id, VARIANT Parameter,
                                 BSTR * bstrText,
                                 enum FQ_UI_ITEM_STATE * State );
	END_DUAL_INTERFACE_PART(MenuSink)

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CFeiqModule)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CFeiqModule)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

private:
	IFQModuleSitePtr m_ptrModuleSite;
	IFQRootPtr m_ptrRoot;
	CFQEventSinkModuleSite m_ModuleSiteEventSink;
	CFQEventSinkRoot m_RootEventSink;

	IFQMenuPtr m_ptrMenu;
	int m_AddMenuID;

public:
	HRESULT OnLoad(IDispatch* FQModuleSite);
	HRESULT OnUnload();
	HRESULT OnConfig();
	HRESULT get_Identifier(BSTR* pVal);
	HRESULT get_Name(BSTR* pVal);
	HRESULT get_Description(BSTR* pVal);
	HRESULT get_Author(BSTR* pVal);

	HRESULT OnSendDataResult(LPCTSTR Sender, LPCTSTR key, enum FQ_SENDDATA_RESULT);
	HRESULT OnDataReceived(LPCTSTR key);
	HRESULT OnViewData(LPCTSTR key, LPCTSTR Result);

	HRESULT MenuOnInvoke(enum FQ_UI_TYPE Type, long Id, VARIANT Parameter );

	HRESULT OnUserEnter(LPCTSTR userMemoName, LPCTSTR userNickName, LPCTSTR userHostName, LPCTSTR userLoginName, LPCTSTR userMemoGroupName, LPCTSTR userGroupName, LPCTSTR userIP, LPCTSTR userMAC);
	HRESULT OnUserExit(LPCTSTR userMemoName, LPCTSTR userNickName, LPCTSTR userHostName, LPCTSTR userLoginName, LPCTSTR userMemoGroupName, LPCTSTR userGroupName, LPCTSTR userIP, LPCTSTR userMAC);
	HRESULT OnSkinChange(COLORREF clrFrame, COLORREF clrFont, COLORREF clrLeftTop, COLORREF clrRightBtm);
	HRESULT BeforeRecvMsg(LPCTSTR MemoName, LPCTSTR Host, LPCTSTR Group, LPCTSTR IP, LPCTSTR MAC, LPCTSTR sendMsg, LPCTSTR font, enum FQ_BEFORERECVMSG_RESULT *pResult);
	HRESULT OnFolderBarChange(LONG nBeforeBarIndex, LONG nNowBarIndex);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

