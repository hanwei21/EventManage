// ������ DLL �ļ���

#include "stdafx.h"

#include "EventSendBridge.h"

bool EventSendBridge::MapListener::RegisterCallback()
{
	if (m_listener == NULL)
		return false;

	if (this->eventCallback != nullptr)
	{
		// ��֤ί�в��ᱻ�ڴ��ƶ����������յ�   
		this->delegateHandle = GCHandle::Alloc(this->eventCallback);
		// ת��Ϊ����ָ��ע��   
		IntPtr ptHandle = Marshal::GetFunctionPointerForDelegate(this->eventCallback);
		if (m_listener != NULL)
			m_listener->RegisterCallback(static_cast<EventCallBack>(ptHandle.ToPointer()));
	}

	return true;
}

EventSendBridge::MapListener::MapListener()
{
	m_listener = new ListenerTrans();
}

EventSendBridge::MapListener::!MapListener()
{
	// �ͷ�ί�о��   
	if (this->delegateHandle.IsAllocated)
		this->delegateHandle.Free();

	//2013-12-23 (�ɴ���)��������Ҫɾ��??????
	if (m_listener != NULL)
		delete m_listener;
	m_listener = NULL;
}

EventSendBridge::MapListener::~MapListener()
{
	this->!MapListener();
}

IntPtr EventSendBridge::MapListener::Handle::get()
{
	return IntPtr(m_listener);
}



EventSendBridge::EventSendClass::EventSendClass() 
{
	m_native = new CGEventSendClass();
	m_bIsFree = true;

	//ע������࣬�����¼����Ƽ�ס���Ա�ص�
	mapListener1 = gcnew MapListener();
	mapListener2 = gcnew MapListener();

	mapListener1->eventCallback = gcnew MapListener::EventHandle(this, &EventSendBridge::EventSendClass::CallbackMapListener1);
	mapListener2->eventCallback = gcnew MapListener::EventHandle(this, &EventSendBridge::EventSendClass::CallbackMapListener2);
	mapListener1->RegisterCallback();
	mapListener2->RegisterCallback();



	SendEvent1 += gcnew EventSendBridge::EventSendClass::SendEventHandle(this, &EventSendBridge::EventSendClass::OnSendEvent1);
}



void EventSendBridge::EventSendClass::OnSendEvent1(System::Object^ sender, EventArgs^ e) {
	int a = 0;
	a++; 
	a++;
}


void EventSendBridge::EventSendClass::CallbackMapListener1(void* handle)
{
	SendEvent1(this, gcnew EventArgs());
}
void EventSendBridge::EventSendClass::CallbackMapListener2(void* handle)
{
	SendEvent2(this, gcnew EventArgs());
}



void EventSendBridge::EventSendClass::SetSendEvent1()
{
	if (m_native != NULL)
		m_native->SendEvent1();
}
void EventSendBridge::EventSendClass::SetSendEvent2()
{
	if (m_native != NULL)
		m_native->SendEvent2();
}


EventSendBridge::EventSendClass::EventSendClass(IntPtr handle)
{
	m_native = static_cast<CGEventSendClass*>(handle.ToPointer());
	m_bIsFree = false;
	mapListener1 = gcnew MapListener();
	mapListener2 = gcnew MapListener();

	mapListener1->eventCallback = gcnew MapListener::EventHandle(this, &EventSendBridge::EventSendClass::CallbackMapListener1);
	mapListener2->eventCallback = gcnew MapListener::EventHandle(this, &EventSendBridge::EventSendClass::CallbackMapListener2);
}

EventSendBridge::EventSendClass::~EventSendClass()
{
	if (m_bIsFree)
		delete m_native;


}