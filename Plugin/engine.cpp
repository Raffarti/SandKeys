#include "engine.h"
#include "kbdstatelistener.h"
#include <QDebug>
#include <xkbcommon/xkbcommon.h>

#ifdef USE_XCB
#include "xcbplatform.h"
#elif USE_X11
#include "x11platform.h"
#elif USE_WL
#include "wlplatform.h"
#endif

KeyboardEngine *KeyboardEngine::singleton = 0;
KeyboardEngine::KeyboardEngine(PARENT_TYPE *parent):
    PARENT_TYPE(parent), modifierItems(NUM_MODS)
{
    // By default, ITEM_TYPE does not draw anything. If you subclass
    // ITEM_TYPE to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()
    
    // setFlag(ItemHasContents, true);

#ifndef USE_QT5
    if (!singleton) singleton = this;
    else return;
#endif
    KbdStateListener *statel;
    qDebug("Accessing server...");
    platform = new PLATFORM();
    platform->connect();
    qDebug("Accessing server done.");
    modsState = platform->getState();

    statel = new KbdStateListener(new PLATFORM);
    connect(statel, SIGNAL(eventRecived()), this, SLOT(modEventRecived()));
    statel->start();

    qDebug("Looking for keysym layout symbols...");
    QFileInfoList files = QDir("symbols").entryInfoList(QStringList("*.symbols"),QDir::Files);
    files += QDir("/usr/share/SandKeys/Symbols").entryInfoList(QStringList("*.symbols"),QDir::Files);
    foreach (QFileInfo fi, files) {
        qDebug() << "Found:" << fi.absoluteFilePath();
        QFile f(fi.absoluteFilePath());
        f.open(QFile::ReadOnly);
        while(!f.atEnd()){
#ifdef USE_QT5
            QString l = f.readLine().trimmed();
#else
            QString l = QString::fromUtf8(f.readLine()).trimmed();
#endif
            if (l.startsWith('#')) continue;
            QStringList p = l.split(" ",QString::SkipEmptyParts);
            if (p.isEmpty()) continue;
            int keyid = p[0].toInt();
            if (!keyid) continue;
            if (symbolMap.contains(keyid)) qDebug() << "WARNING: "<<keyid<<"have multiple definitions";
            switch(p.length()){
            case 0:
                continue;
            case 1:
                symbolMap.insert(keyid,"");
                break;
            case 2:
                symbolMap.insert(keyid,p[1]);
                break;
            case 3:
                p.pop_front();
                symbolMap.insert(keyid,p.join(" "));
                break;
            }
        }
    }
    qDebug("Looking for keysym layout symbols done.");
}
#ifdef USE_QT5
QObject *KeyboardEngine::KeyboardEngine_singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    if (!singleton)
        singleton = new KeyboardEngine();
    return singleton;
}
#endif
KeyboardEngine::~KeyboardEngine()
{
    platform->disconnect();
}

void KeyboardEngine::refreshLayout()
{
#ifndef USE_QT5
    if (singleton != this)return singleton->refreshLayout();
#endif
    foreach(ITEM_TYPE *item, keys)
        QMetaObject::invokeMethod(item,"refresh");
}

void KeyboardEngine::keyPress(int keycode, bool press)
{
#ifndef USE_QT5
    if (singleton != this) return singleton->keyPress(keycode, press);
#endif
    platform->sendEvent(keycode, press);
    if (press) platform->latchKey(keycode);
}

QString KeyboardEngine::keySym(int keycode)
{
#ifndef USE_QT5
    if (singleton != this){
        return singleton->keySym(keycode);
    }
#endif
    long keysym = platform->keysym(keycode);
    if (symbolMap.contains(keysym)) return symbolMap[keysym];
    int s = 1;
    char *b = new char[s];
    int ret = xkb_keysym_to_utf8(keysym, b, s);
    while (ret == -1 && s < 32){
        delete b;
        b = new char[++s];
        ret = xkb_keysym_to_utf8(keysym, b, s);
    }
    if (ret > 0)
#ifdef USE_QT5
        return QString(b);
#else
        return QString::fromUtf8(b);
#endif
    return platform->keysymToString(keysym);
}

void KeyboardEngine::registerModifier(ITEM_TYPE *item, Mods mod)
{
#ifndef USE_QT5
    if (singleton != this)return singleton->registerModifier(item, mod);
#endif
    modifierItems[mod].append(item);
}

void KeyboardEngine::registerKey(ITEM_TYPE *item)
{
#ifndef USE_QT5
    if (singleton != this)return singleton->registerKey(item);
#endif
    keys.append(item);
}

void KeyboardEngine::initialize(ITEM_TYPE *item)
{
#ifndef USE_QT5
    if (singleton != this)return singleton->initialize(item);
#endif
    reset();
    initializeRec(item);
}
void KeyboardEngine::initializeRec(ITEM_TYPE *item)
{
#ifndef USE_QT5
    if (singleton != this)return singleton->initializeRec(item);
#endif
    if (item->metaObject()->indexOfProperty("keyCode") != -1){
        char keycode;
        keycode = item->property("keyCode").toInt();

        registerKey(item);

        foreach (Mods mod, platform->modList(keycode))
            registerModifier(item,mod);
    }
    foreach(QObject *obj, item->children()){
        ITEM_TYPE *item = dynamic_cast<ITEM_TYPE *>(obj);
        if (item)
            initializeRec(item);
    }
}

void KeyboardEngine::reset()
{
#ifndef USE_QT5
    if (singleton != this)return singleton->reset();
#endif
    modifierItems = QVector<QList<ITEM_TYPE*> >(NUM_MODS);
    keys.clear();
}


void KeyboardEngine::modEventRecived()
{
    QVector<char> mstatus;

    mstatus = platform->getState();

    for (int s = 0; s < NUM_MODS; s++)
        if (modsState[s] != mstatus[s])
            switch (mstatus[s]){
            case Effective:
                foreach (ITEM_TYPE *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"activate");
                }
                break;
            case Latched:
                foreach (ITEM_TYPE *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"latch");
                }
                break;
            case Locked:
                foreach (ITEM_TYPE *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"lock");
                }
                break;
            default:
                foreach (ITEM_TYPE *i, modifierItems[s]) {
                    QMetaObject::invokeMethod(i,"reset");
                }
                break;
            }
    modsState = mstatus;
    refreshLayout();

}


