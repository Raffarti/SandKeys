#ifndef SHAPE_TYPE_H
#define SHAPE_TYPE_H
class Shape;
#endif // SHAPE_TYPE_H

#ifndef SHAPE_H
#define SHAPE_H
#include <QVector>
#include "geometry.h"
class Shape
{
public:
    Shape(Geometry *parent);
    QVector<QVector<int> > vertex;
    Geometry *parent;
    int getCornerRadius() const;
    void setCornerRadius(int value);

private:
    int cornerRadius = -1;
};

#endif // SHAPE_H
