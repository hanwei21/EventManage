package com.hanwei.manage;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 15:11
 */
public abstract class InternalManager  extends InternalHandle {

    /**
     * 构造函数，在构造对象的同时调用抽象接口createObj创建内部对象，同时设置操作状态为可任意使用的
     */
    protected InternalManager()
    {
        super();
        setHandle(createObj());
        m_disposable = true;
    }

    /**
     * 复制构造函数，用于构造在外部实例化的对象，直接将句柄传进来
     * @param handle 待设置的对象句柄
     */
    protected InternalManager(long handle)
    {
        super();
        setHandle(handle);
        m_disposable = false;
    }

    /**
     * 抽象函数，用于派生类去实现它的内部对象构建过程
     * @return	: 内部对象句柄
     */
    protected abstract long createObj();

    /**
     * 抽象函数，用于派生类去实现它的内部对象删除过程
     */
    protected abstract void deleteObj();

    /**
     * 显式删除对象时统一接口调用，对象使用完毕后，需显示调用该接口来做内存清理工作
     *
     * 注：在删除的时候会首先去判断对象的操作状态，当操作状态为false的时候内部对象不会被删除
     */
    public void dispose()
    {
        if(getIsDisposable() && getHandle() != 0L)
            deleteObj();
    }

    /**
     * 获取对象的操作状态
     * @return 对象的操作状态
     */
    public boolean getIsDisposable()
    {
        return m_disposable;
    }

    /**
     * 设置对象的操作状态
     * @param flag 对象的操作状态
     */
    public void setIsDisposable(boolean flag)
    {
        m_disposable = flag;
    }

    /**
     * 派生接口，java虚拟机内存清理时自动内部调用
     */
    @Override
    protected void finalize()
    {
        if(getIsDisposable() && getHandle() != 0L)
            deleteObj();
    }

    /**
     * 静态函数，获取任意对象的操作状态
     * @param	internalhandleManager 要操作的对象
     * @return	该对象的操作状态
     */
    protected static boolean getIsDisposable(InternalManager internalhandleManager)
    {
        return internalhandleManager.getIsDisposable();
    }

    /**
     * 静态函数，设置任意对象的操作状态
     * @param	internalhandleManager 	要操作的对象
     * @param	flag 					要设置的对象操作状态
     */
    protected static void setIsDisposable(InternalManager internalhandleManager, boolean flag)
    {
        internalhandleManager.setIsDisposable(flag);
    }

    /**
     * 成员变量，记录对象的操作状态，该参数的引入主要是为了增加对象的安全性，
     * 对于用户设置为false的对象，即被设置为不可任意操作的对象，在显示调用
     * 删除操作时不会被删除，除非使用者重新将对象设置为可任意操作
     */
    private boolean m_disposable;
}
