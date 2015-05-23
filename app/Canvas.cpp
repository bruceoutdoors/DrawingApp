#include "Canvas.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Group.hpp"
#include "ActiveSelection.hpp"
#include "SelectionTool.hpp"

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    m_mainGroup = new Group();
    m_selection = &ActiveSelection::getInstance();

    setBackgroundColor(Qt::white);
}

Canvas::~Canvas()
{
    delete m_mainGroup;
}

VisualEntity *Canvas::getVEFromPosition(int x, int y)
{
    return m_mainGroup->getClicked(x, y);
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

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter(this);

    m_mainGroup->draw(painter);
    m_selection->draw(painter);

    delete painter;
}

bool Canvas::event(QEvent *event)
{
    if (event->type() == QEvent::Paint) {
        QPaintEvent *ke = reinterpret_cast<QPaintEvent *>(event);
        paintEvent(ke);
        return true;
    }

    bool result = m_activeTool->handleEvent(event);

    repaint();

    return result;
}
