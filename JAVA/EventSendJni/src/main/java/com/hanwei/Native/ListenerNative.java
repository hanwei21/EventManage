package com.hanwei.Native;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 15:25
 */
public class ListenerNative {
    public static native void jni_RegisterEventCallback(long handle);
    public static native void jni_UnRegisterEventCallback(long handle);
    public static native long jni_CreateListener(Object obj, long handle);
    public static native void jni_DeleteListener(long handle);
}
