#ifdef USE_XCB
#include "xcbplatform.h"

XcbPlatform::XcbPlatform()
{
}

void XcbPlatform::connect()
{
    conn = xcb_connect(0,0);
    xcb_xkb_use_extension_cookie_t ck = xcb_xkb_use_extension(conn, XCB_XKB_MAJOR_VERSION, XCB_XKB_MINOR_VERSION);
    xcb_xkb_use_extension_reply(conn,ck, 0);
}

ModsState XcbPlatform::getState()
{
    ModsState modsState = QVector<char>(NUM_MODS);
    xcb_xkb_get_state_cookie_t ck = xcb_xkb_get_state_unchecked(conn, XCB_XKB_ID_USE_CORE_KBD);
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
    return modsState;
}

void XcbPlatform::disconnect()
{
    xcb_disconnect(conn);
}

void XcbPlatform::sendEvent(char keycode, bool press)
{
    xcb_test_fake_input(conn,press?XCB_KEY_PRESS:XCB_KEY_RELEASE,keycode,XCB_CURRENT_TIME,0,0,0,XCB_XKB_ID_USE_CORE_KBD);
    xcb_flush(conn);
    xcb_get_modifier_mapping_cookie_t ckmm = xcb_get_modifier_mapping(conn);
    xcb_get_modifier_mapping_reply_t *mmap = xcb_get_modifier_mapping_reply(conn, ckmm,0);
    xcb_keycode_t *kmm = xcb_get_modifier_mapping_keycodes(mmap);
    int mn = mmap->keycodes_per_modifier;
    qDebug("%d", mmap->length);
    for (int n = 0; n < mmap->length; n++)
        for (int s = 0; s < mn; s++)
            if (kmm[mn*n+s] == keycode) qDebug(" → MOD%d: %d\t←",n,kmm[mn*n+s]);
            else qDebug("   MOD%d: %d",n,kmm[mn*n+s]);

}

void XcbPlatform::setState(Mods mod, ModState state)
{

}

void XcbPlatform::latchKey(char keycode)
{

}

void XcbPlatform::lockKey(char keycode)
{

}


void XcbPlatform::waitNextEvent()
{
    xcb_generic_event_t *ev = xcb_wait_for_event(conn);
    delete ev;
}

void XcbPlatform::selectEvents()
{
    xcb_void_cookie_t ck = xcb_xkb_select_events(conn, XCB_XKB_ID_USE_CORE_KBD, XCB_XKB_EVENT_TYPE_STATE_NOTIFY, 0,XCB_XKB_EVENT_TYPE_STATE_NOTIFY,0,0,0);
    xcb_request_check(conn,ck);
}

long XcbPlatform::keysym(char keycode)
{
    xcb_xkb_get_state_cookie_t ck = xcb_xkb_get_state_unchecked(conn, XCB_XKB_ID_USE_CORE_KBD);
    xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,ck,0);

    xcb_key_symbols_t *ptr = xcb_key_symbols_alloc(conn);
    short first = 8;
    short count = 255 - 8;
    xcb_get_keyboard_mapping_cookie_t ckkm = xcb_get_keyboard_mapping(conn, first, count);
    xcb_get_keyboard_mapping_reply_t *reply = xcb_get_keyboard_mapping_reply(conn, ckkm, 0);
    xcb_keysym_t *map_ks = xcb_get_keyboard_mapping_keysyms(reply);
    xcb_get_modifier_mapping_cookie_t ckmm = xcb_get_modifier_mapping(conn);
    xcb_get_modifier_mapping_reply_t *mmap = xcb_get_modifier_mapping_reply(conn, ckmm,0);
    xcb_keycode_t *kmm = xcb_get_modifier_mapping_keycodes(mmap);
    int mn = mmap->keycodes_per_modifier;


    short n = reply->keysyms_per_keycode;
    return map_ks[(keycode - first)*n];
}

bool XcbPlatform::isModifier(char keycode, Mods mod)
{
    /*xcb_xkb_get_state_cookie_t ck = xcb_xkb_get_state_unchecked(conn, XCB_XKB_ID_USE_CORE_KBD);
    xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,ck,0);*/
    qDebug("ERROR: Attempt to call 'isModifier' not implemented in XCB");
    return false;
}

QList<Mods> XcbPlatform::modList(char keycode)
{
    return QList<Mods>();
}

#endif //USE_XCB
