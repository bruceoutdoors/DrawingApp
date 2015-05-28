#include "JsonFileWriter.hpp"
#include "Group.hpp"
#include "VisualEntity.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include "Shape.hpp"

#include <QJsonDocument>
#include <QFile>

JsonFileWriter::JsonFileWriter()
{

}

JsonFileWriter::~JsonFileWriter()
{

}

void JsonFileWriter::setup(Group *mainGroup)
{
    m_mainGroup = mainGroup;
}

bool JsonFileWriter::write(const std::string &fileDir)
{
    QFile saveFile(QString::fromUtf8(fileDir.c_str()));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        return false;
    }

    QJsonObject json;
    json["CanvasShapes"] = writeGroup(m_mainGroup);

    QJsonDocument saveDoc(json);
    saveFile.write(saveDoc.toJson());

    return true;
}

QJsonArray JsonFileWriter::writeGroup(Group *group)
{
    QJsonArray groupArray;
    for (int i = 0; i < group->getSize(); i++) {
        VisualEntity *ve = group->get(i);

        Circle *c = dynamic_cast<Circle*>(ve);

        if (c) {
            groupArray.append(writeCircle(c));
            continue;
        }

        Rectangle *r = dynamic_cast<Rectangle*>(ve);

        if (r) {
            groupArray.append(writeRectangle(r));
            continue;
        }

        Line *l = dynamic_cast<Line*>(ve);

        if (l) {
            groupArray.append(writeLine(l));
            continue;
        }
    }

    return groupArray;
}

QJsonObject JsonFileWriter::writeCircle(Circle *c)
{
    QJsonObject cObj;
    writeShape(c, cObj);

    cObj["Type"] = "Circle";
    cObj["Radius"] = c->getRadius();

    return cObj;
}

QJsonObject JsonFileWriter::writeRectangle(Rectangle *r)
{
    QJsonObject rObj;
    writeShape(r, rObj);

    rObj["Type"] = "Rectangle";
    rObj["Width"] = r->getWidth();
    rObj["Height"] = r->getHeight();

    return rObj;
}

QJsonObject JsonFileWriter::writeLine(Line *l)
{
    QJsonObject lObj;
    lObj["Type"] = "Line";
    lObj["P1"] = writePoint(l->getP1());
    lObj["P2"] = writePoint(l->getP2());
    lObj["LineThickness"] = l->getLineThickness();
    lObj["LineColor"] = writeColor(l->getLineColor());

    return lObj;
}

void JsonFileWriter::writeShape(Shape *s, QJsonObject &obj)
{
    obj["Position"] = writePoint(s->getPosition());
    obj["LineThickness"] = s->getLineThickness();
    obj["FillColor"] = writeColor(s->getFillColor());
    obj["LineColor"] = writeColor(s->getLineColor());
}

QJsonObject JsonFileWriter::writePoint(QPoint p)
{
    QJsonObject pos;
    pos["x"] = p.x();
    pos["y"] = p.y();

    return pos;
}

QJsonObject JsonFileWriter::writeColor(QColor c)
{
    QJsonObject color;
    color["r"] = c.red();
    color["g"] = c.green();
    color["b"] = c.blue();

    return color;
}

