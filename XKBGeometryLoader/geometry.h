#ifndef GEOMETRY_TYPE_H
#define GEOMETRY_TYPE_H
class Geometry;
#endif

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QVector>
#include <QHash>
#include <QString>
#include "indicator.h"
#include "shape.h"

class Geometry{
public:
    Geometry();
    QString name;
    QString description;
    int width;
    int height;
    struct{
        int cornerRadius;
    }shape;

    struct{
        QString offColor;
        QString onColor;
        int left;
        int priority;
        QString shape;
    }indicator;
    QHash<QString,Shape*>shapes;
    QHash<QString, Indicator*> indicators;

    Shape *addShape(QString name);

};

#endif // GEOMETRY_H
