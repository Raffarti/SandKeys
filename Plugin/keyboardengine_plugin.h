#ifndef QMLKEYBOARDENGINE_PLUGIN_H
#define QMLKEYBOARDENGINE_PLUGIN_H

#ifdef USE_QT5
#include <QQmlExtensionPlugin>

class KeyboardEnginePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri);
};
#else
#include <QDeclarativeExtensionPlugin>

class KeyboardEnginePlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
#endif

public:
    void registerTypes(const char *uri);
};

#endif
#endif // QMLKEYBOARDENGINE_PLUGIN_H

