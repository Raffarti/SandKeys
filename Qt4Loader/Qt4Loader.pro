# Add more folders to ship with the application, here
#folder_01.source = qml/Qt4Loader
#folder_01.target = qml
DEPLOYMENTFOLDERS =

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp
TARGET = sandkeys-qt4
# Installation path
target.path = /usr/bin

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

qmlwrapper.files = Wrapper.qml
qmlwrapper.path = /usr/share/SandKeys/Qt4Loader/

INSTALLS += qmlwrapper
OTHER_FILES = $$qmlwrapper.files

