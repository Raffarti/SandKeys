#-------------------------------------------------
#
# Project created by QtCreator 2013-10-08T13:15:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SandKeys
TEMPLATE = app
LIBS += -lX11
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        keyboard.cpp \
    config.cpp \
    xkbadapter.cpp \
    XKBGeometryLoader/layoutbuilder.cpp \
    XKBGeometryLoader/indicator.cpp \
    XKBGeometryLoader/geometry.cpp \
    XKBGeometryLoader/shape.cpp \
    keyboardmanager.cpp

HEADERS  += keyboard.h \
    config.h \
    logger.h \
    xkbadapter.h \
    XKBGeometryLoader/layoutbuilder.h \
    XKBGeometryLoader/indicator.h \
    XKBGeometryLoader/geometry.h \
    XKBGeometryLoader/shape.h \
    keyboardmanager.h

FORMS    += keyboard.ui \
    DefaultKeyboard.ui
