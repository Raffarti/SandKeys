#include "kbdstatelistener.h"

KbdStateListener::KbdStateListener(InputPlatform *platform, QObject *parent) :
    QThread(parent),
    platform(platform)
{
    platform->connect();
    platform->selectEvents();
}

void KbdStateListener::run()
{

    forever{
        platform->waitNextEvent();
        emit eventRecived();
    }

}
