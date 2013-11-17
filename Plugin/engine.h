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

    ModsState modsState;
    InputPlatform *platform;

    void initializeRec(ITEM_TYPE *item);
};

#endif // ENGINE_H

