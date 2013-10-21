folder_01.source = QmlSandKeys/
folder_01.target = SandKeys/
DEPLOYMENTFOLDERS = folder_01

DESTDIR = SandKeys

qmlfilecopy.commands = @echo Copying plugin data...\
                         && $(COPY_FILE) \"$$PWD/KeyboardEngine/qmldir\" \"$$OUT_PWD/$$DESTDIR/com/raffarti/qmlcomponents\" \
                         && $(COPY_FILE) \"$$PWD/SandKeys.launcher.sh\" \"$$OUT_PWD/$$DESTDIR\"

POST_TARGETDEPS += qmlfilecopy
QMAKE_EXTRA_TARGETS += qmlfilecopy

include(KeyboardEngine/keyboardengine.pri)
qtcAddDeployment()

