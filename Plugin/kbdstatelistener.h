#ifndef KBDSTATELISTENER_H
#define KBDSTATELISTENER_H

#include "inputplatform.h"
#include <QThread>

class KbdStateListener : public QThread
{
    Q_OBJECT
public:
    explicit KbdStateListener(InputPlatform *platform, QObject *parent = 0);
    
    void run();
signals:
    void eventRecived();
public slots:
    
private:
    InputPlatform *platform;
};

#endif // KBDSTATELISTENER_H
