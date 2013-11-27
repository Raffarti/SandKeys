import QtQuick 1.1
import sandkeys.theme.ClassicBlack 1.0

Item{
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
