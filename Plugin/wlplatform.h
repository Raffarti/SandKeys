#ifdef USE_WL
#ifndef WLPLATFORM_H
#define WLPLATFORM_H

#include "inputplatform.h"
#include "wayland-client.h"
#define PLATFORM WLPlatform

class WLPlatform : public InputPlatform
{
public:
    WLPlatform();

    // InputPlatform interface
public:
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
    QString keysymToString(long keysym);
    QList<Mods> modList(char keycode);

private:
    wl_display *dpy;
};

#endif // WLPLATFORM_H
#endif //USE_WL
