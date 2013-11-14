#include "autorepeater.h"

InputPlatform *AutoRepeater::platform = 0;
QMap<char, QTimer*> *AutoRepeater::map = new QMap<char, QTimer*>;
AutoRepeater::AutoRepeater(char keycode, QObject *parent) :
    QObject(parent), keycode(keycode)
{
}

void AutoRepeater::begin(char keycode)
{
    AutoRepeater *repeater = new AutoRepeater(keycode);
    QTimer *timer = new QTimer();
    repeater->connect(timer, SIGNAL(timeout()), repeater, SLOT(repeat()));
    repeater->connect(timer, SIGNAL(destroyed()), repeater, SLOT(deleteLater()));
    map->insert(keycode, timer);
    timer->setSingleShot(true);
    timer->start(660);
}

void AutoRepeater::end(char keycode)
{
    map->value(keycode)->stop();
    map->value(keycode)->~QTimer();
}

void AutoRepeater::repeat()
{
    platform->sendEvent(keycode, true);
    if (((QTimer*)sender())->isSingleShot()){
        ((QTimer*)sender())->start(40);
    }
}
