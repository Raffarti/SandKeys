#ifdef USE_WL
#include "wlplatform.h"

WLPlatform::WLPlatform()
{
}

void WLPlatform::connect()
{
    dpy = wl_display_connect(0);
}

ModsState WLPlatform::getState()
{
}

void WLPlatform::disconnect()
{

}

void WLPlatform::sendEvent(char keycode, bool press)
{
}

void WLPlatform::setState(Mods mod, ModState state)
{

}

void WLPlatform::latchKey(char keycode)
{

}

void WLPlatform::lockKey(char keycode)
{

}

void WLPlatform::waitNextEvent()
{

}

void WLPlatform::selectEvents()
{

}

long WLPlatform::keysym(char keycode)
{
    return 0;
}

bool WLPlatform::isModifier(char keycode, Mods mod)
{
    return false;
}

QString WLPlatform::keysymToString(long keysym)
{
    return "";
}

QList<Mods> WLPlatform::modList(char keycode)
{
    return QList<Mods>;
}

#endif //USE_WL
