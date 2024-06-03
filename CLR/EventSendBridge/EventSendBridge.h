// EventSendBridge.h

#pragma once
#include "ListenerBridge.h"
#include "EventSend.h"
using namespace System;
using namespace System;
using namespace System::Runtime::InteropServices;


namespace EventSendBridge {

	

	/// <summary>
	/// 托管监听类
	/// </summary>
	private ref class MapListener
	{
	private:
		ListenerTrans*		m_listener;
	private:
		GCHandle delegateHandle;
	public:
		delegate void EventHandle(void* handle);
		//地图视图事件
		EventHandle^ eventCallback;
	public:
		bool RegisterCallback();

		MapListener();
		!MapListener();
		~MapListener();

		property IntPtr Handle
		{
			IntPtr get();
		}
	};

	public ref class  EventSendClass
	{
	public:
		EventSendClass();
		~EventSendClass();
		EventSendClass(IntPtr handle);


		void SetSendEvent1();
		void SetSendEvent2();
		delegate void SendEventHandle(System::Object^ sender, EventArgs^ e);
	
	private:
		SendEventHandle^ m_PreMoveMap;
	public:
		event SendEventHandle^ SendEvent1
		{
	public:
			void add(SendEventHandle^ d)
			{
				if (m_PreMoveMap == nullptr)
				{
					m_native->GetSendEvent1()->Add(static_cast<ListenerTrans*>(mapListener1->Handle.ToPointer()));
				}
				m_PreMoveMap += d;
			}
			void remove(SendEventHandle^ d)
			{
				m_PreMoveMap -= d;
				if (m_PreMoveMap == nullptr)
				{
					m_native->GetSendEvent1()->Remove(static_cast<ListenerTrans*>(mapListener1->Handle.ToPointer()));
				}
			}
	private:
			void raise(System::Object^ sender, EventArgs^ e) 
			{
				if (m_PreMoveMap)
					m_PreMoveMap(sender, e); 
			}
		};

	private:
		SendEventHandle^ m_PreMoveMap2;
	public:
		event SendEventHandle^ SendEvent2
		{
		public:
			void add(SendEventHandle^ d)
			{
				if (m_PreMoveMap2 == nullptr)
				{
					m_native->GetSendEvent2()->Add(static_cast<ListenerTrans*>(mapListener2->Handle.ToPointer()));
				}
				m_PreMoveMap2 += d;
			}
			void remove(SendEventHandle^ d)
			{
				m_PreMoveMap2 -= d;
				if (m_PreMoveMap2 == nullptr)
				{
					m_native->GetSendEvent2()->Remove(static_cast<ListenerTrans*>(mapListener2->Handle.ToPointer()));
				}
			}
		private:
			void raise(System::Object^ sender, EventArgs^ e)
			{
				if (m_PreMoveMap2)
					m_PreMoveMap2(sender, e);
			}
		};


	private:
		CGEventSendClass *  m_native;
		Boolean             m_bIsFree;
		MapListener^        mapListener1;
		MapListener^        mapListener2;

	private:
		void CallbackMapListener1(void* handle);
		void CallbackMapListener2(void* handle);

		void OnSendEvent1(System::Object^ sender, EventArgs^ e);


	};
	
}
