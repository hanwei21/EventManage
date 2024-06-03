package com.hanwei;

import java.util.EventObject;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 14:57
 */
public class TestEvent extends EventObject {
    /**
     * Constructs a prototypical Event.
     *
     * @param source The object on which the Event initially occurred.
     * @throws IllegalArgumentException if source is null.
     */
    public TestEvent(Object source,TestEventArgs args) {
        super(source);
    }
}
