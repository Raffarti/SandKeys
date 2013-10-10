#include "geometry.h"

Geometry::Geometry()
{
}

Shape *Geometry::addShape(QString name)
{
    Shape *shape = new Shape(this);
    shapes.insert(name, shape);
    return shape;
}
