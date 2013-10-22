import QtQuick 2.0
import com.raffarti.qmlcomponents 1.0 as KE

Rectangle {
    id: ext
    implicitWidth: 426*2
    implicitHeight: 117*2
    color: "#00000000"
    smooth: false

    objectName: {
        KE.KeyboardEngine.initialize(keyboard);
        return objectName
    }

    Rectangle {
        id: keyboard
        width: 426
        height: 117

        color: "#222222"
        smooth: true
        transformOrigin: Item.TopLeft
        opacity: 1

        property int normWidth: 18
        property int normHeight: 18

        LightWeightBtn {
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

        LightWeightBtn {
            id: fk01
            y: 0

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.left: esc.right
            anchors.leftMargin: 20
            anchors.verticalCenter: esc.verticalCenter

            transformOrigin: Item.Left
            keyCode: 67
        }

        LightWeightBtn {
            id: fk02

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.left: fk01.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk01.verticalCenter

            y: 23
            transformOrigin: Item.Left
            keyCode: 68
        }

        LightWeightBtn {
            id: fk03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 69
            anchors.left: fk02.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk02.verticalCenter
        }

        LightWeightBtn {
            id: fk04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 70
            anchors.left: fk03.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk03.verticalCenter
        }

        LightWeightBtn {
            id: fk05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 71
            anchors.left: fk04.right
            anchors.leftMargin: 11
            anchors.verticalCenter: fk04.verticalCenter
        }

        LightWeightBtn {
            id: fk06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            anchors.left: fk05.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk05.verticalCenter
            keyCode: 72
        }

        LightWeightBtn {
            id: fk07

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 73
            anchors.left: fk06.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk06.verticalCenter
        }

        LightWeightBtn {
            id: fk08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 74
            anchors.left: fk07.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk07.verticalCenter
        }

        LightWeightBtn {
            id: fk09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 75
            anchors.left: fk08.right
            anchors.leftMargin: 11
            anchors.verticalCenter: fk08.verticalCenter
        }

        LightWeightBtn {
            id: fk10

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            anchors.left: fk09.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk09.verticalCenter
            keyCode: 76
        }

        LightWeightBtn {
            id: fk11

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            anchors.left: fk10.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk10.verticalCenter
            keyCode: 95
        }

        LightWeightBtn {
            id: fk12

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 96
            anchors.left: fk11.right
            anchors.leftMargin: 1
            anchors.verticalCenter: fk11.verticalCenter
        }

        LightWeightBtn {
            id: prsc

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 107
            anchors.left: fk12.right
            anchors.leftMargin: 5
            anchors.verticalCenter: fk12.verticalCenter
        }

        LightWeightBtn {
            id: sclk

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            keyCode: 78
            anchors.left: prsc.right
            anchors.leftMargin: 1
            anchors.verticalCenter: prsc.verticalCenter
        }

        LightWeightBtn {
            id: paus

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 23
            transformOrigin: Item.Left
            anchors.left: sclk.right
            anchors.leftMargin: 1
            keyCode: 127
            anchors.verticalCenter: sclk.verticalCenter
        }

        LightWeightBtn {
            id: tlde

            width: keyboard.normWidth
            height: keyboard.normHeight

            keyCode: 49
            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: esc.bottom
            anchors.topMargin: 5
        }

        LightWeightBtn {
            id: ae01

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 10
            transformOrigin: Item.Left
            anchors.left: tlde.right
            anchors.leftMargin: 1
            anchors.verticalCenter: tlde.verticalCenter
        }


        LightWeightBtn {
            id: ae02

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 11
            anchors.left: ae01.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae01.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ae03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 12
            anchors.left: ae02.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae02.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ae04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 13
            anchors.left: ae03.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae03.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ae05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 14
            anchors.left: ae04.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae04.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ae06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            anchors.left: ae05.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae05.verticalCenter
            transformOrigin: Item.Left
            keyCode: 15
        }

        LightWeightBtn {
            id: ae07

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 16
            anchors.left: ae06.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae06.verticalCenter
        }

        LightWeightBtn {
            id: ae08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            anchors.left: ae07.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae07.verticalCenter
            transformOrigin: Item.Left
            keyCode: 17
        }

        LightWeightBtn {
            id: ae09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 18
            anchors.left: ae08.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae08.verticalCenter
        }

        LightWeightBtn {
            id: ae10

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            anchors.left: ae09.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae09.verticalCenter
            transformOrigin: Item.Left
            keyCode: 19
        }

        LightWeightBtn {
            id: ae11

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 20
            transformOrigin: Item.Left
            anchors.left: ae10.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae10.verticalCenter
        }

        LightWeightBtn {
            id: ae12

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            anchors.left: ae11.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae11.verticalCenter
            transformOrigin: Item.Left
            keyCode: 21
        }

        LightWeightBtn {
            id: bksp

            width: 38
            height: keyboard.normHeight

            y: 62
            keyCode: 22
            transformOrigin: Item.Left
            anchors.left: ae12.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ae12.verticalCenter
        }

        LightWeightBtn {
            id: tab

            width: 28
            height: keyboard.normHeight

            x: 20
            y: 81
            keyCode: 23
            transformOrigin: Item.TopLeft
            anchors.top: tlde.bottom
            anchors.topMargin: 1
            anchors.left: parent.left
            anchors.leftMargin: 0
        }


        LightWeightBtn {
            id: ad01

            width: keyboard.normWidth
            height: keyboard.normHeight

            x: 46
            y: 81
            transformOrigin: Item.Left
            keyCode: 24
            anchors.left: tab.right
            anchors.leftMargin: 1
            anchors.verticalCenter: tab.verticalCenter
        }

        LightWeightBtn {
            id: ad02

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            anchors.left: ad01.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad01.verticalCenter
            keyCode: 25
        }

        LightWeightBtn {
            id: ad03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            keyCode: 26
            anchors.left: ad02.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad02.verticalCenter
        }

        LightWeightBtn {
            id: ad04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            keyCode: 27
            anchors.left: ad03.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad03.verticalCenter
        }

        LightWeightBtn {
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

        LightWeightBtn {
            id: ad06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            anchors.left: ad05.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad05.verticalCenter
            keyCode: 29
        }

        LightWeightBtn {
            id: ad07

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            keyCode: 30
            anchors.left: ad06.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad06.verticalCenter
        }

        LightWeightBtn {
            id: ad08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            keyCode: 31
            anchors.left: ad07.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad07.verticalCenter
        }

        LightWeightBtn {
            id: ad09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            anchors.left: ad08.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad08.verticalCenter
            keyCode: 32
        }

        LightWeightBtn {
            id: ad10

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            anchors.left: ad09.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad09.verticalCenter
            keyCode: 33
        }

        LightWeightBtn {
            id: ad11

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            keyCode: 34
            anchors.left: ad10.right
            anchors.verticalCenter: ad10.verticalCenter
            anchors.leftMargin: 1
        }

        LightWeightBtn {
            id: ad12

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            keyCode: 35
            anchors.left: ad11.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad11.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: bksl

            width: 28
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            anchors.left: ad12.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ad12.verticalCenter
            keyCode: 51
        }

        LightWeightBtn {
            id: caps

            width: 33
            height: keyboard.normHeight
            anchors.top: tab.bottom
            anchors.topMargin: 1

            keyCode: 66
            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(caps, KE.KeyboardEngine.CapsLock)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: ac01

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            keyCode: 38
            transformOrigin: Item.Left
            anchors.left: caps.right
            anchors.leftMargin: 1
            anchors.verticalCenter: caps.verticalCenter
        }

        LightWeightBtn {
            id: ac02

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            transformOrigin: Item.Left
            anchors.left: ac01.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac01.verticalCenter
            keyCode: 39
        }

        LightWeightBtn {
            id: ac03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            keyCode: 40
            anchors.left: ac02.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac02.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ac04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            transformOrigin: Item.Left
            smooth: true
            anchors.left: ac03.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac03.verticalCenter
            keyCode: 41
        }

        LightWeightBtn {
            id: ac05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            keyCode: 42
            anchors.left: ac04.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac04.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ac06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            keyCode: 43
            anchors.left: ac05.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac05.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ac07

            width: keyboard.normWidth
            height: keyboard.normHeight

            x: 153
            y: 100
            transformOrigin: Item.Left
            keyCode: 44
            anchors.left: ac06.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac06.verticalCenter
        }

        LightWeightBtn {
            id: ac08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            keyCode: 45
            transformOrigin: Item.Left
            anchors.left: ac07.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac07.verticalCenter
        }

        LightWeightBtn {
            id: ac09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            keyCode: 46
            anchors.left: ac08.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac08.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ac10

            width: keyboard.normWidth
            height: keyboard.normHeight

            x: 210
            y: 100
            transformOrigin: Item.Left
            anchors.left: ac09.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac09.verticalCenter
            keyCode: 47
        }

        LightWeightBtn {
            id: ac11

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            transformOrigin: Item.Left
            keyCode: 48
            anchors.left: ac10.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac10.verticalCenter
        }

        LightWeightBtn {
            id: rtrn

            width: 42
            height: keyboard.normHeight

            y: 100
            keyCode: 36
            anchors.left: ac11.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ac11.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: lfsh
            width: 42
            height: keyboard.normHeight
            anchors.top: caps.bottom
            anchors.topMargin: 1
            transformOrigin: Item.TopLeft
            keyCode: 50
            anchors.left: parent.left
            anchors.leftMargin: 0
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(lfsh, KE.KeyboardEngine.Shift)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: ab01
            y: 119
            width: keyboard.normWidth
            height: keyboard.normHeight
            transformOrigin: Item.Left
            keyCode: 52
            anchors.left: lfsh.right
            anchors.leftMargin: 1
            anchors.verticalCenter: lfsh.verticalCenter
        }

        LightWeightBtn {
            id: ab02

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            transformOrigin: Item.Left
            keyCode: 53
            anchors.left: ab01.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab01.verticalCenter
        }

        LightWeightBtn {
            id: ab03

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            transformOrigin: Item.Left
            anchors.left: ab02.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab02.verticalCenter
            keyCode: 54
        }

        LightWeightBtn {
            id: ab04

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            keyCode: 55
            anchors.left: ab03.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab03.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ab05

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            transformOrigin: Item.Left
            keyCode: 56
            anchors.left: ab04.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab04.verticalCenter
        }

        LightWeightBtn {
            id: ab06

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            transformOrigin: Item.Left
            anchors.left: ab05.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab05.verticalCenter
            keyCode: 57
        }

        LightWeightBtn {
            id: ab07

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            keyCode: 58
            anchors.left: ab06.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab06.verticalCenter
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: ab08

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            transformOrigin: Item.Left
            keyCode: 59
            anchors.left: ab07.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab07.verticalCenter
        }

        LightWeightBtn {
            id: ab09

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            transformOrigin: Item.Left
            keyCode: 60
            anchors.left: ab08.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab08.verticalCenter
        }

        LightWeightBtn {
            id: ab10

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            transformOrigin: Item.Left
            anchors.left: ab09.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab09.verticalCenter
            keyCode: 61
        }

        LightWeightBtn {
            id: rtsh

            height: keyboard.normHeight

            y: 119
            width: 52
            keyCode: 62
            anchors.left: ab10.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ab10.verticalCenter
            transformOrigin: Item.Left
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(rtsh, KE.KeyboardEngine.Shift)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: lctl

            height: keyboard.normHeight
            anchors.top: lfsh.bottom
            anchors.topMargin: 1
            anchors.left: parent.left
            anchors.leftMargin: 0

            width: 27
            keyCode: 37
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(lctl, KE.KeyboardEngine.Ctrl)
                return objectName
            }*/

        }

        LightWeightBtn {
            id: lwin

            height: keyboard.normHeight

            y: 138
            width: 23
            transformOrigin: Item.Left
            keyCode: 133
            anchors.left: lctl.right
            anchors.leftMargin: 1
            anchors.verticalCenter: lctl.verticalCenter
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(lwin, KE.KeyboardEngine.Meta)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: lalt

            height: keyboard.normHeight

            y: 138
            width: 23
            anchors.left: lwin.right
            anchors.leftMargin: 1
            anchors.verticalCenter: lwin.verticalCenter
            transformOrigin: Item.Left
            keyCode: 64
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(lalt, KE.KeyboardEngine.Alt)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: spce

            height: keyboard.normHeight

            y: 138
            width: 113
            transformOrigin: Item.Left
            anchors.left: lalt.right
            anchors.leftMargin: 1
            anchors.verticalCenter: lalt.verticalCenter
            keyCode: 65
        }

        LightWeightBtn {
            id: ralt

            height: keyboard.normHeight

            y: 138
            width: 23
            transformOrigin: Item.Left
            anchors.left: spce.right
            anchors.leftMargin: 1
            anchors.verticalCenter: spce.verticalCenter
            keyCode: 108
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(ralt, KE.KeyboardEngine.AltGr)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: rwin

            height: keyboard.normHeight

            y: 138
            width: 23
            transformOrigin: Item.Left
            anchors.left: ralt.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ralt.verticalCenter
            keyCode: 134
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(rwin, KE.KeyboardEngine.Meta)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: menu

            height: keyboard.normHeight

            y: 138
            width: 23
            keyCode: 135
            transformOrigin: Item.Left
            anchors.left: rwin.right
            anchors.leftMargin: 1
            anchors.verticalCenter: rwin.verticalCenter
        }

        LightWeightBtn {
            id: rctl

            height: keyboard.normHeight

            y: 138
            width: 23
            keyCode: 105
            anchors.left: menu.right
            anchors.leftMargin: 1
            anchors.verticalCenter: menu.verticalCenter
            transformOrigin: Item.Left
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(rctl, KE.KeyboardEngine.Ctrl)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: ins
            x: 312

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: prsc.horizontalCenter

            anchors.top: esc.bottom
            anchors.topMargin: 5
            transformOrigin: Item.TopLeft
            keyCode: 118
        }

        LightWeightBtn {
            id: home

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 110
            transformOrigin: Item.Left
            anchors.left: ins.right
            anchors.leftMargin: 1
            anchors.verticalCenter: ins.verticalCenter
        }

        LightWeightBtn {
            id: pgup

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            keyCode: 112
            transformOrigin: Item.Left
            anchors.left: home.right
            anchors.leftMargin: 1
            anchors.verticalCenter: home.verticalCenter
        }

        LightWeightBtn {
            id: dele
            x: 312

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: prsc.horizontalCenter

            keyCode: 119
            anchors.top: ins.bottom
            anchors.topMargin: 1
            transformOrigin: Item.TopLeft
        }

        LightWeightBtn {
            id: end

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            keyCode: 115
            anchors.left: dele.right
            anchors.leftMargin: 1
            anchors.verticalCenter: dele.verticalCenter
        }

        LightWeightBtn {
            id: pgdn

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            keyCode: 117
            anchors.left: end.right
            anchors.leftMargin: 1
            anchors.verticalCenter: end.verticalCenter
        }

        LightWeightBtn {
            id: up

            width: keyboard.normWidth
            height: keyboard.normHeight

            transformOrigin: Item.TopLeft
            keyCode: 111
            anchors.top: dele.bottom
            anchors.topMargin: 20
            anchors.left: dele.right
            anchors.leftMargin: 1
        }

        LightWeightBtn {
            id: left_
            x: 312

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: prsc.horizontalCenter

            keyCode: 113
            anchors.top: ins.bottom
            anchors.topMargin: 58
        }

        LightWeightBtn {
            id: down

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 138
            keyCode: 116
            anchors.left: left_.right
            anchors.leftMargin: 1
            anchors.verticalCenter: left_.verticalCenter
        }

        LightWeightBtn {
            id: rght

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 138
            keyCode: 114
            transformOrigin: Item.Left
            anchors.left: down.right
            anchors.leftMargin: 1
            anchors.verticalCenter: down.verticalCenter
        }

        LightWeightBtn {
            id: nmlk
            x: 376
            y: 62

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: kp1.horizontalCenter
            anchors.verticalCenter: pgup.verticalCenter

            transformOrigin: Item.TopLeft
            keyCode: 77
/*
            objectName: {
                KE.KeyboardEngine.registerModifier(nmlk, KE.KeyboardEngine.NumLock)
                return objectName
            }*/
        }

        LightWeightBtn {
            id: kpdv

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            transformOrigin: Item.Left
            keyCode: 106
            anchors.left: nmlk.right
            anchors.leftMargin: 1
            anchors.verticalCenter: nmlk.verticalCenter
        }

        LightWeightBtn {
            id: kpmu

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            transformOrigin: Item.Left
            keyCode: 63
            anchors.left: kpdv.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kpdv.verticalCenter
        }

        LightWeightBtn {
            id: kpsu

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 62
            transformOrigin: Item.Left
            keyCode: 82
            anchors.left: kpmu.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kpmu.verticalCenter
        }

        LightWeightBtn {
            id: kp7
            x: 376
            y: 86

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.horizontalCenter: kp1.horizontalCenter
            anchors.verticalCenter: pgdn.verticalCenter

            keyCode: 79
            transformOrigin: Item.TopLeft
        }

        LightWeightBtn {
            id: kp8

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 81
            transformOrigin: Item.Left
            keyCode: 80
            anchors.left: kp7.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kp7.verticalCenter
        }

        LightWeightBtn {
            id: kp9

            width: keyboard.normWidth
            height: keyboard.normHeight

            x: 414
            y: 81
            keyCode: 81
            transformOrigin: Item.Left
            anchors.left: kp8.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kp8.verticalCenter
        }

        LightWeightBtn {
            id: kpad

            width: keyboard.normWidth

            height: 37
            anchors.top: kpsu.bottom
            anchors.topMargin: 1
            transformOrigin: Item.Left
            keyCode: 86
            anchors.left: kp9.right
            anchors.leftMargin: 1
        }

        LightWeightBtn {
            id: kp4
            x: 376
            y: 100

            width: keyboard.normWidth
            height: keyboard.normHeight
            anchors.verticalCenter: rtrn.verticalCenter
            anchors.horizontalCenter: kp1.horizontalCenter

            transformOrigin: Item.TopLeft
            keyCode: 83
        }

        LightWeightBtn {
            id: kp5

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 100
            transformOrigin: Item.Left
            keyCode: 84
            anchors.left: kp4.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kp4.verticalCenter
        }

        LightWeightBtn {
            id: kp6

            width: keyboard.normWidth
            height: keyboard.normHeight
            keyCode: 85

            y: 100
            transformOrigin: Item.Left
            anchors.left: kp5.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kp5.verticalCenter
        }

        LightWeightBtn {
            id: kp1
            x: 376
            y: 119
            width: 18

            height: 18
            anchors.bottom: kp0.top
            anchors.bottomMargin: 1
            anchors.right: kp0.left
            anchors.rightMargin: -18

            keyCode: 87
            transformOrigin: Item.Left
        }

        LightWeightBtn {
            id: kp2

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            keyCode: 88
            transformOrigin: Item.Left
            anchors.left: kp1.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kp1.verticalCenter
        }

        LightWeightBtn {
            id: kp3

            width: keyboard.normWidth
            height: keyboard.normHeight

            y: 119
            keyCode: 89
            transformOrigin: Item.Left
            anchors.left: kp2.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kp2.verticalCenter
        }

        LightWeightBtn {
            id: kpen

            width: keyboard.normWidth

            height: 37
            anchors.top: kpad.bottom
            anchors.topMargin: 1
            transformOrigin: Item.Left
            keyCode: 104
            anchors.left: kp3.right
            anchors.leftMargin: 1
        }

        LightWeightBtn {
            id: kp0
            y: 138

            height: keyboard.normHeight
            anchors.left: rght.right
            anchors.leftMargin: 5
            anchors.verticalCenter: rght.verticalCenter

            width: 37
            transformOrigin: Item.TopLeft
            keyCode: 90
        }

        LightWeightBtn {
            id: kpdl

            width: keyboard.normWidth
            height: keyboard.normHeight
            keyCode: 91

            y: 138
            transformOrigin: Item.Left
            anchors.left: kp0.right
            anchors.leftMargin: 1
            anchors.verticalCenter: kp0.verticalCenter
        }

        Rectangle {
            id: leds
            width: 75
            height: 19
            color: "#191919"
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: paus.right
            anchors.leftMargin: 5
            property string offColor: "#004600"
            property string lockColor: "#00FF00"
            Rectangle {
             //   property int animTime: 0
                id: num_lock
                x: 5
                y: 15
                width: 5
                height: 1
                color: parent.offColor
                function lock(){
                    lockAnimNumLock.start()
                }

                function reset(){
                    offAnimNumLock.start()
                }

                objectName: {
                    KE.KeyboardEngine.registerModifier(num_lock,KE.KeyboardEngine.NumLock)
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

                objectName: {
                    KE.KeyboardEngine.registerModifier(caps_lock,KE.KeyboardEngine.CapsLock)
                    return "caps"
                }
                id: caps_lock
                x: 32
                y: 15
                width: 5
                height: 1
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
                x: 51
                y: 15
                width: 5
                height: 1
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
                x: 9
                y: 5
                color: "#ffffff"
                text: qsTr("Caps<br>Lock")
                font.pixelSize: 5
                anchors.top: parent.top
                anchors.topMargin: 3
                anchors.leftMargin: 26
                transformOrigin: Item.TopLeft
                anchors.left: parent.left
            }

            Text {
                id: scroll_lock_txt
                x: 0
                y: 0
                color: "#ffffff"
                text: qsTr("Scroll<br>Lock")
                font.pixelSize: 5
                anchors.top: parent.top
                anchors.topMargin: 3
                anchors.leftMargin: 51
                transformOrigin: Item.TopLeft
                anchors.left: parent.left
            }
        }




    }

    transform: Scale {yScale: 2; xScale: 2}
    onHeightChanged: {
        transform[0].yScale = height/keyboard.height
    }

    onWidthChanged: {
        transform[0].xScale = width/keyboard.width
    }
}

