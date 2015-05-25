#include "JsonFileReader.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include "Shape.hpp"
#include "Group.hpp"

#include <stdexcept>
#include <QJsonDocument>
#include <QFile>

JsonFileReader::JsonFileReader()
{

}

JsonFileReader::~JsonFileReader()
{

}

void JsonFileReader::setup(Group *mainGroup)
{
    m_mainGroup = mainGroup;
}

bool JsonFileReader::read(std::string fileDir)
{
    QFile loadFile(QString::fromUtf8(fileDir.c_str()));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    QJsonObject jsonObj = loadDoc.object();
    QJsonArray canvasShapes = jsonObj["CanvasShapes"].toArray();

    readGroup(m_mainGroup, canvasShapes);

    return true;
}

void JsonFileReader::readGroup(Group *group, const QJsonArray &groupObj)
{
    for (int i = 0; i < groupObj.size(); i++) {
        QJsonObject obj = groupObj[i].toObject();

        if (obj["Type"].toString() == "Circle") {
            group->add(readCircle(obj));
        } else if (obj["Type"].toString() == "Rectangle") {
            group->add(readRectangle(obj));
        } else if (obj["Type"].toString() == "Line") {
            group->add(readLine(obj));
        } else {
            throw std::runtime_error("Invalid visual entity!");
        }
    }
}

Circle *JsonFileReader::readCircle(const QJsonObject &c)
{
    Circle *circle = new Circle();
    readShape(circle, c);

    circle->setRadius(c["Radius"].toInt());

    return circle;
}

Rectangle *JsonFileReader::readRectangle(const QJsonObject &r)
{
    Rectangle *rect = new Rectangle();
    readShape(rect, r);

    rect->setWidth(r["Width"].toInt());
    rect->setHeight(r["Height"].toInt());

    return rect;
}

Line *JsonFileReader::readLine(const QJsonObject &l)
{
    Line *line = new Line();

    line->setP1(readPoint(l["P1"].toObject()));
    line->setP2(readPoint(l["P2"].toObject()));
    line->setLineThickness(l["LineThickness"].toInt());
    line->setLineColor(readColor(l["LineColor"].toObject()));

    return line;
}

void JsonFileReader::readShape(Shape *s, const QJsonObject &obj)
{
    s->setPosition(readPoint(obj["Position"].toObject()));
    s->setFillColor(readColor(obj["FillColor"].toObject()));
    s->setLineColor(readColor(obj["LineColor"].toObject()));
    s->setLineThickness(obj["LineThickness"].toInt());
}

QPoint JsonFileReader::readPoint(QJsonObject &p) const
{
    QPoint point(p["x"].toInt(),
                 p["y"].toInt());

    return point;
}

QColor JsonFileReader::readColor(QJsonObject &c) const
{
    QColor color(c["r"].toInt(),
                 c["g"].toInt(),
                 c["b"].toInt());

    return color;
}

