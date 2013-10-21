import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0

ApplicationWindow {
    id: mainwindow
    //X11BypassWindowManagerHint
    flags: "WindowDoesNotAcceptFocus|WindowStaysOnTopHint" //QtCreator report an invalid error there, just ignore it
    width: keyboard1.implicitWidth
    height: keyboard1.implicitHeight
    Keyboard {
        id: keyboard1
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
    }
}
