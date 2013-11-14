#ifndef TYPES_H
#define TYPES_H

#include <QVector>

#define NUM_MODS 7
enum ModState {Unsetted, Effective, Latched, Locked};
enum Mods {Shift, Ctrl, Alt, AltGr, NumLock, CapsLock, Meta};

typedef QVector<char> ModsState;

#endif // TYPES_H
