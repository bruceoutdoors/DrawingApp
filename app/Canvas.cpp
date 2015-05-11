#include "Canvas.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Group.hpp"
#include "Selection.hpp"
#include "SelectionTool.hpp"

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    m_mainGroup = new Group();
    m_selection = &Selection::getInstance();
    m_selectionTool = std::unique_ptr<SelectionTool>(new SelectionTool(m_mainGroup));

    Circle *circle = new Circle();
    QColor fillColor(255, 50, 50);
    circle->setFillColor(fillColor);

    QColor outlineColor(0, 150, 250);
    circle->setLineColor(outlineColor);

    circle->setlineThickness(8);
    circle->setRadius(35);
    circle->setPosition(QPoint(150, 50));

    m_mainGroup->add(circle);

    setBackgroundColor(Qt::white);
    setActiveTool(m_selectionTool.get());
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
    m_mainGroup->add(val);
}

void Canvas::setActiveTool(Tool *val)
{
    m_activeTool = val;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    m_mainGroup->draw(painter);
    m_selection->draw(painter);

    delete painter;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
//    qDebug() << "Click: " << event->pos();

    m_activeTool->handleEvent(event);

    repaint();
}

