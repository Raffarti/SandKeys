import QtQuick 2.0
import com.raffarti.qmlcomponents 1.0 as KE

Rectangle {
    radius: 0
    width: 18
    height: 18
    property int keyCode;

    id: btn
    color: "#3c3c3c"

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
    MouseArea {

        id: mousearea1
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top

        onPressed:{
            if (btn.color == "#3c3c3c") btn.color = "#000000"
            KE.KeyboardEngine.keyPress(keyCode, 1)
        }
        onReleased:{
            if (btn.color == "#000000")btn.color = "#3c3c3c"
            KE.KeyboardEngine.keyPress(keyCode, 0)
        }
        onWidthChanged: text.font.pixelSize = textSize(text.text, width, height)
        onHeightChanged: text.font.pixelSize = textSize(text.text, width, height)
        Text {
            renderType: Text.NativeRendering
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
            onTextChanged: font.pixelSize = btn.textSize(text, btn.width, btn.height)
            transformOrigin: Item.Center
            styleColor: "#c8c8c8"
        }
    }

    function activate(){
        color = "red"
    }

    function reset(){
        color = "#3c3c3c"
    }
    function lock(){
        color = "green"
    }
    function latch(){
        color = "yellow"
    }
    function refresh(){
        text.text = KE.KeyboardEngine.keySym(keyCode)
    }
}
