#include "engine.h"
#include "modifierlistener.h"
#include "kbdstatelistener.h"
#ifndef USE_XCB
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/extensions/XTest.h>
#include <xkbcommon/xkbcommon.h>
#endif

KeyboardEngine *KeyboardEngine::singleton = 0;
KeyboardEngine::KeyboardEngine(QQuickItem *parent):
    QQuickItem(parent), modifierItems(NUM_MODS)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()
    
    // setFlag(ItemHasContents, true);
    KbdStateListener *statel;

    qDebug("Accessing X...");
#ifdef USE_XCB
    conn = xcb_connect(0,0);
#else
    dpy = XOpenDisplay(0);
    statel = new KbdStateListener(dpy);
    modsState = QVector<char>(NUM_MODS);
    XkbStatePtr status = new XkbStateRec;
    XkbGetState((Display *)dpy, XkbUseCoreKbd, status);
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
    if (status->latched_mods & Mod3Mask) modsState[Meta] = Latched;
    else if (status->locked_mods & Mod3Mask) modsState[Meta] = Locked;
    else if (status->base_mods & Mod3Mask) modsState[Meta] = Effective;
    else modsState[AltGr] = Unsetted;
    if (status->latched_mods & Mod5Mask) modsState[AltGr] = Latched;
    else if (status->locked_mods & Mod5Mask) modsState[AltGr] = Locked;
    else if (status->base_mods & Mod5Mask) modsState[AltGr] = Effective;
    else modsState[AltGr] = Unsetted;
#endif
    qDebug("Accessing X done.");

    connect(statel, SIGNAL(eventRecived()), this, SLOT(modEventRecived()));
    statel->start();

}

QObject *KeyboardEngine::KeyboardEngine_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    if (!singleton)
        singleton = new KeyboardEngine();
    return singleton;
}

KeyboardEngine::~KeyboardEngine()
{
#ifdef USE_XCB
    xcb_disconnect(conn);
#else
    XCloseDisplay((Display *)dpy);
#endif
}

void KeyboardEngine::refreshLayout()
{
    foreach(QQuickItem *item, keys)
        QMetaObject::invokeMethod(item,"refresh");
}

void KeyboardEngine::keyPress(int keycode, bool press)
{
#ifdef USE_XCB
    xcb_void_cookie_t cookie = xcb_test_fake_input_checked(conn,press?XCB_KEY_PRESS:XCB_KEY_RELEASE,keycode,XCB_CURRENT_TIME,0,0,0,0);
    xcb_request_check(conn, cookie);
#else
    XTestFakeKeyEvent((Display *)dpy, keycode, press, 0);
    XFlush((Display *)dpy);

#endif
}

QString KeyboardEngine::keySym(int keycode)
{
#ifdef USE_XCB
    xcb_key_symbols_t *ptr = xcb_key_symbols_alloc(conn);
    xcb_keysym_t sym = xcb_key_symbols_get_keysym(ptr,keycode, 0);
    return QString::number(sym);
#else
    KeySym keysym;
    XkbStatePtr status = new XkbStateRec;
    XkbGetState((Display *)dpy, XkbUseCoreKbd, status);
    XkbLookupKeySym((Display *)dpy, keycode, status->base_mods|status->latched_mods|status->locked_mods, 0, &keysym);
    return XKeysymToString(keysym);

#endif
}

void KeyboardEngine::registerModifier(QQuickItem *item, KeyboardEngine::Mods mod)
{
    modifierItems[mod].append(item);
}

void KeyboardEngine::registerKey(QQuickItem *item)
{
    keys.append(item);
}

void KeyboardEngine::initialize(QQuickItem *item)
{
    if (item->metaObject()->indexOfProperty("keyCode") != -1){
        KeyCode keycode;
        KeySym keysym;

        keycode = item->property("keyCode").toInt();

        registerKey(item);

        XkbStatePtr status = new XkbStateRec;
        XkbGetState((Display *)dpy, XkbUseCoreKbd, status);
        XkbLookupKeySym((Display *)dpy, keycode, status->base_mods|status->latched_mods|status->locked_mods, 0, &keysym);

        int mods = XkbKeysymToModifiers((Display *)dpy, keysym);
        if (mods){
            if (mods & ShiftMask)
                registerModifier(item,Shift);
            if (mods & ControlMask)
                registerModifier(item,Ctrl);
            if (mods & Mod1Mask)
                registerModifier(item,Alt);
            if (mods & Mod2Mask)
                registerModifier(item,NumLock);
            if (mods & LockMask)
                registerModifier(item,CapsLock);
            if (mods & Mod4Mask)
                registerModifier(item,Meta);
            if (mods & Mod5Mask)
                registerModifier(item,AltGr);
        }
    }
    foreach(QObject *obj, item->children()){
        QQuickItem *item = dynamic_cast<QQuickItem *>(obj);
        if (item)
            initialize(item);
    }
}


void KeyboardEngine::modEventRecived()
{
    QVector<char> mstatus(NUM_MODS);
#ifdef USE_XCB
#else
    XkbStatePtr status = new XkbStateRec;
    XkbGetState((Display *)dpy, XkbUseCoreKbd, status);
    if (status->latched_mods & ShiftMask) mstatus[Shift] = Latched;
    else if (status->locked_mods & ShiftMask) mstatus[Shift] = Locked;
    else if (status->base_mods & ShiftMask) mstatus[Shift] = Effective;
    else mstatus[Shift] = Unsetted;
    if (status->latched_mods & ControlMask) mstatus[Ctrl] = Latched;
    else if (status->locked_mods & ControlMask) mstatus[Ctrl] = Locked;
    else if (status->base_mods & ControlMask) mstatus[Ctrl] = Effective;
    else mstatus[Ctrl] = Unsetted;
    if (status->latched_mods & Mod1Mask) mstatus[Alt] = Latched;
    else if (status->locked_mods & Mod1Mask) mstatus[Alt] = Locked;
    else if (status->base_mods & Mod1Mask) mstatus[Alt] = Effective;
    else mstatus[Alt] = Unsetted;
    if (status->latched_mods & Mod2Mask) mstatus[NumLock] = Latched;
    else if (status->locked_mods & Mod2Mask) mstatus[NumLock] = Locked;
    else if (status->base_mods & Mod2Mask) mstatus[NumLock] = Effective;
    else mstatus[NumLock] = Unsetted;
    if (status->latched_mods & LockMask) mstatus[CapsLock] = Latched;
    else if (status->locked_mods & LockMask) mstatus[CapsLock] = Locked;
    else if (status->base_mods & LockMask) mstatus[CapsLock] = Effective;
    else mstatus[CapsLock] = Unsetted;
    if (status->latched_mods & Mod4Mask) mstatus[Meta] = Latched;
    else if (status->locked_mods & Mod4Mask) mstatus[Meta] = Locked;
    else if (status->base_mods & Mod4Mask) mstatus[Meta] = Effective;
    else mstatus[Meta] = Unsetted;
    if (status->latched_mods & Mod5Mask) mstatus[AltGr] = Latched;
    else if (status->locked_mods & Mod5Mask) mstatus[AltGr] = Locked;
    else if (status->base_mods & Mod5Mask) mstatus[AltGr] = Effective;
    else mstatus[AltGr] = Unsetted;
#endif

    for (int s = 0; s < NUM_MODS; s++)
        if (modsState[s] != mstatus[s])
            switch (mstatus[s]){
            case Effective:
                foreach (QQuickItem *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"activate");
                }
                break;
            case Latched:
                foreach (QQuickItem *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"latch");
                }
                break;
            case Locked:
                foreach (QQuickItem *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"lock");
                }
                break;
            default:
                foreach (QQuickItem *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"reset");
                }
                break;
            }
    modsState = mstatus;
    refreshLayout();
}


