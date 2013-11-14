#ifndef AUTOREPEATER_H
#define AUTOREPEATER_H

#include <QObject>
#include "inputplatform.h"
#include <QMap>
#include <QTimer>

class AutoRepeater : public QObject
{
    Q_OBJECT
public:
    static InputPlatform *platform;
    explicit AutoRepeater(char keycode, QObject *parent = 0);
    static void end(char keycode);
    static void begin(char keycode);
private:
    char keycode;
    static QMap<char, QTimer*> *map;
public slots:
    void repeat();

signals:

public slots:

};

#endif // AUTOREPEATER_H
