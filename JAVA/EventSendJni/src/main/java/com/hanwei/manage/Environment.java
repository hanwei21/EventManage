package com.hanwei.manage;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 14:47
 */
public class Environment {
    public static synchronized void loadLib() {
        if (!isLibLoaded)
            try {
                System.loadLibrary("EventSendJNI");
                isLibLoaded = true;
            } catch (UnsatisfiedLinkError unsatisfiedlinkerror) {
                unsatisfiedlinkerror.printStackTrace();
            } catch (Exception exception) {
                exception.printStackTrace();
            }
    }

    protected static void InternalLoadLib() {
        loadLib();
    }

    private static boolean isLibLoaded = false;
}
