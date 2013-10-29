#include "modifierlistener.h"
ModifierListener *ModifierListener::listener = 0;

ModifierListener::ModifierListener(xcb_connection_t *conn, QObject *parent) :
    QThread(parent), conn(conn)
{
}

void ModifierListener::run()
{
}
