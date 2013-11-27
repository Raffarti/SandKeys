import QtQuick 1.1
import sandkeys.theme.ClassicBlack 1.0

Item{
    width: kbd.width
    height: kbd.height + close_btn.height
    id: window
    Item{
        id:kbd_container
        width: kbd.width
        height: kbd.height + close_btn.height
        ClassicBlackKeyboard {
            id: kbd
            anchors.top:close_btn.bottom
        }
        Rectangle {
            id: close_btn
            color: "#80FFFFFF"
            width: 65
            height: 17
            anchors.top: parent.top
            anchors.right: parent.right
            Text{
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15

                text: "Close"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: viewerWidget.close()
            }
        }
        Rectangle {
            id: minimize_btn
            color: "#80FFFFFF"
            width: 75
            height: 17
            anchors.top: parent.top
            anchors.right: close_btn.left
            Text{
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15

                text: "Iconize"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    kbd_container.visible = false
                    window.width = icon.width
                    window.height = icon.height
                }
            }
        }
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
                    viewerWidget.pos = Qt.point(viewerWidget.pos.x + dx,
                                                viewerWidget.pos.y + dy)
                }
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
                    window.width = kbd_container.width
                    window.height = kbd_container.height
                }
            }

            onPositionChanged: {
                if (pressedButtons == Qt.LeftButton) {
                    moved = true
                    var dx = mouseX - previousPosition.x
                    var dy = mouseY - previousPosition.y
                    viewerWidget.pos = Qt.point(viewerWidget.pos.x + dx,
                                                viewerWidget.pos.y + dy)
                }
            }
        }
    }
    onWidthChanged: viewerWidget.geometry.width = window.width
    onHeightChanged: viewerWidget.geometry.height = window.height
}
