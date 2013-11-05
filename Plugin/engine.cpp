#include "engine.h"
#include "kbdstatelistener.h"
#include <QDebug>
#ifndef USE_XCB
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/extensions/XTest.h>
#endif
#include <xkbcommon/xkbcommon.h>

KeyboardEngine *KeyboardEngine::singleton = 0;
KeyboardEngine::KeyboardEngine(PARENT_TYPE *parent):
    PARENT_TYPE(parent), modifierItems(NUM_MODS)
{
    // By default, ITEM_TYPE does not draw anything. If you subclass
    // ITEM_TYPE to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()
    
    // setFlag(ItemHasContents, true);

#ifndef USE_QT5
    if (!singleton) singleton = this;
    else return;
#endif

    KbdStateListener *statel;

    qDebug("Accessing X...");
    modsState = QVector<char>(NUM_MODS);
#ifdef USE_XCB
    conn = xcb_connect(0,0);
    statel = new KbdStateListener(conn);
    xcb_xkb_get_state_cookie_t ck = xcb_xkb_get_state_unchecked(conn, XCB_XKB_ID_USE_CORE_KBD);
 /*   xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,ck,0); //return 0 with error code 10, whatever it means
    if (status->latchedMods & XCB_MOD_MASK_SHIFT) modsState[Shift] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_SHIFT) modsState[Shift] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_SHIFT) modsState[Shift] = Effective;
    else modsState[Shift] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_CONTROL) modsState[Ctrl] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_CONTROL) modsState[Ctrl] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_CONTROL) modsState[Ctrl] = Effective;
    else modsState[Ctrl] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_1) modsState[Alt] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_1) modsState[Alt] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_1) modsState[Alt] = Effective;
    else modsState[Alt] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_2) modsState[NumLock] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_2) modsState[NumLock] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_2) modsState[NumLock] = Effective;
    else modsState[NumLock] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_LOCK) modsState[CapsLock] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_LOCK) modsState[CapsLock] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_LOCK) modsState[CapsLock] = Effective;
    else modsState[CapsLock] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_3) modsState[Meta] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_3) modsState[Meta] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_3) modsState[Meta] = Effective;
    else modsState[AltGr] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_5) modsState[AltGr] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_5) modsState[AltGr] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_5) modsState[AltGr] = Effective;
    else modsState[AltGr] = Unsetted;
    delete status;*/
#else
    dpy = XOpenDisplay(0);
    statel = new KbdStateListener(dpy);
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
    delete status;


#endif
    qDebug("Accessing X done.");

    connect(statel, SIGNAL(eventRecived()), this, SLOT(modEventRecived()));
    statel->start();

    qDebug("Looking for keysym layout symbols...");
    QFileInfoList files = QDir("symbols").entryInfoList(QStringList("*.symbols"),QDir::Files);
    files += QDir("/usr/share/SandKeys/Symbols").entryInfoList(QStringList("*.symbols"),QDir::Files);
    foreach (QFileInfo fi, files) {
        qDebug() << "Found:" << fi.absoluteFilePath();
        QFile f(fi.absoluteFilePath());
        f.open(QFile::ReadOnly);
        while(!f.atEnd()){
#ifdef USE_QT5
            QString l = f.readLine().trimmed();
#else
            QString l = QString::fromUtf8(f.readLine()).trimmed();
#endif
            if (l.startsWith('#')) continue;
            QStringList p = l.split(" ",QString::SkipEmptyParts);
            if (p.isEmpty()) continue;
            int keyid = p[0].toInt();
            if (!keyid) continue;
            if (symbolMap.contains(keyid)) qDebug() << "WARNING: "<<keyid<<"have multiple definitions";
            switch(p.length()){
            case 0:
                continue;
            case 1:
                symbolMap.insert(keyid,"");
                break;
            case 2:
                symbolMap.insert(keyid,p[1]);
                break;
            case 3:
                p.pop_front();
                symbolMap.insert(keyid,p.join(" "));
                break;
            }
        }
    }
    qDebug("Looking for keysym layout symbols done.");
}
#ifdef USE_QT5
QObject *KeyboardEngine::KeyboardEngine_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    if (!singleton)
        singleton = new KeyboardEngine();
    return singleton;
}
#endif
KeyboardEngine::~KeyboardEngine()
{
#ifdef USE_XCB
    xcb_disconnect(conn);
#else
    if (singleton != this) return;
    XCloseDisplay((Display *)dpy);
#endif
}

void KeyboardEngine::refreshLayout()
{
#ifndef USE_QT5
    if (singleton != this)return singleton->refreshLayout();
#endif
    foreach(ITEM_TYPE *item, keys)
        QMetaObject::invokeMethod(item,"refresh");
}

void KeyboardEngine::keyPress(int keycode, bool press)
{
#ifndef USE_QT5
    if (singleton != this) return singleton->keyPress(keycode, press);
#endif
#ifdef USE_XCB
   /* xcb_xkb_get_state_cookie_t ck = xcb_xkb_get_state(conn, XCB_XKB_ID_USE_CORE_KBD);
    xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,ck,0);
    xcb_key_symbols_t *syms;
    qDebug() << xcb_key_symbols_get_keysym(syms, keycode, status->group);*/
    xcb_test_fake_input(conn,press?XCB_KEY_PRESS:XCB_KEY_RELEASE,keycode,XCB_CURRENT_TIME,0,0,0,XCB_XKB_ID_USE_CORE_KBD);
    xcb_flush(conn);
#else
    XkbStatePtr status = new XkbStateRec;
    XkbGetState((Display *)dpy, XkbUseCoreKbd, status);
    KeySym keysym;
    XkbLookupKeySym((Display *)dpy, keycode, status->base_mods|status->latched_mods|status->locked_mods, 0, &keysym);
    int mods = XkbKeysymToModifiers((Display *)dpy, keysym);
    if (mods && !press){
        XkbLatchModifiers((Display *)dpy, XkbUseCoreKbd, status->latched_mods | mods, (mods ^ status->latched_mods) & ~status->locked_mods);
    }
    XTestFakeKeyEvent((Display *)dpy, keycode, press, 0);
    XFlush((Display *)dpy);
    delete status;

#endif
}

QString KeyboardEngine::keySym(int keycode)
{
#ifndef USE_QT5
    if (singleton != this){
        return singleton->keySym(keycode);
    }
#endif
#ifdef USE_XCB
    xcb_key_symbols_t *ptr = xcb_key_symbols_alloc(conn);
    xcb_keysym_t keysym = xcb_key_symbols_get_keysym(ptr,keycode, 0);
#else
    KeySym keysym;
    XkbStatePtr status = new XkbStateRec;
    XkbGetState((Display *)dpy, XkbUseCoreKbd, status);
    XkbLookupKeySym((Display *)dpy, keycode, status->mods|(status->group<<13), 0, &keysym);
    delete status;

#endif
    if (symbolMap.contains(keysym)) return symbolMap[keysym];
    int s = 1;
    char *b = new char[s];
    int ret = xkb_keysym_to_utf8(keysym, b, s);
    while (ret == -1 && s < 32){
        delete b;
        b = new char[++s];
        ret = xkb_keysym_to_utf8(keysym, b, s);
    }
    if (ret > 0)
#ifdef USE_QT5
        return QString(b);
#else
        return QString::fromUtf8(b);
#endif
#ifdef USE_XCB
    return QString::number(keysym);
#else
    return XKeysymToString(keysym);
#endif
}

void KeyboardEngine::registerModifier(ITEM_TYPE *item, KeyboardEngine::Mods mod)
{
#ifndef USE_QT5
    if (singleton != this)return singleton->registerModifier(item, mod);
#endif
    modifierItems[mod].append(item);
}

void KeyboardEngine::registerKey(ITEM_TYPE *item)
{
#ifndef USE_QT5
    if (singleton != this)return singleton->registerKey(item);
#endif
    keys.append(item);
}

void KeyboardEngine::initialize(ITEM_TYPE *item)
{
#ifndef USE_QT5
    if (singleton != this)return singleton->initialize(item);
#endif
    reset();
    initializeRec(item);
}
void KeyboardEngine::initializeRec(ITEM_TYPE *item)
{
#ifndef USE_QT5
    if (singleton != this)return singleton->initializeRec(item);
#endif
    if (item->metaObject()->indexOfProperty("keyCode") != -1){
#ifdef USE_XCB
        char keycode;
        int keysym;
#else
        KeyCode keycode;
        KeySym keysym;
#endif
        keycode = item->property("keyCode").toInt();

        registerKey(item);

#ifdef USE_XCB
        xcb_xkb_get_state_cookie_t ck = xcb_xkb_get_state(conn, XCB_XKB_ID_USE_CORE_KBD);
        xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,ck,0);
#else
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
        delete status;
#endif
    }
    foreach(QObject *obj, item->children()){
        ITEM_TYPE *item = dynamic_cast<ITEM_TYPE *>(obj);
        if (item)
            initializeRec(item);
    }
}

void KeyboardEngine::reset()
{
#ifndef USE_QT5
    if (singleton != this)return singleton->reset();
#endif
    modifierItems = QVector<QList<ITEM_TYPE*> >(NUM_MODS);
    keys.clear();
}


void KeyboardEngine::modEventRecived()
{
    QVector<char> mstatus(NUM_MODS);
#ifdef USE_XCB
    xcb_xkb_get_state_cookie_t ck = xcb_xkb_get_state(conn, XCB_XKB_ID_USE_CORE_KBD);
    xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,ck,0);
    if (status->latchedMods & XCB_MOD_MASK_SHIFT) modsState[Shift] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_SHIFT) modsState[Shift] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_SHIFT) modsState[Shift] = Effective;
    else modsState[Shift] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_CONTROL) modsState[Ctrl] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_CONTROL) modsState[Ctrl] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_CONTROL) modsState[Ctrl] = Effective;
    else modsState[Ctrl] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_1) modsState[Alt] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_1) modsState[Alt] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_1) modsState[Alt] = Effective;
    else modsState[Alt] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_2) modsState[NumLock] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_2) modsState[NumLock] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_2) modsState[NumLock] = Effective;
    else modsState[NumLock] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_LOCK) modsState[CapsLock] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_LOCK) modsState[CapsLock] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_LOCK) modsState[CapsLock] = Effective;
    else modsState[CapsLock] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_3) modsState[Meta] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_3) modsState[Meta] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_3) modsState[Meta] = Effective;
    else modsState[AltGr] = Unsetted;
    if (status->latchedMods & XCB_MOD_MASK_5) modsState[AltGr] = Latched;
    else if (status->lockedMods & XCB_MOD_MASK_5) modsState[AltGr] = Locked;
    else if (status->baseMods & XCB_MOD_MASK_5) modsState[AltGr] = Effective;
    else modsState[AltGr] = Unsetted;
    delete status;
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
    delete status;
#endif

    for (int s = 0; s < NUM_MODS; s++)
        if (modsState[s] != mstatus[s])
            switch (mstatus[s]){
            case Effective:
                foreach (ITEM_TYPE *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"activate");
                }
                break;
            case Latched:
                foreach (ITEM_TYPE *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"latch");
                }
                break;
            case Locked:
                foreach (ITEM_TYPE *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"lock");
                }
                break;
            default:
                foreach (ITEM_TYPE *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"reset");
                }
                break;
            }
    modsState = mstatus;
    refreshLayout();

}


