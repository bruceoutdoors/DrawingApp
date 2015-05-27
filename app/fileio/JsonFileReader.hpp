#pragma once

#include "IFileReader.hpp"
#include <QJsonObject>
#include <QJsonArray>
#include <QPoint>
#include <QColor>

class Circle;
class Shape;
class Line;
class Rectangle;

class JsonFileReader : public IFileReader
{
public:
    JsonFileReader();
    ~JsonFileReader();

    void setup(Group *mainGroup) override;
    bool read(const std::string &fileDir) override;

private:
    void readGroup(Group *group, const QJsonArray &groupObj);
    Circle *readCircle(const QJsonObject &c);
    Rectangle *readRectangle(const QJsonObject &r);
    Line *readLine(const QJsonObject &l);
    void readShape(Shape *s, const QJsonObject &obj);
    QPoint readPoint(const QJsonObject &p) const;
    QColor readColor(const QJsonObject &c) const;

    Group *m_mainGroup;
};

