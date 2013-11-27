import QtQuick 1.1
import sandkeys.theme.ClassicBlack 1.0

ClassicBlackKeyboard {
    id: baseWrapper
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
