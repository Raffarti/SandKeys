#ifndef QMLKEYBOARDENGINE_PLUGIN_H
#define QMLKEYBOARDENGINE_PLUGIN_H

#include <QQmlExtensionPlugin>

class QmlKeyboardEnginePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri);
};

#endif // QMLKEYBOARDENGINE_PLUGIN_H

