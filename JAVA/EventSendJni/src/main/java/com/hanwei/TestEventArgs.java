package com.hanwei;

import com.hanwei.Native.EventArgsNative;
import com.hanwei.manage.InternalManager;
import com.hanwei.manage.InternalResource;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 15:08
 */
public class TestEventArgs  extends InternalManager {
    /**
     * 构造函数
     */
    public TestEventArgs(long handle) {
        super(handle);
        setIsDisposable(false);
    }

    @Override
    protected long createObj() {
        return 0;
    }

    @Override
    protected void deleteObj() {
        if (getHandle() == 0L) {
            String s = InternalResource.loadString("deleteObj",
                    "Handle_ObjectHasBeenDisposed", "data_resources");
            throw new IllegalStateException(s);
        } else {
            EventArgsNative.jni_DeleteObj(getHandle());
            clearHandle();
        }
    }
}
