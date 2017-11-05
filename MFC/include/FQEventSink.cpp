#pragma once
#include <afxctl.h>


/////////////////////////////////////////////////////////////////////////////////////////////////
//

#define BEGIN_IMPLEMENT_FQ_EVENT_SINK(Object, DIID)\
CFQEventSink##Object::CFQEventSink##Object()\
{\
	m_dwCookie = 0;\
	m_pFQ##Object = NULL;\
	EnableAutomation();\
}\
CFQEventSink##Object::~CFQEventSink##Object()\
{\
	if (m_pFQ##Object != NULL)\
		VERIFY(Unadvise());\
}\
BEGIN_MESSAGE_MAP(CFQEventSink##Object, CCmdTarget)\
END_MESSAGE_MAP()\
BEGIN_INTERFACE_MAP(CFQEventSink##Object, CCmdTarget)\
	INTERFACE_PART(CFQEventSink##Object, DIID, Dispatch)\
END_INTERFACE_MAP()\
BOOL CFQEventSink##Object::Advise(IFQ##Object* pFQ##Object)\
{\
	if (m_pFQ##Object == NULL)\
	{\
		if (::AfxConnectionAdvise(pFQ##Object, DIID, GetIDispatch(FALSE), TRUE, &m_dwCookie))\
		{\
			m_pFQ##Object = pFQ##Object;\
		}\
		else\
		{\
			m_dwCookie = 0;\
		}\
	}\
	return (m_pFQ##Object != NULL);\
}\
BOOL CFQEventSink##Object::Unadvise()\
{\
	if (m_pFQ##Object == NULL || m_dwRef <= 1)\
		return FALSE;\
	if (::AfxConnectionUnadvise(m_pFQ##Object, DIID, GetIDispatch(FALSE), TRUE, m_dwCookie))\
	{\
		m_pFQ##Object = NULL;\
		return TRUE;\
	}\
	return FALSE;\
}\
BEGIN_DISPATCH_MAP(CFQEventSink##Object, CCmdTarget)

#define IMPLEMENT_FQ_EVENT(Object, id, Event, ExternalName, RetVal, Params)\
	DISP_FUNCTION_ID(CFQEventSink##Object, ExternalName, id, evt_##Event, RetVal, Params)

#define END_IMPLEMENT_FQ_EVENT_SINK()\
END_DISPATCH_MAP()

//////////////////////////////////////////////////////////////////////////

#define BEGIN_IMPLEMENT_EVENT_SINK(Object, DIID)\
CEventSink##Object::CEventSink##Object()\
{\
	m_dwCookie = 0;\
	m_p##Object = NULL;\
	EnableAutomation();\
}\
CEventSink##Object::~CEventSink##Object()\
{\
	if (m_p##Object != NULL)\
		VERIFY(Unadvise());\
}\
BEGIN_MESSAGE_MAP(CEventSink##Object, CCmdTarget)\
END_MESSAGE_MAP()\
BEGIN_INTERFACE_MAP(CEventSink##Object, CCmdTarget)\
	INTERFACE_PART(CEventSink##Object, DIID, Dispatch)\
END_INTERFACE_MAP()\
BOOL CEventSink##Object::Advise(I##Object* p##Object)\
{\
	if (m_p##Object == NULL)\
	{\
		if (::AfxConnectionAdvise(p##Object, DIID, GetIDispatch(FALSE), FALSE, &m_dwCookie))\
		{\
			m_p##Object = p##Object;\
		}\
		else\
		{\
			m_dwCookie = 0;\
		}\
	}\
	return (m_p##Object != NULL);\
}\
BOOL CEventSink##Object::Unadvise()\
{\
	if (m_p##Object == NULL)\
		return FALSE;\
	if (::AfxConnectionUnadvise(m_p##Object, DIID, GetIDispatch(FALSE), FALSE, m_dwCookie))\
	{\
		m_p##Object = NULL;\
		return TRUE;\
	}\
	return FALSE;\
}\
BEGIN_DISPATCH_MAP(CEventSink##Object, CCmdTarget)

#define IMPLEMENT_EVENT(Object, id, Event, ExternalName, RetVal, Params)\
	DISP_FUNCTION_ID(CEventSink##Object, ExternalName, id, evt_##Event, RetVal, Params)

#define END_IMPLEMENT_EVENT_SINK()\
END_DISPATCH_MAP()