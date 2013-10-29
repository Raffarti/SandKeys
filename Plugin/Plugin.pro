TEMPLATE = lib
TARGET = KeyboardEngine
equals (QT_MAJOR_VERSION, 5): {
    DEFINES += USE_QT5=1 COMPONET_VERSION=2.0 PARENT_TYPE=QQuickItem ITEM_TYPE=QQuickItem
    CONFIG += use_qt5
    PLUGIN_INSTALL_PATH = $$[QT_INSTALL_QML]
}
equals (QT_MAJOR_VERSION, 4): {
    DEFINES += COMPONET_VERSION=1.1 PARENT_TYPE=QDeclarativeItem ITEM_TYPE=QDeclarativeItem
    PLUGIN_INSTALL_PATH = $$[QT_INSTALL_IMPORTS]
}

use_qt5 {
    QT += qml quick
    CONFIG += qt plugin
} else {
    QT += declarative
    CONFIG += qt plugin
}

use_xcb {
    CONFIG += link_pkgconfig
    PKGCONFIG += xcb xcb-xtest xcb-xkb xcb-keysyms
    DEFINES += USE_XCB
} else {
    CONFIG += link_pkgconfig
    PKGCONFIG += x11 xtst
}

TARGET = $$qtLibraryTarget($$TARGET)
uri = sandkeys.plugin

# Input
SOURCES += \
    qmlkeyboardengine_plugin.cpp \
    engine.cpp \
    kbdstatelistener.cpp

HEADERS += \
    qmlkeyboardengine_plugin.h \
    engine.h \
    kbdstatelistener.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$PLUGIN_INSTALL_PATH/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

