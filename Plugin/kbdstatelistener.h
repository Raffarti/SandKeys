#ifndef KBDSTATELISTENER_H
#define KBDSTATELISTENER_H
#ifdef USE_XCB

#define xcb_key_symbols_alloc xcb_key_symbols_alloc_broken
#include <xcb/xcb.h>
#undef xcb_key_symbols_alloc
#include <xcb/xtest.h>
#define explicit explicit_
#include <xcb/xkb.h>
#undef explicit
#include <xcb/xcb_keysyms.h>
#endif
#include <QThread>

class KbdStateListener : public QThread
{
    Q_OBJECT
public:
#ifdef USE_XCB
    explicit KbdStateListener(xcb_connection_t *dpy, QObject *parent = 0);
#else
    explicit KbdStateListener(void *dpy, QObject *parent = 0);
#endif
    
    void run();
private:
#ifdef USE_XCB
    xcb_connection_t *conn;
#else
    void *dpy;
#endif
signals:
    void eventRecived();
public slots:
    
};

#endif // KBDSTATELISTENER_H
