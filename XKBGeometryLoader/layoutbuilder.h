#ifndef LAYOUTBUILDER_H
#define LAYOUTBUILDER_H

#include <QFile>
#include <QWidget>
#include <QTextStream>
#include <QStack>
#include <QHash>
#include "indicator.h"
#include "geometry.h"



class LayoutBuilder
{
public:
    LayoutBuilder(QFile *file);
    QWidget *build(QString name);
private:
    QString sep = "    ";

    QTextStream text;

    QChar pick;
    QChar pop();

    void pComment();
    void pDefault();
    Geometry *pGeometry();
    void pGeomAttribute(Geometry *g);
    void pShape(Geometry *g);
    void pShapeAttribute(Geometry *g);
    void pShapeStruct(Shape *shape);
    void pShapeStructAttribute(Shape *shape);
    void pShapeVertex(Shape *shape);

    QString getVarName();
    QString getString();
    int getInt();
    QString getStringAssignment();
    int getIntegerAssignment();

    QList<Geometry*> geoms;
    Geometry *defaultGeom;

    QString outLevel;
};

#endif // LAYOUTBUILDER_H
