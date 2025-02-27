/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_hanwei_Native_ListenerNative */

#ifndef _Included_com_hanwei_Native_ListenerNative
#define _Included_com_hanwei_Native_ListenerNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_hanwei_Native_ListenerNative
 * Method:    jni_RegisterEventCallback
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_hanwei_Native_ListenerNative_jni_1RegisterEventCallback
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_hanwei_Native_ListenerNative
 * Method:    jni_UnRegisterEventCallback
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_hanwei_Native_ListenerNative_jni_1UnRegisterEventCallback
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_hanwei_Native_ListenerNative
 * Method:    jni_CreateListener
 * Signature: (Ljava/lang/Object;J)J
 */
JNIEXPORT jlong JNICALL Java_com_hanwei_Native_ListenerNative_jni_1CreateListener
  (JNIEnv *, jclass, jobject, jlong);

/*
 * Class:     com_hanwei_Native_ListenerNative
 * Method:    jni_DeleteListener
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_hanwei_Native_ListenerNative_jni_1DeleteListener
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
