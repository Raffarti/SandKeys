#include "kbdstatelistener.h"

#ifndef USE_XCB
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/extensions/XTest.h>
#include <xkbcommon/xkbcommon.h>
#endif

#ifdef USE_XCB
KbdStateListener::KbdStateListener(xcb_connection_t *conn, QObject *parent) :
    QThread(parent), conn(conn)
{
}
#else
KbdStateListener::KbdStateListener(void *dpy, QObject *parent) :
    QThread(parent), dpy(dpy)
{
}

#endif
void KbdStateListener::run()
{

#ifdef USE_XCB
    conn = xcb_connect(0,0);
    xcb_void_cookie_t ck = xcb_xkb_select_events(conn, XCB_XKB_ID_USE_CORE_KBD, XCB_EVENT_MASK_KEYMAP_STATE, 0,0,XCB_EVENT_MASK_KEYMAP_STATE,0,0);
    xcb_request_check(conn,ck);
    forever{ break; //something is wrong, probably xcb_xkb_select_events is not used properly (any docs somewhere???)
        xcb_wait_for_event(conn);

#else
    dpy = XOpenDisplay(0);
    XkbSelectEvents((Display *)dpy, XkbUseCoreKbd, XkbStateNotifyMask, XkbStateNotifyMask);
    forever{
        XEvent xev;
        XNextEvent((Display *)dpy,&xev);

#endif
        emit eventRecived();
    }

}
