#ifndef KBDSTATELISTENER_H
#define KBDSTATELISTENER_H

#include <QThread>

class KbdStateListener : public QThread
{
    Q_OBJECT
public:
    explicit KbdStateListener(void *dpy, QObject *parent = 0);
    
    void run();
private:
    void *dpy;
signals:
    void eventRecived();
public slots:
    
};

#endif // KBDSTATELISTENER_H
