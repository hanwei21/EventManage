package com.hanwei.Native;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 15:34
 */
public class EventSendClassNative {
    public static native long jni_CreateObj();

    public static native void jni_DeleteObj(long handle);

    public static native long GetSendEvent1(long handle);

    public static native long GetSendEvent2(long handle);

    public static native void SendEvent1(long handle);

    public static native void SendEvent2(long handle);
}
