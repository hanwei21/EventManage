package com.hanwei.Native;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 15:23
 */
public class EventArgsNative {
    public static native long jni_CreateObj();
    public static native void jni_DeleteObj(long handle);
}
