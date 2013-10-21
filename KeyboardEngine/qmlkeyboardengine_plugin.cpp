#include "qmlkeyboardengine_plugin.h"
#include "engine.h"
#include "kbdstatelistener.h"

#include <qqml.h>


void QmlKeyboardEnginePlugin::registerTypes(const char *uri)
{
    //@uri com.raffarti.qmlcomponents
    qmlRegisterSingletonType<KeyboardEngine>(uri, 1, 0, "KeyboardEngine",KeyboardEngine::KeyboardEngine_singletontype_provider);
    qmlRegisterType<KeyboardEngine>(uri, 1, 0, "KeyboardEngine"); //just here to trick a Qt-Creator bug. *Should* be harmless.
}


