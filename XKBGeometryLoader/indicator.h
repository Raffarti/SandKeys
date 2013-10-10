#ifndef INDICATOR_TYPE_H
#define INDICATOR_TYPE_H
class Indicator;
#endif
#ifndef INDICATOR_H
#define INDICATOR_H

#include <QString>
#include "geometry.h"

class Indicator{

public:
    Indicator(Geometry *g);
    Geometry *parent;


};

#endif // INDICATOR_H
