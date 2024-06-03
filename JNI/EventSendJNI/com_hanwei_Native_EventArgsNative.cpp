#include "stdafx.h"
#include "gevent.h"
#include "com_hanwei_Native_EventArgsNative.h"


JNIEXPORT jlong JNICALL Java_com_hanwei_Native_EventArgsNative_jni_1CreateObj(JNIEnv *jniEnv, jclass jcls)
{
	GEventArgs *eventArgs = new GEventArgs();
	if (eventArgs != NULL)
	{
		return (jlong)eventArgs;
	}
	return 0;
}

JNIEXPORT void JNICALL Java_com_hanwei_Native_EventArgsNative_jni_1DeleteObj(JNIEnv *jniEnv, jclass jcls, jlong handle)
{
	GEventArgs *eventArgs = (GEventArgs*)handle;
	if (eventArgs != NULL)
		delete eventArgs;
}