#ifdef USE_X11
#ifndef X11PLATFORM_H
#define X11PLATFORM_H

#include <QMap>
#include "inputplatform.h"
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/extensions/XTest.h>
#define PLATFORM X11Platform

class X11Platform : public InputPlatform
{
public:
    X11Platform();

    void connect();
    ModsState getState();
    void disconnect();
    void sendEvent(char keycode, bool press);
    void setState(Mods mod, ModState state);
    void latchKey(char keycode);
    void lockKey(char keycode);
    void waitNextEvent();
    void selectEvents();
    long keysym(char keycode);
    bool isModifier(char keycode, Mods mod);
    QList<Mods> modList(char keycode);
    virtual bool canLatch() const;
    virtual bool hasEffectiveModifiers() const;


private:

    Display *dpy;
};

#endif // X11PLATFORM_H
#endif //USE_X11
