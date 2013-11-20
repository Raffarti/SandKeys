#ifdef USE_X11
#include "x11platform.h"

X11Platform::X11Platform()
{

}

void X11Platform::connect()
{
    dpy = XOpenDisplay(0);
}

ModsState X11Platform::getState()
{
    ModsState modsState = ModsState(NUM_MODS);
    XkbStatePtr status = new XkbStateRec;
    XkbGetState(dpy, XkbUseCoreKbd, status);
    if (status->latched_mods & ShiftMask) modsState[Shift] = Latched;
    else if (status->locked_mods & ShiftMask) modsState[Shift] = Locked;
    else if (status->base_mods & ShiftMask) modsState[Shift] = Effective;
    else modsState[Shift] = Unsetted;
    if (status->latched_mods & ControlMask) modsState[Ctrl] = Latched;
    else if (status->locked_mods & ControlMask) modsState[Ctrl] = Locked;
    else if (status->base_mods & ControlMask) modsState[Ctrl] = Effective;
    else modsState[Ctrl] = Unsetted;
    if (status->latched_mods & Mod1Mask) modsState[Alt] = Latched;
    else if (status->locked_mods & Mod1Mask) modsState[Alt] = Locked;
    else if (status->base_mods & Mod1Mask) modsState[Alt] = Effective;
    else modsState[Alt] = Unsetted;
    if (status->latched_mods & Mod2Mask) modsState[NumLock] = Latched;
    else if (status->locked_mods & Mod2Mask) modsState[NumLock] = Locked;
    else if (status->base_mods & Mod2Mask) modsState[NumLock] = Effective;
    else modsState[NumLock] = Unsetted;
    if (status->latched_mods & LockMask) modsState[CapsLock] = Latched;
    else if (status->locked_mods & LockMask) modsState[CapsLock] = Locked;
    else if (status->base_mods & LockMask) modsState[CapsLock] = Effective;
    else modsState[CapsLock] = Unsetted;
    if (status->latched_mods & Mod4Mask) modsState[Meta] = Latched;
    else if (status->locked_mods & Mod4Mask) modsState[Meta] = Locked;
    else if (status->base_mods & Mod4Mask) modsState[Meta] = Effective;
    else modsState[AltGr] = Unsetted;
    if (status->latched_mods & Mod5Mask) modsState[AltGr] = Latched;
    else if (status->locked_mods & Mod5Mask) modsState[AltGr] = Locked;
    else if (status->base_mods & Mod5Mask) modsState[AltGr] = Effective;
    else modsState[AltGr] = Unsetted;
    delete status;
    return modsState;
}

void X11Platform::disconnect()
{
    XCloseDisplay(dpy);
}
/*
static XKeyEvent createKeyEvent(Display *display, bool press,
                           int keycode, int modifiers)
{
   XKeyEvent event;

   Window winRoot = DefaultRootWindow(display);


   Window winFocus;
   int    revert;
   XGetInputFocus(display, &winFocus, &revert);

   event.display     = display;
   event.window      = winFocus;
   event.root        = winRoot;
   event.subwindow   = None;
   event.time        = CurrentTime;
   event.x           = 1;
   event.y           = 1;
   event.x_root      = 1;
   event.y_root      = 1;
   event.same_screen = True;
   event.keycode     = keycode;
   event.state       = modifiers;

   if(press)
      event.type = KeyPress;
   else
      event.type = KeyRelease;

   return event;
}*/

void X11Platform::sendEvent(char keycode, bool press)
{
    XTestFakeKeyEvent(dpy,keycode,press,0);
    XFlush(dpy);
}

void X11Platform::setState(Mods mod, ModState state)
{

}

void X11Platform::latchKey(char keycode)
{
    XkbStatePtr status = new XkbStateRec;
    XkbGetState(dpy, XkbUseCoreKbd, status);
    KeySym keysym;
    XkbLookupKeySym(dpy, keycode, status->base_mods|status->latched_mods|status->locked_mods, 0, &keysym);
    int mods = XkbKeysymToModifiers(dpy, keysym);
    if (!mods)return;
    XkbLatchModifiers(dpy, XkbUseCoreKbd, status->latched_mods | mods, (mods ^ status->latched_mods) & ~status->locked_mods);
    XFlush(dpy);
}

void X11Platform::lockKey(char keycode)
{
    XkbStatePtr status = new XkbStateRec;
    XkbGetState(dpy, XkbUseCoreKbd, status);
    KeySym keysym;
    XkbLookupKeySym(dpy, keycode, status->base_mods|status->latched_mods|status->locked_mods, 0, &keysym);
    int mods = XkbKeysymToModifiers(dpy, keysym);
    if (!mods)return;
    XkbLockModifiers(dpy, XkbUseCoreKbd, status->latched_mods | mods, (mods ^ status->latched_mods) & ~status->locked_mods);
    XFlush(dpy);
}

void X11Platform::waitNextEvent()
{
    XEvent xev;
    XNextEvent(dpy,&xev);
}

void X11Platform::selectEvents()
{
    XkbSelectEvents(dpy, XkbUseCoreKbd, XkbStateNotifyMask, XkbStateNotifyMask);
}

long X11Platform::keysym(char keycode)
{
    KeySym keysym;
    XkbStatePtr status = new XkbStateRec;
    XkbGetState((Display *)dpy, XkbUseCoreKbd, status);
    XkbLookupKeySym((Display *)dpy, keycode, status->mods|(status->group<<13), 0, &keysym);
    delete status;
    return keysym;
}

bool X11Platform::isModifier(char keycode, Mods mod)
{
    KeySym keysym;
    XkbStatePtr status = new XkbStateRec;
    XkbGetState(dpy, XkbUseCoreKbd, status);
    XkbLookupKeySym(dpy, keycode, status->mods|(status->group<<13), 0, &keysym);
    int mods = XkbKeysymToModifiers(dpy, keysym);
    delete status;
    switch(mod){
    case Shift:
        return mods & ShiftMask;
    case CapsLock:
        return mods & LockMask;
    case Ctrl:
        return mods & ControlMask;
    case Alt:
        return mods & Mod1Mask;
    case NumLock:
        return mods & Mod2Mask;
    case Meta:
        return mods & Mod4Mask;
    case AltGr:
        return mods & Mod5Mask;
    }
}

QList<Mods> X11Platform::modList(char keycode)
{
    QList<Mods> ret;
    KeySym keysym;
    XkbStatePtr status = new XkbStateRec;
    XkbGetState(dpy, XkbUseCoreKbd, status);
    XkbLookupKeySym(dpy, keycode, status->mods|(status->group<<13), 0, &keysym);
    int mods = XkbKeysymToModifiers(dpy, keysym);
    delete status;
    if (mods & ShiftMask) ret.append(Shift);
    if (mods & LockMask) ret.append(CapsLock);
    if (mods & ControlMask) ret.append(Ctrl);
    if (mods & Mod1Mask) ret.append(Alt);
    if (mods & Mod2Mask) ret.append(NumLock);
    if (mods & Mod4Mask) ret.append(Meta);
    if (mods & Mod5Mask) ret.append(AltGr);
    return ret;
}

bool X11Platform::canLatch() const
{
    return true;
}

bool X11Platform::hasEffectiveModifiers() const
{
    return true;
}

#endif USE_X11
