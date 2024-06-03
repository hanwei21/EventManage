#include "stdafx.h"
#include "gevent.h"
#include "ListenerBridge.h"
#include "com_hanwei_Native_ListenerNative.h"

/*
* Class:     com_hanwei_Native_ListenerNative
* Method:    jni_RegisterEventCallback
* Signature: (JI)V
*/
JNIEXPORT void JNICALL Java_com_hanwei_Native_ListenerNative_jni_1RegisterEventCallback
(JNIEnv *jniEnv, jclass jcls, jlong handle)
{
	ListenerTrans *pListerner = (ListenerTrans*)handle;
	if (pListerner != NULL)
	{
		pListerner->RegisterCallback();
	}
}

/*
* Class:     com_hanwei_Native_ListenerNative
* Method:    jni_UnRegisterEventCallback
* Signature: (JI)V
*/
JNIEXPORT void JNICALL Java_com_hanwei_Native_ListenerNative_jni_1UnRegisterEventCallback
(JNIEnv *jniEnv, jclass jcls, jlong handle)
{
	ListenerTrans *pListerner = (ListenerTrans*)handle;
	if (pListerner != NULL)
	{
		pListerner->UnRegisterEventCallback();
	}
}

/*
* Class:     com_hanwei_Native_ListenerNative
* Method:    jni_CreateListener
* Signature: (Ljava/lang/Object;J)J
*/
JNIEXPORT jlong JNICALL Java_com_hanwei_Native_ListenerNative_jni_1CreateListener
(JNIEnv *jniEnv, jclass jcls, jobject jobj, jlong handle)
{
	CGEvent *pEvent = (CGEvent*)handle;
	ListenerTrans *pListerner = new ListenerTrans(jniEnv, jobj, pEvent);
	if (pListerner != NULL)
	{
		return (jlong)pListerner;
	}
	return 0;
}

/*
* Class:     com_hanwei_Native_ListenerNative
* Method:    jni_DeleteListener
* Signature: (J)V
*/
JNIEXPORT void JNICALL Java_com_hanwei_Native_ListenerNative_jni_1DeleteListener
(JNIEnv *jniEnv, jclass jcls, jlong handle)
{
	ListenerTrans *pListerner = (ListenerTrans*)handle;
	if (pListerner != NULL)
		delete pListerner;
}