#ifndef INPUTPLATFORM_H
#define INPUTPLATFORM_H
#include "types.h"
#include <QString>
#include <QList>

class InputPlatform
{
public:

    virtual void connect()=0;
    virtual ModsState getState()=0;
    virtual void disconnect()=0;
    virtual void sendEvent(char keycode, bool press)=0;
    virtual void setState(Mods mod, ModState state)=0;
    virtual void latchKey(char keycode)=0;
    virtual void lockKey(char keycode)=0;
    virtual void waitNextEvent()=0;
    virtual void selectEvents()=0;
    virtual long keysym(char keycode)=0;
    virtual bool isModifier(char keycode, Mods mod)=0;
    virtual QList<Mods> modList(char keycode)=0;
    virtual QString keysymToString(long keysym){
        return QString::number(keysym);
    }
};

#endif // INPUTPLATFORM_H
