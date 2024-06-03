package com.hanwei.manage;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 14:47
 */
public class InternalResource {


    private InternalResource()
    {
    }
    /**
     * 加载字符串。
     *
     * 该方法调用ResourceBundle的getBundle(String)方法并返回结果字符串。
     *
     * @param sDesc 异常的描述，如错误的方法名或变量名
     * @param sErrType 异常的类型
     * @param sRes 资源包的基本名称，此处为静态字符串集属性文件名
     * @return 根据资源类型sRes所合成的字符串
     */
    public static String loadString(String sDesc, String sErrType, String sRes)
    {
        String s;
        s = "";
        if(sDesc != null && sDesc.trim() != "")
            s = (new StringBuilder()).append(sDesc.trim()).append("\n").toString();
        //ResourceBundle resourcebundle = ResourceBundle.getBundle(sRes);
        //return (new StringBuilder()).append(s).append(resourcebundle.getString(sErrType)).toString();
        return (new StringBuilder()).append(s).append(sErrType).toString();
    }//end loadString()
}
