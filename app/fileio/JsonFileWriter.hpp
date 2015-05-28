#pragma once

#include "IFileWriter.hpp"
#include <QJsonObject>
#include <QJsonArray>
#include <QPoint>
#include <QColor>

class Circle;
class Shape;
class Line;
class Rectangle;

class JsonFileWriter : public IFileWriter
{
public:
    JsonFileWriter();
    ~JsonFileWriter();

    void setup(Group *mainGroup) override;
    bool write(const std::string &fileDir) override;

private:
    QJsonArray writeGroup(Group *group);
    QJsonObject writeCircle(Circle *c);
    QJsonObject writeRectangle(Rectangle *r);
    QJsonObject writeLine(Line *l);
    void writeShape(Shape *s, QJsonObject &obj);
    QJsonObject writePoint(QPoint p);
    QJsonObject writeColor(QColor c);

    Group *m_mainGroup;
};

