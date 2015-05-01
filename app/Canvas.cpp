#include "Canvas.hpp"
#include "Circle.hpp"
#include "Group.hpp"

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    m_mainGroup = new Group();

    Circle *circle = new Circle();
    QColor fillColor(255, 50, 50);
    circle->setFillColor(fillColor);

    QColor outlineColor(0, 150, 250);
    circle->setLineColor(outlineColor);

    circle->setlineThickness(8);
    circle->setRadius(35);
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
    m_mainGroup->drawSelection(painter);

    delete painter;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Click: " << event->pos();

    if (m_mainGroup->contains(event->pos().x(), event->pos().y())) {
        qDebug() << "Clicked!";
    } else {
        qDebug() << "Missed!";
    }
}

