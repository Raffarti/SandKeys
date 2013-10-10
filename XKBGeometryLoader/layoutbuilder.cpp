#include "layoutbuilder.h"
#include <QDebug>

LayoutBuilder::LayoutBuilder(QFile *file) : text(file)
{
    file->open(QFile::ReadOnly);
    pop();
    while (!text.atEnd()){
        QString name = getVarName();
        while(name.isEmpty()){
            if (pick.isSpace()) pop();
            else if (pick.category() == QChar::Separator_Line) pop();
            else if (pick == '/'){
                pComment();
            }
            else break;
            name = getVarName();
        }
        if (name == "default")
            pDefault();
        else if (name == "xkb_geometry")
            pGeometry();
    }
}

QWidget *LayoutBuilder::build(QString name = "")
{

}

QChar LayoutBuilder::pop()
{
    QChar old = pick;
    text >> pick;
    return old;
}

void LayoutBuilder::pComment()
{
    pop();
    if (pick == '/'){
        text.readLine();
        pop();
    }
}

void LayoutBuilder::pDefault()
{
    qDebug() << outLevel << "pDefault";
    outLevel.append(sep);
    while(!pick.isLetter()){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    getVarName();
    defaultGeom = pGeometry();
    outLevel.chop(sep.size());
    qDebug() << outLevel << "/pDefault";
}

Geometry *LayoutBuilder::pGeometry()
{
    qDebug() << outLevel << "pGeometry";
    outLevel.append(sep);

    Geometry *g = new Geometry;

    while(pick != '"'){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    qDebug() << outLevel << "New Geometry";
    g->name = getString();
    qDebug() << outLevel << "Geometry name:" << g->name;

    while(pick != '{'){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    pop();
    while(1){
        while(!pick.isLetter() || pick != '}'){
            if (pick.isSpace()) pop();
            else if (pick.category() == QChar::Separator_Line) pop();
            else if (pick == '/'){
                pComment();
            }
            else break;
        }
        if (pick.isLetter())
            pGeomAttribute(g);
        else break;
    }
    geoms.append(g);
    outLevel.chop(sep.size());
    qDebug() << outLevel << "/pGeometry";
    return g;
}

void LayoutBuilder::pGeomAttribute(Geometry *g)
{
    qDebug() << outLevel << "pGeomAttribute";
    outLevel.append(sep);

    QString name = getVarName();
    qDebug() << outLevel << "Attribute:" << name;
    if (name == "description") g->name = getStringAssignment();
    else if (name == "width") g->width = getIntegerAssignment();
    else if (name == "height") g->height = getIntegerAssignment();
    else if (name == "shape") pShape(g);

    outLevel.chop(sep.size());
    qDebug() << outLevel << "/pGeomAttribute";
}

void LayoutBuilder::pShape(Geometry *g)
{
    qDebug() << outLevel << "pShape";
    outLevel.append(sep);

    if (pick == '.') pShapeAttribute(g);
    else{
        while(pick != '"'){
            if (pick.isSpace()) pop();
            else if (pick.category() == QChar::Separator_Line) pop();
            else if (pick == '/'){
                pComment();
            }
            else break;
        }
        QString name = getString();
        qDebug() << outLevel << "Shape name:" << name;
        Shape *s = g->addShape(name);
        pShapeStruct(s);
    }

    outLevel.chop(sep.size());
    qDebug() << outLevel << "/pShape";
}

void LayoutBuilder::pShapeAttribute(Geometry *g)
{
    qDebug() << outLevel << "pShapeAttribute";
    outLevel.append(sep);
    pop();

    QString name = getVarName();
    qDebug() << outLevel << "Attribute:" << name;
    if (name == "cornerRadius") g->shape.cornerRadius = getIntegerAssignment();

    outLevel.chop(sep.size());
    qDebug() << outLevel << "/pShapeAttribute";
}

void LayoutBuilder::pShapeStruct(Shape *shape)
{
    qDebug() << outLevel << "pShapeStruct";
    outLevel.append(sep);

    while(pick != '{'){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    pop();
    while(1){
        while(!pick.isLetter() && pick != '{' && pick != '}'){
            if (pick.isSpace()) pop();
            else if (pick.category() == QChar::Separator_Line) pop();
            else if (pick == '/'){
                pComment();
            }
            else break;
        }
        if (pick == '}')break;
        else if (pick.isLetter()) pShapeStructAttribute(shape);
        else if (pick == '{') pShapeVertex(shape);

    }


    outLevel.chop(sep.size());
    qDebug() << outLevel << "/pShapeStruct";

}

void LayoutBuilder::pShapeStructAttribute(Shape *shape)
{
    qDebug() << outLevel << "pShapeStructAttribute";
    outLevel.append(sep);

    QString name = getVarName();
    qDebug() << outLevel << "ShapeStructAttribute:" << name;
    if (name == "cornerRadius") shape->setCornerRadius(getIntegerAssignment());

    outLevel.chop(sep.size());
    qDebug() << outLevel << "/pShapeStructAttribute";
}

void LayoutBuilder::pShapeVertex(Shape *shape)
{
    qDebug() << outLevel << "pShapeVertex";
    outLevel.append(sep);
    pop();
    QVector<int> polygon;
    while(pick != '['){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    pop();
    while (1){
        while(!pick.isDigit()){
            if (pick.isSpace()) pop();
            else if (pick.category() == QChar::Separator_Line) pop();
            else if (pick == '/'){
                pComment();
            }
            else break;
        }
        polygon.append(getInt());
        while(pick != ',' && pick != ']'){
            if (pick.isSpace()) pop();
            else if (pick.category() == QChar::Separator_Line) pop();
            else if (pick == '/'){
                pComment();
            }
            else break;
        }
        if (pick == ',')
            pop();
        else{
            pop();
            break;
        }
    }

    while(pick != '}'){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    pop();
    shape->vertex.append(polygon);
    qDebug() << outLevel << "New Polygon:" << polygon;



    outLevel.chop(sep.size());
    qDebug() << outLevel << "/pShapeVertex";
}


QString LayoutBuilder::getVarName(){
    QString ret;
    while (pick.isLetterOrNumber() || pick == '-' || pick == '_')ret.append(pop());
    return ret;
}

QString LayoutBuilder::getString(){
    QString ret;
    pop();
    while (pick != '"')ret.append(pop());
    pop();
    return ret;
}

int LayoutBuilder::getInt()
{
    QString ret;
    while(pick.isDigit()){
        ret.append(pick);
        pop();
    }
    return ret.toInt();
}

QString LayoutBuilder::getStringAssignment()
{
    while(pick != '='){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    pop();
    while(pick != '"'){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    QString ret = getString();
    while(pick != ';'){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    pop();
    return ret;


}

int LayoutBuilder::getIntegerAssignment()
{
    while(pick != '='){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    pop();
    while(!pick.isNumber()){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    int ret = getInt();
    while(pick != ';'){
        if (pick.isSpace()) pop();
        else if (pick.category() == QChar::Separator_Line) pop();
        else if (pick == '/'){
            pComment();
        }
        else break;
    }
    pop();
    return ret;
}

