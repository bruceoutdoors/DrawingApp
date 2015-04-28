#include "Canvas.hpp"
#include "Circle.hpp"
#include "Group.hpp"
#include <QPainter>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    m_mainGroup = new Group();

    Circle *circle = new Circle();
    QColor fillColor(255, 50, 50);
    circle->setFillColor(fillColor);

    QColor outlineColor(0, 150, 250);
    circle->setLineColor(outlineColor);

    circle->setlineThickness(5);
    circle->setRadius(15);
    circle->setPosition(QPoint(150, 50));

    m_mainGroup->addVisualEntity(circle);

    setBackgroundColor(Qt::white);
}

Canvas::~Canvas()
{
    delete m_mainGroup;
}

void Canvas::setBackgroundColor(QColor val)
{
    QPalette Pal;
    Pal.setColor(QPalette::Background, val);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

void Canvas::addVisualEntity(VisualEntity *val)
{
    m_mainGroup->addVisualEntity(val);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    m_mainGroup->draw(painter);

    delete painter;
}

