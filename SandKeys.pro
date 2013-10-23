DESTDIR = SandKeys

folder_01.source = QmlSandKeys/
folder_01.target = $$DESTDIR/
folder_02.source = QmlSandKeysLightWeight/
folder_02.target = $$DESTDIR/
folder_03.source = SandKeysWindow/
folder_03.target = $$DESTDIR
DEPLOYMENTFOLDERS = folder_01 folder_02 folder_03 folder_04


qmlfilecopy.commands = @echo Copying plugin data...\
                         && $(COPY_FILE) \"$$PWD/KeyboardEngine/qmldir\" \"$$OUT_PWD/$$DESTDIR/com/raffarti/qmlcomponents\" \
                         && $(COPY_FILE) \"$$PWD/SandKeys.launcher.sh\" \"$$OUT_PWD/$$DESTDIR\"

POST_TARGETDEPS += qmlfilecopy
QMAKE_EXTRA_TARGETS += qmlfilecopy
OTHER_FILES += SandKeys.launcher.sh

include(KeyboardEngine/keyboardengine.pri)
qtcAddDeployment()

