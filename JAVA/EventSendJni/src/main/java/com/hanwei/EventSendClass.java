package com.hanwei;

import com.hanwei.Native.EventSendClassNative;
import com.hanwei.Native.ListenerNative;
import com.hanwei.manage.InternalManager;

import javax.security.auth.callback.Callback;
import java.util.*;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 14:52
 */
public class EventSendClass extends InternalManager {

   public EventSendClass(){

   }

    @Override
    protected long createObj() {
        return EventSendClassNative.jni_CreateObj();
    }

    @Override
    protected void deleteObj() {
        EventSendClassNative.jni_DeleteObj(getHandle());
    }

    private Collection SendEvent1List;
    private Collection SendEvent2List;

    //监听器对象句柄
    protected long hListener1;
    //监听器对象句柄
    protected long hListener2;

    /**
     * 添加事件
     *
     * @param listener
     * @return void
     */
    public void addSendEvent1Listener(ITestListener listener) {
        synchronized(this){
            if(hListener1 == 0L)
                hListener1 = ListenerNative.jni_CreateListener(this, EventSendClassNative.GetSendEvent1( getHandle()));
            if (SendEvent1List == null) {
                SendEvent1List = new ArrayList();
            }
            if (SendEvent1List.size() == 0)
                ListenerNative.jni_RegisterEventCallback(hListener1);
            SendEvent1List.add(listener);
        }
    }

    /**
     * 移除事件
     *
     * @param listener
     * @return void
     */
    public void removeSendEvent1Listener(ITestListener listener) {
        synchronized(this){
            if (SendEvent1List == null)
                return;
            SendEvent1List.remove(listener);
            if (SendEvent1List.size() == 0){
                ListenerNative.jni_UnRegisterEventCallback(hListener1);
            }

            if (SendEvent1List == null || SendEvent1List.size() == 0){
                if (hListener1 != 0L) {
                    ListenerNative.jni_DeleteListener(hListener1);
                    hListener1 = 0;
                }
            }
        }
    }
    /**
     * 图层属性改变事件回调函数
     * @return void
     */
    public void eventSendEvent1()
    {
        notifySendEvent1Listeners();
    }

    /**
    /**
     * 通知所有的属性变化监听者
     *
     * @return void
     */
    private void notifySendEvent1Listeners() {
        synchronized(this){
            List<ITestListener> listenerList = new ArrayList<ITestListener>(SendEvent1List);
            for (ITestListener listener : listenerList){
                if (SendEvent1List.contains(listener)) {
                    listener.TestListener();
                }
            }
        }
    }



    /**
     * 添加事件
     *
     * @param listener
     * @return void
     */
    public void addSendEvent2Listener(ITestListener listener) {
        synchronized(this){
            if(hListener2 == 0L)
                hListener2 = ListenerNative.jni_CreateListener(this,EventSendClassNative.GetSendEvent2(getHandle()) );
            if (SendEvent2List == null) {
                SendEvent2List = new ArrayList();
            }
            if (SendEvent2List.size() == 0)
                ListenerNative.jni_RegisterEventCallback(hListener2);
            SendEvent2List.add(listener);
        }
    }

    /**
     * 移除事件
     *
     * @param listener
     * @return void
     */
    public void removeSendEvent2Listener(ITestListener listener) {
        synchronized(this){
            if (SendEvent2List == null)
                return;
            SendEvent2List.remove(listener);
            if (SendEvent2List.size() == 0){
                ListenerNative.jni_UnRegisterEventCallback(hListener2);
            }

            if (SendEvent2List == null || SendEvent2List.size() == 0){
                if (hListener2 != 0L) {
                    ListenerNative.jni_DeleteListener(hListener2);
                    hListener2 = 0;
                }
            }
        }
    }
    /**
     * 图层属性改变事件回调函数
     * @param argsHandle 底层事件参数
     * @return void
     */
    public void eventSendEvent2(long argsHandle)
    {
        notifySendEvent2Listeners();
    }

    /**
     /**
     * 通知所有的属性变化监听者
     *
     * @return void
     */
    private void notifySendEvent2Listeners() {
        synchronized(this){
            List<ITestListener> listenerList = new ArrayList<ITestListener>(SendEvent2List);
            for (ITestListener listener : listenerList){
                if (SendEvent2List.contains(listener)) {
                    listener.TestListener();
                }
            }
        }
    }

    public void SendEvent1(){
        EventSendClassNative.SendEvent1(getHandle());
    }
    public void SendEvent2()
    {
        EventSendClassNative.SendEvent2(getHandle());

    }
}
