#pragma once
#include "gevent.h"
#include "EventSend.h"
#include <jni.h>


typedef void(__stdcall* EventCallBack)(void*);

class  ListenerTrans : public GListener
{
public:
	ListenerTrans(JNIEnv *env, jobject jobj, CGEvent* pEvent)
	{
		m_eventClass = NULL;
		env->GetJavaVM(&m_jvm);
		m_jclassobj = env->NewGlobalRef(jobj);
		jmethodID mid;
		mid = env->GetMethodID(env->GetObjectClass(m_jclassobj), "getHandle", "()J");
		if (mid != NULL)
		{
			jlong handle = env->CallLongMethod(m_jclassobj, mid);
			if (handle != 0)
				m_eventClass = (CGEventSendClass*)handle;
		}
		m_pEvent = pEvent;
		m_preMoveMapFun = NULL;
		m_isValid = false;
	}
	virtual void OnFire(GEventArgs *args)
	{
		JNIEnv* jniEnv = NULL;
		int state = m_jvm->GetEnv((void**)&jniEnv, 0x00010008);// JNI_VERSION_1_8);
		if (jniEnv != NULL) 
		{
			if (m_eventClass != NULL && m_eventClass->GetSendEvent1() == m_pEvent)
			{
				jmethodID mid;
				mid = jniEnv->GetMethodID(jniEnv->GetObjectClass(m_jclassobj), "eventSendEvent1", "()V");
				if (mid != NULL)
				{
					jniEnv->CallVoidMethod(m_jclassobj, mid);
				}
			}
			else if (m_eventClass != NULL && m_eventClass->GetSendEvent2() == m_pEvent)
			{
				jmethodID mid;
				mid = jniEnv->GetMethodID(jniEnv->GetObjectClass(m_jclassobj), "eventSendEvent2", "(J)V");
				if (mid != NULL)
				{
					 jniEnv->CallVoidMethod(m_jclassobj, mid, args);
				}
			}
		}
	}
	bool IsValid()
	{
		return m_isValid;
	}
	void SetValid(bool isValid)
	{
		m_isValid = isValid;
	}
	bool RegisterCallback()
	{
		if (m_pEvent != NULL)
		{
			m_pEvent->Add(this);
		}
		return true;
	}

	bool UnRegisterEventCallback()
	{
		if (m_pEvent != NULL)
		{
			m_pEvent->Remove(this);
		}
		return true;
	}

private:
	EventCallBack m_preMoveMapFun;
private:
	JavaVM* m_jvm;
	jobject m_jclassobj;
	CGEvent *m_pEvent;
	CGEventSendClass* m_eventClass;
private:
	bool	m_isValid;
};