#ifndef ENGINE_H
#define ENGINE_H

#ifdef USE_XCB

#define xcb_key_symbols_alloc xcb_key_symbols_alloc_broken
#include <xcb/xcb.h>
#undef xcb_key_symbols_alloc
#include <xcb/xtest.h>
#define explicit explicit_
#include <xcb/xkb.h>
#undef explicit
#include <xcb/xcb_keysyms.h>

#else



#endif

#define NUM_MODS 7
#ifdef USE_QT5
#include <QQuickItem>
#else
#include <QDeclarativeItem>
#endif
#include <QHash>
#include <QDir>

class KeyboardEngine : public PARENT_TYPE
{
    Q_OBJECT
    Q_DISABLE_COPY(KeyboardEngine)
    Q_ENUMS(Mods)
public:
    enum Mods {Shift, Ctrl, Alt, AltGr, NumLock, CapsLock, Meta};
    KeyboardEngine(PARENT_TYPE *parent = 0);
    ~KeyboardEngine();

    Q_INVOKABLE void refreshLayout();
    Q_INVOKABLE void keyPress(int keycode, bool press);
    Q_INVOKABLE QString keySym(int keycode);
#ifdef USE_QT5
    Q_INVOKABLE void registerModifier(QQuickItem *item, Mods mod);
    Q_INVOKABLE void registerKey(QQuickItem *item);
    Q_INVOKABLE void initialize(QQuickItem *item);
#else
    Q_INVOKABLE void registerModifier(QDeclarativeItem *item, Mods mod);
    Q_INVOKABLE void registerKey(QDeclarativeItem *item);
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

    enum ModState {Unsetted, Effective, Latched, Locked};

    QVector<char> modsState;

#ifdef USE_XCB

    xcb_connection_t *conn;

#else

    void *dpy;

#endif
    void initializeRec(ITEM_TYPE *item);
};

#endif // ENGINE_H

