#ifndef ENGINE_H
#define ENGINE_H

#ifdef USE_QT5
#include <QQuickItem>
#else
#include <QDeclarativeItem>
#endif
#include <QHash>
#include <QDir>
#include <QTimer>
#include "types.h"
#include "inputplatform.h"

class KeyboardEngine : public PARENT_TYPE
{
    Q_OBJECT
    Q_DISABLE_COPY(KeyboardEngine)
    Q_ENUMS(p_Mods)
public:
    enum p_Mods {Shift, Ctrl, Alt, AltGr, NumLock, CapsLock, Meta};
    KeyboardEngine(PARENT_TYPE *parent = 0);
    ~KeyboardEngine();

    /**
      @brief invoke refresh() method for each registered key, tipically caused by a modifier status change.
      @see registerKey registerKeyAuto
    */
    Q_INVOKABLE void refreshLayout();
    /**
      @brief emulate a key press or release, keycode is an evdev keycode (usually inside /usr/share/X11/xkb/keycodes/evdev).
      @param keycode a keycode representing a physical key.
      @param press true to emulate a keypress, false for key release.
    */
    Q_INVOKABLE void keyPress(int keycode, bool press);
    /**
      @brief return the keysym you would obtain with a keypress with the current keyboard state
      @param keycode a keycode representing a physical key.
    */
    Q_INVOKABLE QString keySym(int keycode);
#ifdef USE_QT5
    /**
      @brief register a qml item as modifier, the methods 'activate', 'latch', 'lock' and 'reset' of the item will be called (if any).
      @param item a qml item
      @param mod the modifier for the item's methods will be invoked.
      @see registerKey registerKeyAuto
    */
    Q_INVOKABLE void registerModifier(QQuickItem *item, Mods mod);
    /**
      @brief register a qml item as a key, the method 'refresh' of the item will be called (if any) on layout changes or such, the item need a 'keycode' property filled with the wanted keycode.
      @param item a qml item
      @see registerModifier registerKeyAuto
    */
    Q_INVOKABLE void registerKey(QQuickItem *item);
    /**
      @brief register a qml item using 'registerModifier' and 'registerKey' internally, register modifier will be called according with the server modifier map using the 'keycode' property of the item;
      @param item a qml item
      @see registerKey registerModifier
    */
    Q_INVOKABLE void registerKeyAuto(QQuickItem *item);
    /**
      @brief recursively check the given item and its children, any item owning a 'keycode' propertly will be registered.
      @param item a qml item
      @see registerKeyAuto
    */
    Q_INVOKABLE void initialize(QQuickItem *item);
#else
    /**
      @brief register a qml item as modifier, the methods 'activate', 'latch', 'lock' and 'reset' of the item will be called (if any).
      @param item a qml item
      @param mod the modifier for the item's methods will be invoked.
      @see registerKey registerKeyAuto
    */
    Q_INVOKABLE void registerModifier(QDeclarativeItem *item, Mods mod);
    /**
      @brief register a qml item as a key, the method 'refresh' of the item will be called (if any) on layout changes or such, the item need a 'keycode' property filled with the wanted keycode.
      @param item a qml item
      @see registerModifier registerKeyAuto
    */
    Q_INVOKABLE void registerKey(QDeclarativeItem *item);
    /**
      @brief register a qml item using 'registerModifier' and 'registerKey' internally, register modifier will be called according with the server modifier map using the 'keycode' property of the item;
      @param item a qml item
      @see registerKey registerModifier
    */
    Q_INVOKABLE void registerKeyAuto(QDeclarativeItem *item);
    /**
      @brief recursively check the given item and its children, any item owning a 'keycode' propertly will be registered.
      @param item a qml item
      @see registerKeyAuto
    */
    Q_INVOKABLE void initialize(QDeclarativeItem *item);
#endif
#ifdef USE_QT5
    static QObject *KeyboardEngine_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine);
#endif
public slots:
    void modEventRecived();

public slots:
    void reset();
signals:
    Q_SIGNAL void modifierLatched(int);
    Q_SIGNAL void modifierUnlatched(int);
    Q_SIGNAL void modifierLocked(int);
    Q_SIGNAL void modifierUnlocked(int);
    Q_SIGNAL void modifierEffective(int);
    Q_SIGNAL void modifierUneffective(int);
private:

    QVector<QList<ITEM_TYPE*> > modifierItems;
    QList<ITEM_TYPE*> keys;
    static KeyboardEngine *singleton;
    QHash<int, QString> symbolMap;

    ModsState modsState;
    InputPlatform *platform;

    void initializeRec(ITEM_TYPE *item);
};

#endif // ENGINE_H

