#include "GlobalDrawProperties.hpp"
#include "PropertyColorButton.hpp"
#include "PropertySpinBox.hpp"
#include "Line.hpp"
#include "Shape.hpp"

GlobalDrawProperties &GlobalDrawProperties::getInstance()
{
    static GlobalDrawProperties instance;
    return instance;
}

void GlobalDrawProperties::setGlobals(PropertyColorButton *fillColorProp,
                                  PropertyColorButton *lineColorProp,
                                  PropertySpinBox *thicknessProp)
{
    m_fillColorProp = fillColorProp;
    m_lineColorProp = lineColorProp;
    m_thicknessProp = thicknessProp;
}

QColor GlobalDrawProperties::getFillColor()
{
    return m_fillColorProp->getColor();
}

QColor GlobalDrawProperties::getLineColor()
{
    return m_lineColorProp->getColor();
}

int GlobalDrawProperties::getThickness()
{
    return m_thicknessProp->value();
}

void GlobalDrawProperties::setVisualEntity(VisualEntity *ve)
{
    Line *line = dynamic_cast<Line*>(ve);

    if (line) {
        m_lineColor = QColor(line->getLineColor());
        m_lineColorProp->setGetterSetter(
                    [=]() { return line->getLineColor(); },
                    [=](QColor c) { line->setLineColor(c); m_lineColor = QColor(c); });


        m_thicknessProp->setGetterSetter(
                    [=]() { return line->getlineThickness(); },
                    [=](int i) { line->setlineThickness(i); });

        m_fillColorProp->setGetterSetter(
                    [=]() { return getFillColor(); },
                    [=](QColor c) {});
        return;
    }

    Shape *shape = dynamic_cast<Shape*>(ve);

    if (shape) {
        m_lineColor = QColor(shape->getLineColor());
        m_lineColorProp->setGetterSetter(
                    [=]() { return shape->getLineColor(); },
                    [=](QColor c) { shape->setLineColor(c); m_lineColor = QColor(c); });

        m_thicknessProp->setGetterSetter(
                    [=]() { return shape->getlineThickness(); },
                    [=](int i) { shape->setlineThickness(i); });

        m_fillColor = QColor(shape->getFillColor());
        m_fillColorProp->setGetterSetter(
                    [=]() { return shape->getFillColor(); },
                    [=](QColor c) { shape->setFillColor(c); m_fillColor = QColor(c); });
    }
}

void GlobalDrawProperties::unlinkProperties()
{
    m_lineColorProp->setGetterSetter(
                [=]() { return m_lineColor; },
                [=](QColor c) { });

    m_thicknessProp->setGetterSetter(
                [=]() { return m_thicknessProp->value(); },
                [=](int i) { });

    m_fillColorProp->setGetterSetter(
                [=]() { return m_fillColor; },
                [=](QColor c) { });
}


