#include "stdafx.h"
#include "EventSend.h"
#include "EventSendClass.h"


CGEventSendClass::CGEventSendClass() {
	INIT_DELEGATE(EventSendClass)
}
CGEventSendClass:: ~CGEventSendClass() {
	DELETE_DELEGATE
}


BEGIN_SET_DELEGATE(CGEventSendClass, PTEventSendClass)
SET_DELEGATE
END_SET_DELEGATE


CGEvent* CGEventSendClass::GetSendEvent1()
{
	if (m_pDelegate != NULL)
		return	m_pDelegate->GetSendEvent1();
	return NULL;
}
CGEvent* CGEventSendClass::GetSendEvent2()
{
	if (m_pDelegate != NULL)
		return m_pDelegate->GetSendEvent2();
	return NULL;
}
void CGEventSendClass::SendEvent1() 
{
	if (m_pDelegate != NULL)
		m_pDelegate->SendEvent1();
}
void CGEventSendClass::SendEvent2() 
{
	if (m_pDelegate != NULL)
		m_pDelegate->SendEvent2();
}

void CGEventSendClass::SendEvent1(GEventArgs* args)
{
	if (m_pDelegate != NULL)
		m_pDelegate->SendEvent1(args);
}
void CGEventSendClass::SendEvent2(GEventArgs* args) 
{
	if (m_pDelegate != NULL)
		m_pDelegate->SendEvent2(args);
}