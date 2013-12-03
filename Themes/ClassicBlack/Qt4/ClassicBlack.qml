import QtQuick 1.1
import sandkeys.plugin 1.0 as KE


Rectangle {
    property real implicitScale: 2
    KE.KeyboardEngine {
        id: ke
    }

    id: ext
    implicitWidth: 426*implicitScale
    implicitHeight: 117*implicitScale
    color: "#00000000"
    smooth: false

    property bool initialized: false
    Component.onCompleted: {
        if (initialized) return
        ke.initialize(keyboard);
        initialized = true
    }


    Rectangle {
        id: keyboard
        width: 426*implicitScale
        height: 117*implicitScale

        color: "#222222"
        smooth: true
        transformOrigin: Item.TopLeft
        opacity: 1

        property int normWidth: 18 * implicitScale
        property int normHeight: 18 * implicitScale

        RectBtn {
            id: esc

            width: keyboard.normWidth
            height: keyboard.normHeight

            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            keyCode: 9
        }

        RectBtn {
            id: fk01
            y: 0

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.left: esc.right
            anchors.leftMargin: 20 * implicitScale
            anchors.verticalCenter: esc.verticalCenter

            transformOrigin: Item.Left
            keyCode: 67
        }

        RectBtn {
            id: fk02

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.left: fk01.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk01.verticalCenter

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 68
        }

        RectBtn {
            id: fk03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 69
            anchors.left: fk02.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk02.verticalCenter
        }

        RectBtn {
            id: fk04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 70
            anchors.left: fk03.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk03.verticalCenter
        }

        RectBtn {
            id: fk05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 71
            anchors.left: fk04.right
            anchors.leftMargin: 11 * implicitScale
            anchors.verticalCenter: fk04.verticalCenter
        }

        RectBtn {
            id: fk06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            anchors.left: fk05.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk05.verticalCenter
            keyCode: 72
        }

        RectBtn {
            id: fk07

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 73
            anchors.left: fk06.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk06.verticalCenter
        }

        RectBtn {
            id: fk08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 74
            anchors.left: fk07.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk07.verticalCenter
        }

        RectBtn {
            id: fk09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 75
            anchors.left: fk08.right
            anchors.leftMargin: 11 * implicitScale
            anchors.verticalCenter: fk08.verticalCenter
        }

        RectBtn {
            id: fk10

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            anchors.left: fk09.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk09.verticalCenter
            keyCode: 76
        }

        RectBtn {
            id: fk11

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            anchors.left: fk10.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk10.verticalCenter
            keyCode: 95
        }

        RectBtn {
            id: fk12

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 96
            anchors.left: fk11.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: fk11.verticalCenter
        }

        RectBtn {
            id: prsc

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 107
            anchors.left: fk12.right
            anchors.leftMargin: 5 * implicitScale
            anchors.verticalCenter: fk12.verticalCenter
        }

        RectBtn {
            id: sclk

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 78
            anchors.left: prsc.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: prsc.verticalCenter
        }

        RectBtn {
            id: paus

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23 * implicitScale
            transformOrigin: Item.Left
            anchors.left: sclk.right
            anchors.leftMargin: 1 * implicitScale
            keyCode: 127
            anchors.verticalCenter: sclk.verticalCenter
        }

        RectBtn {
            id: tlde

            width: keyboard.normWidth
            height: keyboard.normHeight

            keyCode: 49
            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: esc.bottom
            anchors.topMargin: 5 * implicitScale
        }

        RectBtn {
            id: ae01

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 10
            transformOrigin: Item.Left
            anchors.left: tlde.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: tlde.verticalCenter
        }


        RectBtn {
            id: ae02

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 11
            anchors.left: ae01.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae01.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ae03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 12
            anchors.left: ae02.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae02.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ae04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 13
            anchors.left: ae03.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae03.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ae05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 14
            anchors.left: ae04.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae04.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ae06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            anchors.left: ae05.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae05.verticalCenter
            transformOrigin: Item.Left
            keyCode: 15
        }

        RectBtn {
            id: ae07

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 16
            anchors.left: ae06.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae06.verticalCenter
        }

        RectBtn {
            id: ae08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            anchors.left: ae07.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae07.verticalCenter
            transformOrigin: Item.Left
            keyCode: 17
        }

        RectBtn {
            id: ae09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 18
            anchors.left: ae08.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae08.verticalCenter
        }

        RectBtn {
            id: ae10

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            anchors.left: ae09.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae09.verticalCenter
            transformOrigin: Item.Left
            keyCode: 19
        }

        RectBtn {
            id: ae11

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 20
            transformOrigin: Item.Left
            anchors.left: ae10.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae10.verticalCenter
        }

        RectBtn {
            id: ae12

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            anchors.left: ae11.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae11.verticalCenter
            transformOrigin: Item.Left
            keyCode: 21
        }

        RectBtn {
            id: bksp

            width: 38 * implicitScale
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 22
            transformOrigin: Item.Left
            anchors.left: ae12.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ae12.verticalCenter
        }

        RectBtn {
            id: tab

            width: 28 * implicitScale
            height: keyboard.normHeight

            x: 20 * implicitScale
            y: 81 * implicitScale
            keyCode: 23
            transformOrigin: Item.TopLeft
            anchors.top: tlde.bottom
            anchors.topMargin: 1 * implicitScale
            anchors.left: parent.left
            anchors.leftMargin: 0
        }


        RectBtn {
            id: ad01

            width: keyboard.normWidth
            height: keyboard.normHeight

            x: 46 * implicitScale
            y: 81 * implicitScale
            transformOrigin: Item.Left
            keyCode: 24
            anchors.left: tab.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: tab.verticalCenter
        }

        RectBtn {
            id: ad02

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ad01.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad01.verticalCenter
            keyCode: 25
        }

        RectBtn {
            id: ad03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            keyCode: 26
            anchors.left: ad02.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad02.verticalCenter
        }

        RectBtn {
            id: ad04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            keyCode: 27
            anchors.left: ad03.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad03.verticalCenter
        }

        RectBtn {
            id: ad05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            keyCode: 28
            transformOrigin: Item.Left
            anchors.left: ad04.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad04.verticalCenter
        }

        RectBtn {
            id: ad06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ad05.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad05.verticalCenter
            keyCode: 29
        }

        RectBtn {
            id: ad07

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            keyCode: 30
            anchors.left: ad06.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad06.verticalCenter
        }

        RectBtn {
            id: ad08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            keyCode: 31
            anchors.left: ad07.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad07.verticalCenter
        }

        RectBtn {
            id: ad09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ad08.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad08.verticalCenter
            keyCode: 32
        }

        RectBtn {
            id: ad10

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ad09.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad09.verticalCenter
            keyCode: 33
        }

        RectBtn {
            id: ad11

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            keyCode: 34
            anchors.left: ad10.right
            anchors.verticalCenter: ad10.verticalCenter
            anchors.leftMargin: 1 * implicitScale
        }

        RectBtn {
            id: ad12

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            keyCode: 35
            anchors.left: ad11.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad11.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: bksl

            width: 28 * implicitScale
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ad12.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ad12.verticalCenter
            keyCode: 51
        }

        RectBtn {
            id: caps

            width: 33 * implicitScale
            height: keyboard.normHeight
            anchors.top: tab.bottom
            anchors.topMargin: 1 * implicitScale

            keyCode: 66
            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        RectBtn {
            id: ac01

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            keyCode: 38
            transformOrigin: Item.Left
            anchors.left: caps.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: caps.verticalCenter
        }

        RectBtn {
            id: ac02

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ac01.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac01.verticalCenter
            keyCode: 39
        }

        RectBtn {
            id: ac03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            keyCode: 40
            anchors.left: ac02.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac02.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ac04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            transformOrigin: Item.Left
            smooth: true
            anchors.left: ac03.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac03.verticalCenter
            keyCode: 41
        }

        RectBtn {
            id: ac05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            keyCode: 42
            anchors.left: ac04.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac04.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ac06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            keyCode: 43
            anchors.left: ac05.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac05.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ac07

            width: keyboard.normWidth
            height: keyboard.normHeight

            x: 153 * implicitScale
            y: 100 * implicitScale
            transformOrigin: Item.Left
            keyCode: 44
            anchors.left: ac06.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac06.verticalCenter
        }

        RectBtn {
            id: ac08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            keyCode: 45
            transformOrigin: Item.Left
            anchors.left: ac07.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac07.verticalCenter
        }

        RectBtn {
            id: ac09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            keyCode: 46
            anchors.left: ac08.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac08.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ac10

            width: keyboard.normWidth
            height: keyboard.normHeight

            x: 210 * implicitScale
            y: 100 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ac09.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac09.verticalCenter
            keyCode: 47
        }

        RectBtn {
            id: ac11

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            transformOrigin: Item.Left
            keyCode: 48
            anchors.left: ac10.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac10.verticalCenter
        }

        RectBtn {
            id: rtrn

            width: 42 * implicitScale
            height: keyboard.normHeight

            y: 100 * implicitScale
            keyCode: 36
            anchors.left: ac11.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ac11.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: lfsh
            width: 42 * implicitScale
            height: keyboard.normHeight
            anchors.top: caps.bottom
            anchors.topMargin: 1 * implicitScale
            transformOrigin: Item.TopLeft
            keyCode: 50
            anchors.left: parent.left
            anchors.leftMargin: 0
/*
            Component.onCompleted: {
                ke.registerModifier(lfsh, ke.Shift)

            }*/
        }

        RectBtn {
            id: ab01
            y: 119 * implicitScale
            width: keyboard.normWidth
            height: keyboard.normHeight
            transformOrigin: Item.Left
            keyCode: 52
            anchors.left: lfsh.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: lfsh.verticalCenter
        }

        RectBtn {
            id: ab02

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            transformOrigin: Item.Left
            keyCode: 53
            anchors.left: ab01.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab01.verticalCenter
        }

        RectBtn {
            id: ab03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ab02.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab02.verticalCenter
            keyCode: 54
        }

        RectBtn {
            id: ab04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            keyCode: 55
            anchors.left: ab03.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab03.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ab05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            transformOrigin: Item.Left
            keyCode: 56
            anchors.left: ab04.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab04.verticalCenter
        }

        RectBtn {
            id: ab06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ab05.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab05.verticalCenter
            keyCode: 57
        }

        RectBtn {
            id: ab07

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            keyCode: 58
            anchors.left: ab06.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab06.verticalCenter
            transformOrigin: Item.Left
        }

        RectBtn {
            id: ab08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            transformOrigin: Item.Left
            keyCode: 59
            anchors.left: ab07.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab07.verticalCenter
        }

        RectBtn {
            id: ab09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            transformOrigin: Item.Left
            keyCode: 60
            anchors.left: ab08.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab08.verticalCenter
        }

        RectBtn {
            id: ab10

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ab09.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab09.verticalCenter
            keyCode: 61
        }

        RectBtn {
            id: rtsh

            height: keyboard.normHeight

            y: 119 * implicitScale
            width: 52 * implicitScale
            keyCode: 62
            anchors.left: ab10.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ab10.verticalCenter
            transformOrigin: Item.Left
/*
            Component.onCompleted: {
                ke.registerModifier(rtsh, ke.Shift)

            }*/
        }

        RectBtn {
            id: lctl

            height: keyboard.normHeight
            anchors.top: lfsh.bottom
            anchors.topMargin: 1 * implicitScale
            anchors.left: parent.left
            anchors.leftMargin: 0

            width: 27 * implicitScale
            keyCode: 37
/*
            Component.onCompleted: {
                ke.registerModifier(lctl, ke.Ctrl)

            }*/

        }

        RectBtn {
            id: lwin

            height: keyboard.normHeight

            y: 138 * implicitScale
            width: 23 * implicitScale
            transformOrigin: Item.Left
            keyCode: 133
            anchors.left: lctl.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: lctl.verticalCenter
/*
            Component.onCompleted: {
                ke.registerModifier(lwin, ke.Meta)

            }*/
        }

        RectBtn {
            id: lalt

            height: keyboard.normHeight

            y: 138 * implicitScale
            width: 23 * implicitScale
            anchors.left: lwin.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: lwin.verticalCenter
            transformOrigin: Item.Left
            keyCode: 64
/*
            Component.onCompleted: {
                ke.registerModifier(lalt, ke.Alt)

            }*/
        }

        RectBtn {
            id: spce

            height: keyboard.normHeight

            y: 138 * implicitScale
            width: 113 * implicitScale
            transformOrigin: Item.Left
            anchors.left: lalt.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: lalt.verticalCenter
            keyCode: 65
        }

        RectBtn {
            id: ralt

            height: keyboard.normHeight

            y: 138 * implicitScale
            width: 23 * implicitScale
            transformOrigin: Item.Left
            anchors.left: spce.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: spce.verticalCenter
            keyCode: 108
/*
            Component.onCompleted: {
                ke.registerModifier(ralt, ke.AltGr)

            }*/
        }

        RectBtn {
            id: rwin

            height: keyboard.normHeight

            y: 138 * implicitScale
            width: 23 * implicitScale
            transformOrigin: Item.Left
            anchors.left: ralt.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ralt.verticalCenter
            keyCode: 134
/*
            Component.onCompleted: {
                ke.registerModifier(rwin, ke.Meta)

            }*/
        }

        RectBtn {
            id: menu

            height: keyboard.normHeight

            y: 138 * implicitScale
            width: 23 * implicitScale
            keyCode: 135
            transformOrigin: Item.Left
            anchors.left: rwin.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: rwin.verticalCenter
        }

        RectBtn {
            id: rctl

            height: keyboard.normHeight

            y: 138 * implicitScale
            width: 23 * implicitScale
            keyCode: 105
            anchors.left: menu.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: menu.verticalCenter
            transformOrigin: Item.Left
/*
            Component.onCompleted: {
                ke.registerModifier(rctl, ke.Ctrl)

            }*/
        }

        RectBtn {
            id: ins
            x: 312 * implicitScale

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: prsc.horizontalCenter

            anchors.top: esc.bottom
            anchors.topMargin: 5 * implicitScale
            transformOrigin: Item.TopLeft
            keyCode: 118
        }

        RectBtn {
            id: home

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 110
            transformOrigin: Item.Left
            anchors.left: ins.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: ins.verticalCenter
        }

        RectBtn {
            id: pgup

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            keyCode: 112
            transformOrigin: Item.Left
            anchors.left: home.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: home.verticalCenter
        }

        RectBtn {
            id: dele
            x: 312 * implicitScale

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: prsc.horizontalCenter

            keyCode: 119
            anchors.top: ins.bottom
            anchors.topMargin: 1 * implicitScale
            transformOrigin: Item.TopLeft
        }

        RectBtn {
            id: end

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            keyCode: 115
            anchors.left: dele.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: dele.verticalCenter
        }

        RectBtn {
            id: pgdn

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            keyCode: 117
            anchors.left: end.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: end.verticalCenter
        }

        RectBtn {
            id: up

            width: keyboard.normWidth
            height: keyboard.normHeight

            transformOrigin: Item.TopLeft
            keyCode: 111
            anchors.top: dele.bottom
            anchors.topMargin: 20 * implicitScale
            anchors.left: dele.right
            anchors.leftMargin: 1 * implicitScale
        }

        RectBtn {
            id: left_
            x: 312 * implicitScale

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: prsc.horizontalCenter

            keyCode: 113
            anchors.top: ins.bottom
            anchors.topMargin: 58 * implicitScale
        }

        RectBtn {
            id: down

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 138 * implicitScale
            keyCode: 116
            anchors.left: left_.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: left_.verticalCenter
        }

        RectBtn {
            id: rght

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 138 * implicitScale
            keyCode: 114
            transformOrigin: Item.Left
            anchors.left: down.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: down.verticalCenter
        }

        RectBtn {
            id: nmlk
            x: 376 * implicitScale
            y: 62 * implicitScale

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: kp1.horizontalCenter
            anchors.verticalCenter: pgup.verticalCenter

            transformOrigin: Item.TopLeft
            keyCode: 77
/*
            Component.onCompleted: {
                ke.registerModifier(nmlk, ke.NumLock)

            }*/
        }

        RectBtn {
            id: kpdv

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            transformOrigin: Item.Left
            keyCode: 106
            anchors.left: nmlk.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: nmlk.verticalCenter
        }

        RectBtn {
            id: kpmu

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            transformOrigin: Item.Left
            keyCode: 63
            anchors.left: kpdv.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kpdv.verticalCenter
        }

        RectBtn {
            id: kpsu

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62 * implicitScale
            transformOrigin: Item.Left
            keyCode: 82
            anchors.left: kpmu.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kpmu.verticalCenter
        }

        RectBtn {
            id: kp7
            x: 376 * implicitScale
            y: 86 * implicitScale

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: kp1.horizontalCenter
            anchors.verticalCenter: pgdn.verticalCenter

            keyCode: 79
            transformOrigin: Item.TopLeft
        }

        RectBtn {
            id: kp8

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81 * implicitScale
            transformOrigin: Item.Left
            keyCode: 80
            anchors.left: kp7.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kp7.verticalCenter
        }

        RectBtn {
            id: kp9

            width: keyboard.normWidth
            height: keyboard.normHeight

            x: 414 * implicitScale
            y: 81 * implicitScale
            keyCode: 81
            transformOrigin: Item.Left
            anchors.left: kp8.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kp8.verticalCenter
        }

        RectBtn {
            id: kpad

            width: keyboard.normWidth

            height: 37 * implicitScale
            anchors.top: kpsu.bottom
            anchors.topMargin: 1 * implicitScale
            transformOrigin: Item.Left
            keyCode: 86
            anchors.left: kp9.right
            anchors.leftMargin: 1 * implicitScale
        }

        RectBtn {
            id: kp4
            x: 376 * implicitScale
            y: 100 * implicitScale

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.verticalCenter: rtrn.verticalCenter
            anchors.horizontalCenter: kp1.horizontalCenter

            transformOrigin: Item.TopLeft
            keyCode: 83
        }

        RectBtn {
            id: kp5

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100 * implicitScale
            transformOrigin: Item.Left
            keyCode: 84
            anchors.left: kp4.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kp4.verticalCenter
        }

        RectBtn {
            id: kp6

            width: keyboard.normWidth
            height: keyboard.normHeight
            keyCode: 85

            y: 100 * implicitScale
            transformOrigin: Item.Left
            anchors.left: kp5.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kp5.verticalCenter
        }

        RectBtn {
            id: kp1
            x: 376 * implicitScale
            y: 119 * implicitScale
            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.bottom: kp0.top
            anchors.bottomMargin: 1 * implicitScale
            anchors.right: kp0.left
            anchors.rightMargin: -18 * implicitScale

            keyCode: 87
            transformOrigin: Item.Left
        }

        RectBtn {
            id: kp2

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            keyCode: 88
            transformOrigin: Item.Left
            anchors.left: kp1.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kp1.verticalCenter
        }

        RectBtn {
            id: kp3

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119 * implicitScale
            keyCode: 89
            transformOrigin: Item.Left
            anchors.left: kp2.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kp2.verticalCenter
        }

        RectBtn {
            id: kpen

            width: keyboard.normWidth

            height: 37 * implicitScale
            anchors.top: kpad.bottom
            anchors.topMargin: 1 * implicitScale
            transformOrigin: Item.Left
            keyCode: 104
            anchors.left: kp3.right
            anchors.leftMargin: 1 * implicitScale
        }

        RectBtn {
            id: kp0
            y: 138 * implicitScale

            height: keyboard.normHeight
            anchors.left: rght.right
            anchors.leftMargin: 5 * implicitScale
            anchors.verticalCenter: rght.verticalCenter

            width: 37 * implicitScale
            transformOrigin: Item.TopLeft
            keyCode: 90
        }

        RectBtn {
            id: kpdl

            width: keyboard.normWidth
            height: keyboard.normHeight
            keyCode: 91

            y: 138 * implicitScale
            transformOrigin: Item.Left
            anchors.left: kp0.right
            anchors.leftMargin: 1 * implicitScale
            anchors.verticalCenter: kp0.verticalCenter
        }

        Rectangle {
            id: leds
            width: 75 * implicitScale
            height: 19 * implicitScale
            color: "#191919"
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: paus.right
            anchors.leftMargin: 5 * implicitScale
            property string offColor: "#004600"
            property string lockColor: "#00FF00"
            Rectangle {
             //   property int animTime: 0
                id: num_lock
                x: 5 * implicitScale
                y: 15 * implicitScale
                width: 5 * implicitScale
                height: 1 * implicitScale
                color: parent.offColor
                function lock(){
                    lockAnimNumLock.start()
                }

                function reset(){
                    offAnimNumLock.start()
                }

                Component.onCompleted: {
                    ke.registerModifier(num_lock,ke.NumLock)
                    return "NUM"
                }
                ColorAnimation on color{
                    id: lockAnimNumLock
                    to: leds.lockColor;
                    duration: 75
                }
                ColorAnimation on color{
                    id: offAnimNumLock
                    to: leds.offColor;
                    duration: 75
                }
            }

            Rectangle {

                function lock(){
                    lockAnimCapsLock.start()
                }

                function reset(){
                    offAnimCapsLock.start()
                }

                Component.onCompleted: {
                    ke.registerModifier(caps_lock,ke.CapsLock)
                    return "caps"
                }
                id: caps_lock
                x: 32 * implicitScale
                y: 15 * implicitScale
                width: 5 * implicitScale
                height: 1 * implicitScale
                color: parent.offColor
                ColorAnimation on color{
                    id: lockAnimCapsLock
                    to: leds.lockColor;
                    duration: 75
                }
                ColorAnimation on color{
                    id: offAnimCapsLock
                    to: leds.offColor;
                    duration: 75
                }
            }

            Rectangle {
                id: scroll_lock
                x: 51 * implicitScale
                y: 15 * implicitScale
                width: 5 * implicitScale
                height: 1 * implicitScale
                color: parent.offColor
            }

            Text {
                id: num_lock_txt
                color: "#ffffff"
                text: qsTr("Num<br>Lock")
                anchors.left: parent.left
                anchors.leftMargin: 1
                anchors.top: parent.top
                anchors.topMargin: 3
                transformOrigin: Item.TopLeft
                font.pixelSize: 5
            }

            Text {
                id: caps_lock_txt
                x: 9 * implicitScale
                y: 5 * implicitScale
                color: "#ffffff"
                text: qsTr("Caps<br>Lock")
                font.pixelSize: 5 * implicitScale
                anchors.top: parent.top
                anchors.topMargin: 3 * implicitScale
                anchors.leftMargin: 26 * implicitScale
                transformOrigin: Item.TopLeft
                anchors.left: parent.left
            }

            Text {
                id: scroll_lock_txt
                x: 0
                y: 0
                color: "#ffffff"
                text: qsTr("Scroll<br>Lock")
                font.pixelSize: 5 * implicitScale
                anchors.top: parent.top
                anchors.topMargin: 3 * implicitScale
                anchors.leftMargin: 51 * implicitScale
                transformOrigin: Item.TopLeft
                anchors.left: parent.left
            }
        }




    }
/*
    transform: Scale {yScale: 1; xScale: 1}
    onHeightChanged: {
        transform[0].yScale = height/keyboard.height
    }

    onWidthChanged: {
        transform[0].xScale = width/keyboard.width
    }*/
}

