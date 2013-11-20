#ifdef USE_XCB
#ifndef XCBPLATFORM_H
#define XCBPLATFORM_H

#define xcb_key_symbols_alloc xcb_key_symbols_alloc_broken
#include <xcb/xcb.h>
#undef xcb_key_symbols_alloc
#include <xcb/xtest.h>
#define explicit explicit_
#include <xcb/xkb.h>
#undef explicit
#include <xcb/xcb_keysyms.h>

#include "inputplatform.h"
#define PLATFORM XcbPlatform

class XcbPlatform : public InputPlatform
{
public:
    XcbPlatform();

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

    xcb_connection_t *conn;
};

#endif // XCBPLATFORM_H
#endif //USE_XCB
