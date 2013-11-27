import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0

ApplicationWindow {
    id: mainwindow
    //X11BypassWindowManagerHint
    opacity: 0.75
    flags: "WindowDoesNotAcceptFocus|WindowStaysOnTopHint|X11BypassWindowManagerHint" //QtCreator report an invalid error there, just ignore it
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
        MouseArea{
            anchors.fill: parent
            z: -1
            property variant previousPosition
            onPressed: {
                previousPosition = Qt.point(mouseX, mouseY)

            }
            onPositionChanged: {
                if (pressedButtons == Qt.LeftButton) {
                    var dx = mouseX - previousPosition.x
                    var dy = mouseY - previousPosition.y
                    mainwindow.x = mainwindow.x + dx
                    mainwindow.y = mainwindow.y + dy
                }
            }
        }

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
            case 0: setKeyboard("/usr/lib64/qt5/qml/sandkeys/theme/ClassicBlack/ClassicBlack.qml"); break
            case 1: setKeyboard("/usr/lib64/qt5/qml/sandkeys/theme/LightWeight/Keyboard.qml"); break
            }
        }
    }
}
