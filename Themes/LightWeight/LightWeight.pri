
equals (QT_MAJOR_VERSION, 5): {
    qt5lw.path = $$[QT_INSTALL_QML]/sandkeys/theme/LightWeight
    qt5lw.files = $$PWD/Keyboard.qml $$PWD/LightWeightBtn.qml $$PWD/qmldir
    for(file, qt5lw.files){
        OTHER_FILES += $$file
        INSTALLS += qt5lw
    }
}
