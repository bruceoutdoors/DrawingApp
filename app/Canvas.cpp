#include "Canvas.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
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

    Rectangle *r = new Rectangle();

    m_mainGroup->addVisualEntity(circle);
    m_mainGroup->addVisualEntity(r);

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
    m_mainGroup->drawSelectedSelection(painter);

    delete painter;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Click: " << event->pos();

    VisualEntity *clicked = m_mainGroup->getClicked(event->pos().x(), event->pos().y());

    if (clicked != nullptr) {
        qDebug() << "Clicked!";
        clicked->toogleSelect();
        repaint();
    } else {
        qDebug() << "Missed!";
    }
}

