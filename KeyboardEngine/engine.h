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
#include <QQuickItem>

class KeyboardEngine : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(KeyboardEngine)
    Q_ENUMS(Mods)
public:
    enum Mods {Shift, Ctrl, Alt, AltGr, NumLock, CapsLock, Meta};
    KeyboardEngine(QQuickItem *parent = 0);
    ~KeyboardEngine();

    Q_INVOKABLE void refreshLayout();
    Q_INVOKABLE void keyPress(int keycode, bool press);
    Q_INVOKABLE QString keySym(int keycode);
    Q_INVOKABLE void registerModifier(QQuickItem *item, Mods mod);
    Q_INVOKABLE void registerKey(QQuickItem *item);
    Q_INVOKABLE void initialize(QQuickItem *item);
    static QObject *KeyboardEngine_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine);
public slots:
    void modEventRecived();
signals:
    Q_SIGNAL void modifierLatched(int);
    Q_SIGNAL void modifierUnlatched(int);
    Q_SIGNAL void modifierLocked(int);
    Q_SIGNAL void modifierUnlocked(int);
    Q_SIGNAL void modifierEffective(int);
    Q_SIGNAL void modifierUneffective(int);
private:
    QVector<QList<QQuickItem*> > modifierItems;
    QList<QQuickItem*> keys;
    static KeyboardEngine *singleton;

    enum ModState {Unsetted, Effective, Latched, Locked};

    QVector<char> modsState;
#ifdef USE_XCB

    xcb_connection_t *conn;

#else

    void *dpy;

#endif
};

#endif // ENGINE_H

