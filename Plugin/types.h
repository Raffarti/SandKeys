#ifndef TYPES_H
#define TYPES_H

#include <QVector>

#define NUM_MODS 7
enum ModState {Unsetted=0, Effective=1, Latched=2, Locked=3};
enum Mods {Shift=0, Ctrl=1, Alt=2, AltGr=3, NumLock=4, CapsLock=5, Meta=6};

typedef QVector<ModState> ModsState;

#endif // TYPES_H
