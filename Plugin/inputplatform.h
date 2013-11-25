#ifndef INPUTPLATFORM_H
#define INPUTPLATFORM_H
#include "types.h"
#include <QString>
#include <QList>

class InputPlatform
{
public:

    /**
     * @brief connect initialize connection to the server.
     */
    virtual void connect()=0;
    /**
     * @brief getState return the current modifiers state.
     * @return a vector representing the modifiers state.
     *@see disconnect
     */
    virtual ModsState getState()=0;
    /**
     * @brief disconnect end the connection.
     */
    virtual void disconnect()=0;
    /**
     * @brief sendEvent emulate a keypress or release event
     * @param keycode keycode representing the physical key
     * @param press true to emulate a keypress, false for key release
     */
    virtual void sendEvent(char keycode, bool press)=0;
    /**
     * @brief setState change a modifier state.
     * @param mod the modifier which state is to be changed
     * @param state the new state for the modifier, if the modifier is already on that state, it will be resetted.
     */
    virtual void setState(Mods mod, ModState state)=0;
    /**
     * @brief latchKey latch/unlatch any modifier owned by the key according to the server modifier map.
     * @param keycode a keycode.
     */
    virtual void latchKey(char keycode)=0;
    /**
     * @brief lockKey lock/unlock any modifier owned by the key according to the server modifier map.
     * @param keycode a keycode.
     */
    virtual void lockKey(char keycode)=0;
    /**
     * @brief waitNextEvent just wait for next keyboard state event
     * @see selectEvents
     */
    virtual void waitNextEvent()=0;
    /**
     * @brief selectEvents select the event type to wait for
     * @see waitNextEvent
     */
    virtual void selectEvents()=0;
    /**
     * @brief keysym return a keysym according with the server state and map, give a keycode
     * @param keycode a keycode standing for a physical key.
     * @return a keysym representing the logical key.
     */
    virtual long keysym(char keycode)=0;
    /**
     * @brief isModifier check if a keycode own the given modifier (according to the server modifier map)
     * @param keycode a keycode standing for a physical key.
     * @param mod a modifier.
     * @return true if the keycode own the modifier, false otherwise.
     */
    virtual bool isModifier(char keycode, Mods mod)=0;
    /**
     * @brief modList returns the list of the modifiers owned by a key according to the server modifier map.
     * @param keycode a keycode standing for a physical key.
     * @return the modifier list, an empty list if the key own no modifier.
     */
    virtual QList<Mods> modList(char keycode)=0;
    /**
     * @brief canLatch return if the platform can latch modifiers.
     * @return true if the platform can latch, false otherwise.
     */
    virtual bool canLatch() const = 0;
    /**
     * @brief hasEffectiveModifiers
     * @return
     */
    virtual bool hasEffectiveModifiers() const = 0;
    /**
     * @brief keysymToString convert a keysym to a string representation, if not implemented returns the keysym as QString.
     * @param keysym keysym to convert.
     * @return string representation for the keysym.
     */
    virtual QString keysymToString(long keysym){
        return QString::number(keysym);
    }
};

#endif // INPUTPLATFORM_H
