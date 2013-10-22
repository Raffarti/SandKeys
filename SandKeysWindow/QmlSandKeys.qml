import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0

ApplicationWindow {
    id: mainwindow
    //X11BypassWindowManagerHint
    opacity: 0.75
    flags: "WindowDoesNotAcceptFocus|WindowStaysOnTopHint" //QtCreator report an invalid error there, just ignore it
   // width: keyboard1.implicitWidth
  //  height: keyboard1.implicitHeight

    property Item currentKeyboard
    function setKeyboard(arg1){
        if (currentKeyboard) currentKeyboard.destroy()
        var keyboard = Qt.createComponent(arg1)
        keyboard = keyboard.createObject(keyboard1)
        keyboard.anchors.fill = keyboard1
        mainwindow.width = keyboard.implicitWidth
        mainwindow.height = keyboard.implicitHeight
        currentKeyboard = keyboard
    }

    Rectangle {
        id: keyboard1
        anchors.topMargin: 0
        anchors.top: combo_box1.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left

    }

    ComboBox {
        id: combo_box1
        width: 320
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top

        model: ListModel{
            ListElement{
                text: "Black"
            }
            ListElement{
                text: "LightWeight"
            }
        }
        onCurrentIndexChanged: {
            switch(currentIndex){
            case 0: setKeyboard("../QmlSandKeys/Keyboard.qml"); break
            case 1: setKeyboard("../QmlSandKeysLightWeight/Keyboard.qml"); break
            }
        }
    }
}
