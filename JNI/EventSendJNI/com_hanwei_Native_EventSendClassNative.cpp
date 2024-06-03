#include "stdafx.h"
#include "EventSend.h"
#include "com_hanwei_Native_EventSendClassNative.h"

/*
* Class:     com_hanwei_Native_EventSendClassNative
* Method:    jni_CreateObj
* Signature: ()J
*/
JNIEXPORT jlong JNICALL Java_com_hanwei_Native_EventSendClassNative_jni_1CreateObj
(JNIEnv *jniEnv, jclass jcls) 
{
	CGEventSendClass *eventSendClass = new CGEventSendClass();
	if (eventSendClass != NULL)
	{
		return (jlong)eventSendClass;
	}
	return 0;
}

/*
* Class:     com_hanwei_Native_EventSendClassNative
* Method:    jni_DeleteObj
* Signature: (J)V
*/
JNIEXPORT void JNICALL Java_com_hanwei_Native_EventSendClassNative_jni_1DeleteObj
(JNIEnv *jniEnv, jclass jcls , jlong handle)
{
	CGEventSendClass *eventSendClass = (CGEventSendClass*)handle;
	if (eventSendClass != NULL)
		delete eventSendClass;
}

/*
* Class:     com_hanwei_Native_EventSendClassNative
* Method:    GetSendEvent1
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_hanwei_Native_EventSendClassNative_GetSendEvent1
(JNIEnv *jniEnv, jclass jcls, jlong handle) 
{
	CGEventSendClass *eventSendClass = (CGEventSendClass*)handle;
	if (eventSendClass != NULL) 
	{
		return (jlong)eventSendClass->GetSendEvent1();

	}
	return 0;
}

/*
* Class:     com_hanwei_Native_EventSendClassNative
* Method:    GetSendEvent2
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_hanwei_Native_EventSendClassNative_GetSendEvent2
(JNIEnv *jniEnv, jclass jcls, jlong handle) 
{
	CGEventSendClass *eventSendClass = (CGEventSendClass*)handle;
	if (eventSendClass != NULL)
	{
		return (jlong)eventSendClass->GetSendEvent2();

	}
	return 0;
}

/*
* Class:     com_hanwei_Native_EventSendClassNative
* Method:    SendEvent1
* Signature: (J)V
*/
JNIEXPORT void JNICALL Java_com_hanwei_Native_EventSendClassNative_SendEvent1
(JNIEnv *jniEnv, jclass jcls, jlong handle)
{
	CGEventSendClass *eventSendClass = (CGEventSendClass*)handle;
	if (eventSendClass != NULL)
		eventSendClass->SendEvent1();
}

/*
* Class:     com_hanwei_Native_EventSendClassNative
* Method:    SendEvent2
* Signature: (J)V
*/
JNIEXPORT void JNICALL Java_com_hanwei_Native_EventSendClassNative_SendEvent2
(JNIEnv *jniEnv, jclass jcls, jlong handle)
{
	CGEventSendClass *eventSendClass = (CGEventSendClass*)handle;
	if (eventSendClass != NULL)
		eventSendClass->SendEvent2();
}