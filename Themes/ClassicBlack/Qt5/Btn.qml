import QtQuick 2.0
import sandkeys.plugin 1.0 as KE

Rectangle {
    id: background
    width: 18
    height: 18
    property int keyCode;
    color: "#000000"

    Rectangle {
        id: btn
        radius: 1
        anchors.fill: parent
        color: "#3c3c3c"

        MouseArea {

            id: mousearea1
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.top: parent.top

            onPressed: {
                background.state = "Pressed"
                KE.KeyboardEngine.keyPress(keyCode, 1)
            }
            onReleased: {
                background.state = "Base State"
                KE.KeyboardEngine.keyPress(keyCode, 0)
            }
            Rectangle {
                function textSize(text,width,height){
                    text = String(text)
                    var rows = text.split("<br>")
                    var lens = []
                    rows.forEach(function(el){lens.push(el.length)})
                    var a = 0.0
                    var b = 0.8
                    var x = a * width/Math.max.apply(null,lens) + b * width/Math.sqrt(Math.max.apply(null,lens))
                    var y = a * height/rows.length + b * height/Math.pow(rows.length,0.5)
                    return Math.min(x,y)
                }

                id: inner
                radius: 1
                anchors.rightMargin: 2
                anchors.leftMargin: 2
                anchors.bottomMargin: 2
                anchors.topMargin: 1
                anchors.fill: parent
                color: "#000000"
                border.color: "#000000"

                onWidthChanged: text.font.pixelSize = textSize(text.text, width, height)
                onHeightChanged: text.font.pixelSize = textSize(text.text, width, height)
                Text {
                    id: text
                    color: "#ffffff"
                    text: KE.KeyboardEngine.keySym(keyCode)
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.rightMargin: 1
                    anchors.leftMargin: 1
                    anchors.bottomMargin: 1
                    anchors.topMargin: 1
                    font.pointSize: 6
                    anchors.fill: parent
                    onTextChanged: font.pixelSize = inner.textSize(text, inner.width, inner.height)
                    transformOrigin: Item.Center
                    styleColor: "#c8c8c8"
                }
            }
        }
        ColorAnimation on color{
            id: resetAnim
            running: false
            to: "#3c3c3c";
            duration: 75
        }

        ColorAnimation on color{
            id: latchAnim
            running: false
            to: "yellow";
            duration: 75
        }
        ColorAnimation on color{
            id: lockAnim
            running: false
            to: "green";
            duration: 50
        }
        ColorAnimation on color{
            id: effectiveAnim
            running: false
            to: "red";
            duration: 50
        }
    }
    states: [
        State {
            name: "Pressed"

            PropertyChanges {
                target: btn
                anchors.topMargin: 1
            }

            PropertyChanges {
                target: inner
                anchors.bottomMargin: 1
            }
        }
    ]

    function activate(){
        effectiveAnim.start();
    }

    function reset(){
        resetAnim.start()
    }
    function lock(){
        lockAnim.start()
    }
    function latch(){
        latchAnim.start()
    }
    function refresh(){
        text.text = KE.KeyboardEngine.keySym(keyCode)
    }
}
