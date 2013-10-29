loader.files = $$PWD/QmlLoader.qml
loader.path = /usr/share/SandKeys/QmlLoader

launcher.files = $$PWD/sandkeys-qt5
launcher.path = /usr/bin
launcher.extra = chmod +x /usr/bin/sandkeys-qt5

INSTALLS += loader launcher
OTHER_FILES += $$loader.files $$launcher.files

