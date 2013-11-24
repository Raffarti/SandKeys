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
    ModsState modsState = QVector<ModState>(NUM_MODS);
    xcb_xkb_get_state_cookie_t ck = xcb_xkb_get_state_unchecked(conn, XCB_XKB_ID_USE_CORE_KBD);
    xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,ck,0);

    Mods mods[] = {Shift, Ctrl, Alt, NumLock, CapsLock, Meta, AltGr};
    const int sz = sizeof(mods) / sizeof(Mods);
    int masks[sz] = {XCB_MOD_MASK_SHIFT, XCB_MOD_MASK_CONTROL, XCB_MOD_MASK_1,
                  XCB_MOD_MASK_2,XCB_MOD_MASK_LOCK, XCB_MOD_MASK_4,XCB_MOD_MASK_5};

    for (int i = 0; i < sz; i++) {
        if (status->latchedMods & masks[i])
            modsState[mods[i]] = Latched;
        else if (status->lockedMods & masks[i])
            modsState[mods[i]] = Locked;
        else if (status->baseMods & masks[i])
            modsState[mods[i]] = Effective;
        else if (status->latchedGroup & masks[i])
            modsState[mods[i]] = Latched;
        else
            modsState[mods[i]] = Unsetted;
    }

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
    int mn = xcb_get_modifier_mapping_keycodes_length(mmap);
    int mn2 = mmap->keycodes_per_modifier;
    qDebug("%d", mn2);
    for (int n = 0; n < mn; n++){
            if (kmm[n] == (u_int8_t)keycode) qDebug(" → MOD%d: %d\t←",n/mn2,kmm[n]);
            else qDebug("   MOD%d: %d",n/mn2,kmm[n]);
    }
    qDebug("keycode: %d %d", (u_int8_t)keycode, keycode);

}

void XcbPlatform::setState(Mods mod, ModState state)
{

}

void XcbPlatform::latchKey(char keycode)
{/*
    xcb_xkb_get_state_cookie_t cks = xcb_xkb_get_state_unchecked(conn, XCB_XKB_ID_USE_CORE_KBD);
    xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,cks,0);

    xcb_get_modifier_mapping_cookie_t ckmm = xcb_get_modifier_mapping(conn);
    xcb_get_modifier_mapping_reply_t *mmap = xcb_get_modifier_mapping_reply(conn, ckmm,0);
    xcb_keycode_t *kmm = xcb_get_modifier_mapping_keycodes(mmap);
    int mn = xcb_get_modifier_mapping_keycodes_length(mmap);
    int mn2 = mmap->keycodes_per_modifier;
    int masks[] = {XCB_MOD_MASK_SHIFT, XCB_MOD_MASK_LOCK, XCB_MOD_MASK_CONTROL, XCB_MOD_MASK_1,
                  XCB_MOD_MASK_2, XCB_MOD_MASK_3, XCB_MOD_MASK_4, XCB_MOD_MASK_5};
    int stack = 0;
    for (int n = 0; n < mn; n++)
        if (kmm[n] == (u_int8_t)keycode) stack = stack | masks[n/mn2];
    xcb_void_cookie_t ck = xcb_xkb_latch_lock_state(conn, XCB_XKB_ID_USE_CORE_KBD, status->lockedMods | stack, stack ^ status->lockedMods(), 0, 0, 0, 0, 0); //parameter missing?
    xcb_request_check(conn, ck);*/
    lockKey(keycode);
}

void XcbPlatform::lockKey(char keycode)
{
    xcb_xkb_get_state_cookie_t cks = xcb_xkb_get_state_unchecked(conn, XCB_XKB_ID_USE_CORE_KBD);
    xcb_xkb_get_state_reply_t *status = xcb_xkb_get_state_reply(conn,cks,0);

    xcb_get_modifier_mapping_cookie_t ckmm = xcb_get_modifier_mapping(conn);
    xcb_get_modifier_mapping_reply_t *mmap = xcb_get_modifier_mapping_reply(conn, ckmm,0);
    xcb_keycode_t *kmm = xcb_get_modifier_mapping_keycodes(mmap);
    int mn = xcb_get_modifier_mapping_keycodes_length(mmap);
    int mn2 = mmap->keycodes_per_modifier;
    int masks[] = {XCB_MOD_MASK_SHIFT, XCB_MOD_MASK_LOCK, XCB_MOD_MASK_CONTROL, XCB_MOD_MASK_1,
                  XCB_MOD_MASK_2, XCB_MOD_MASK_3, XCB_MOD_MASK_4, XCB_MOD_MASK_5};
    int stack = 0;
    for (int n = 0; n < mn; n++)
        if (kmm[n] == (u_int8_t)keycode) stack = stack | masks[n/mn2];
    xcb_void_cookie_t ck = xcb_xkb_latch_lock_state(conn, XCB_XKB_ID_USE_CORE_KBD, status->lockedMods | stack, stack ^ status->lockedMods, 0, 0, 0, 0, 0);
    xcb_request_check(conn, ck);
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

    xcb_keycode_t first = xcb_get_setup(conn)->min_keycode;
    xcb_keycode_t count = xcb_get_setup(conn)->max_keycode - first +1;
    xcb_get_keyboard_mapping_cookie_t ckkm = xcb_get_keyboard_mapping(conn, first, count);
    xcb_get_keyboard_mapping_reply_t *reply = xcb_get_keyboard_mapping_reply(conn, ckkm, 0);
    xcb_keysym_t *map_ks = xcb_get_keyboard_mapping_keysyms(reply);
    xcb_get_modifier_mapping_cookie_t ckmm = xcb_get_modifier_mapping(conn);
    xcb_get_modifier_mapping_reply_t *mmap = xcb_get_modifier_mapping_reply(conn, ckmm,0);
    xcb_keycode_t *kmm = xcb_get_modifier_mapping_keycodes(mmap);
    int mn = mmap->keycodes_per_modifier;


    short n = reply->keysyms_per_keycode;
    return map_ks[(keycode - first)*n];
    //return xcb_key_symbols_get_keysym(syms, keycode, 7);
}

bool XcbPlatform::isModifier(char keycode, Mods mod)
{
    return modList(keycode).contains(mod);
}

QList<Mods> XcbPlatform::modList(char keycode)
{
    QList<Mods> ret;
    xcb_get_modifier_mapping_cookie_t ckmm = xcb_get_modifier_mapping(conn);
    xcb_get_modifier_mapping_reply_t *mmap = xcb_get_modifier_mapping_reply(conn, ckmm,0);
    xcb_keycode_t *kmm = xcb_get_modifier_mapping_keycodes(mmap);
    int mn = xcb_get_modifier_mapping_keycodes_length(mmap);
    int mn2 = mmap->keycodes_per_modifier;
    Mods mods[] = {Shift, CapsLock, Ctrl, Alt, NumLock, (Mods) -1, Meta, AltGr};
    for (int n = 0; n < mn; n++)
        if (kmm[n] == (u_int8_t)keycode) ret.append(mods[n/mn2]);

    return ret;
}

bool XcbPlatform::canLatch() const
{
    return false;
}

bool XcbPlatform::hasEffectiveModifiers() const
{
    return true;
}

#endif //USE_XCB
