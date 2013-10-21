#include "kbdstatelistener.h"

#ifndef USE_XCB
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/extensions/XTest.h>
#include <xkbcommon/xkbcommon.h>
#endif

KbdStateListener::KbdStateListener(void *dpy, QObject *parent) :
    QThread(parent), dpy(dpy)
{
}

void KbdStateListener::run()
{

    dpy = XOpenDisplay(0);
    XkbSelectEvents((Display *)dpy, XkbUseCoreKbd, XkbStateNotifyMask, XkbStateNotifyMask);
    forever{
        XEvent xev;
        XNextEvent((Display *)dpy,&xev);
        emit eventRecived();
    }

}
