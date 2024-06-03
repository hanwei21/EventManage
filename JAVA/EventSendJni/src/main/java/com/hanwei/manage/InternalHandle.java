package com.hanwei.manage;

public abstract class InternalHandle {


    /**
     * 构造函数
     */
    protected InternalHandle() {
    }

    /**
     * 获取对象句柄
     *
     * @return 对象句柄
     */
    public long getHandle() {
        return m_handle;
    }

    /**
     * 设置对象句柄
     *
     * @param    handle    对象句柄
     */
    public void setHandle(long handle) {
        m_handle = handle;
    }

    /**
     * 静态函数，获取任意对象的句柄
     *
     * @return 对象句柄
     * @param    internalhandle 要操作的对象
     */
    public static long getHandle(InternalHandle internalhandle) {
        return internalhandle.getHandle();
    }

    /**
     * 静态函数，设置任意对象的句柄
     *
     * @param    internalhandle 要操作的对象
     * @param    handle 对象句柄
     */
    public static void setHandle(InternalHandle internalhandle, long handle) {
        internalhandle.setHandle(handle);
    }

    /**
     * 清空句柄，赋值为零
     */
    public void clearHandle() {
        setHandle(0L);
    }

    protected boolean isHandleValid() {
        if (m_handle == 0L) {
            StackTraceElement[] ts = Thread.currentThread().getStackTrace();
            String methodName = ts[2].getMethodName();
            String s = InternalResource.loadString(methodName, "Handle_ObjectHasBeenDisposed", "data_resources");
            throw new IllegalStateException(s);
        }
        return true;
    }

    /**
     * 成员变量，记录对象句柄值
     */
    private long m_handle;


    /**
     * 调用java组件动态库
     */
    static {
        Environment.loadLib();
    }
}
