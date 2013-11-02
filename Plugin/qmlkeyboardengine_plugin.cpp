#include "qmlkeyboardengine_plugin.h"
#include "engine.h"
#include "kbdstatelistener.h"

#ifdef USE_QT5
#include <qqml.h>


void QmlKeyboardEnginePlugin::registerTypes(const char *uri)
{
    //@uri sandkeys.plugin
    qmlRegisterSingletonType<KeyboardEngine>(uri, 1, 0, "KeyboardEngine",KeyboardEngine::KeyboardEngine_singletontype_provider);
    qmlRegisterType<KeyboardEngine>(uri, 1, 0, "KeyboardEngine"); //just here to trick a Qt-Creator bug. *Should* be harmless.
}
#else
#include <qdeclarative.h>

void KeyboardEnginePlugin::registerTypes(const char *uri)
{
    // @uri sandkeys.plugin
    qmlRegisterType<KeyboardEngine>(uri, 1, 0, "KeyboardEngine");
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(KeyboardEngine, KeyboardEnginePlugin)
#endif

#endif
