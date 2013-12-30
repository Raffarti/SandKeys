import QtQuick 2.2
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
    Item{
        id: kbd_container
        anchors.fill: parent
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
            x: 0
            y: 0
            height: 23
            anchors.right: minimize_btn.left
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
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

        Button {
            id: close_btn
            x: 240
            y: 0
            text: "Close"
            anchors.right: parent.right
            anchors.rightMargin: 0
            onClicked: mainwindow.close()
        }

        Button {
            id: minimize_btn
            x: 144
            y: 0
            text: "Minimize"
            anchors.right: close_btn.left
            anchors.rightMargin: 0
            onClicked: {
                kbd_container.visible = false
                kbd_container.implicitWidth = kbd_container.width
                kbd_container.implicitHeight = kbd_container.height
                mainwindow.width = icon.width
                mainwindow.height = icon.height
            }
        }
    }

    Rectangle{
        color: kbd.color
        id: icon
        width: 50
        height: 50
        border.width: 5
        border.color: "#80FFFFFF"
        visible: !kbd_container.visible

        MouseArea{
            anchors.fill: parent
            property variant previousPosition
            property bool moved
            onPressed: {
                previousPosition = Qt.point(mouseX, mouseY)
                moved = false
            }
            onReleased: {
                if (!moved){
                    kbd_container.visible = true
                    mainwindow.width = kbd_container.implicitWidth
                    mainwindow.height = kbd_container.implicitHeight
                }
            }

            onPositionChanged: {
                if (pressedButtons == Qt.LeftButton) {
                    moved = true
                    var dx = mouseX - previousPosition.x
                    var dy = mouseY - previousPosition.y
                    mainwindow.x = mainwindow.x + dx
                    mainwindow.y = mainwindow.y + dy
                }
            }
        }
    }
}
