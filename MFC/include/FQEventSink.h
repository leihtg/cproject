#pragma once
#include "EventSupport.h"

#define BEGIN_FQ_EVENT_SINK(Object)\
class CFQEventSink##Object : public CCmdTarget\
{\
public:\
	CFQEventSink##Object();\
	virtual ~CFQEventSink##Object();\
public:\
	BOOL Unadvise();\
	BOOL Advise(IFQ##Object* pFQ##Object);\
	DECLARE_MESSAGE_MAP()\
	DECLARE_DISPATCH_MAP()\
	DECLARE_INTERFACE_MAP()\
private:\
	IFQ##Object* m_pFQ##Object;\
	DWORD m_dwCookie;

#define FQ_EVENT(Event, p, v)\
	EVENT(evt_##Event, p, v);

#define END_FQ_EVENT_SINK()\
};

#define BEGIN_EVENT_SINK(Object)\
	class CEventSink##Object : public CCmdTarget\
{\
public:\
	CEventSink##Object();\
	virtual ~CEventSink##Object();\
public:\
	BOOL Unadvise();\
	BOOL Advise(I##Object* p##Object);\
	DECLARE_MESSAGE_MAP()\
	DECLARE_DISPATCH_MAP()\
	DECLARE_INTERFACE_MAP()\
private:\
	I##Object* m_p##Object;\
	DWORD m_dwCookie;

#define _EVENT_(Event, p, v)\
	EVENT(evt_##Event, p, v);

#define END_EVENT_SINK()\
};