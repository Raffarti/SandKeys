#ifndef MODIFIERLISTENER_H
#define MODIFIERLISTENER_H

#include <xcb/xcb.h>
#include <xcb/xtest.h>
#define explicit explicit_
#include <xcb/xkb.h>
#undef explicit

#include <QThread>

class ModifierListener : public QThread
{
    Q_OBJECT
public:
    explicit ModifierListener(xcb_connection_t *conn, QObject *parent = 0);

    void run();
private:
    static ModifierListener *listener;
    xcb_connection_t *conn;
signals:
    
public slots:
    
};

#endif // MODIFIERLISTENER_H
