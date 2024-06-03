package com.hanwei;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

/**
 * @program: EventSend
 * @description:
 * @author: 韩
 * @create: 2022-06-16 14:05
 */
public class MainForm {
    @FXML
    public Button button_ok;

    @FXML
    public Button button_cancel;


    public void buttonOkOnAction(ActionEvent actionEvent) {

        EventSendClass eventSendClass = new EventSendClass();
        eventSendClass.addSendEvent1Listener(new ITestListener() {
            @Override
            public void TestListener() {

            }

        });
        eventSendClass.addSendEvent2Listener(new ITestListener() {
            @Override
            public void TestListener() {

            }
        });

        eventSendClass.SendEvent1();
        eventSendClass.SendEvent2();
    }

    public void buttonCancelOnAction(ActionEvent actionEvent) {
    }
}
