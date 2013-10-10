#include "shape.h"

Shape::Shape(Geometry *parent) : parent(parent)
{
}
int Shape::getCornerRadius() const
{
    return cornerRadius!=-1?cornerRadius:parent->shape.cornerRadius;
}

void Shape::setCornerRadius(int value)
{
    cornerRadius = value;
}

