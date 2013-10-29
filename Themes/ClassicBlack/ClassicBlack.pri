
equals (QT_MAJOR_VERSION, 5): {
    qt5cb.path = $$[QT_INSTALL_QML]/sandkeys/theme/ClassicBlack
    qt5cb.files = $$PWD/Qt5/ClassicBlack.qml $$PWD/Qt5/Btn.qml $$PWD/qmldir
    for(file, qt5cb.files){
        OTHER_FILES += $$file
        INSTALLS += qt5cb
    }
}
equals (QT_MAJOR_VERSION, 4): {
    qt4cb.path = $$[QT_INSTALL_IMPORTS]/sandkeys/theme/ClassicBlack
    qt4cb.files = $$PWD/Qt4/ClassicBlack.qml $$PWD/Qt4/RectBtn.qml $$PWD/qmldir

    for(file, qt4cb.files){
        OTHER_FILES += $$PWD/$$file
        INSTALLS += qt4cb
    }
}

