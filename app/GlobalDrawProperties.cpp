#include "GlobalDrawProperties.hpp"
#include "PropertyColorButton.hpp"
#include "PropertySpinBox.hpp"
#include "Line.hpp"
#include "Shape.hpp"
#include "ActiveSelection.hpp"

ActiveSelection *selection = &ActiveSelection::getInstance();

GlobalDrawProperties &GlobalDrawProperties::getInstance()
{
    static GlobalDrawProperties instance;
    return instance;
}

void GlobalDrawProperties::setup(PropertyColorButton *fillColorProp,
                                  PropertyColorButton *lineColorProp,
                                  PropertySpinBox *thicknessProp)
{
    m_isSetup = true;

    m_fillColorProp = fillColorProp;
    m_lineColorProp = lineColorProp;
    m_thicknessProp = thicknessProp;

    m_fillColor = m_fillColorProp->getColor();
    m_lineColor = m_lineColorProp->getColor();
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

// get from one source; apply to many
void GlobalDrawProperties::update()
{
    const static auto setLineColorFunc = [=](QColor c) {
        for (int i = 0; i < selection->getSize(); i++) {
            VisualEntity *entity = selection->get(i);
            Line *l = dynamic_cast<Line*>(entity);

            if (l) {
                l->setLineColor(c);
                m_lineColor = c;
                continue;
            }

            Shape *s = dynamic_cast<Shape*>(entity);

            if (s) {
                s->setLineColor(c);
                m_lineColor = c;
            }
        }
    };

    const static auto setFillColorFunc = [=](QColor c) {
        for (int i = 0; i < selection->getSize(); i++) {
            VisualEntity *entity = selection->get(i);

            if (dynamic_cast<Line*>(entity)) continue;

            Shape *s = dynamic_cast<Shape*>(entity);

            if (s) {
                s->setFillColor(c);
                m_fillColor = c;
            }
        }
    };

    const static auto setThicknessFunc = [=](int t) {
        for (int i = 0; i < selection->getSize(); i++) {
            VisualEntity *entity = selection->get(i);

            Line *l = dynamic_cast<Line*>(entity);

            if (l) {
                l->setlineThickness(t);
                continue;
            }

            Shape *s = dynamic_cast<Shape*>(entity);

            if (s) s->setlineThickness(t);
        }
    };

    VisualEntity *ve = selection->getLastSelected();
    Line *line = dynamic_cast<Line*>(ve);

    if (line) {
        m_lineColor = QColor(line->getLineColor());
        m_lineColorProp->setGetterSetter(
                    [=]() { return line->getLineColor(); },
                    setLineColorFunc);

        m_thicknessProp->setGetterSetter(
                    [=]() { return line->getlineThickness(); },
                    setThicknessFunc);

        m_fillColorProp->setGetterSetter(
                    [=]() { return getFillColor(); },
                    setFillColorFunc);
        return;
    }

    Shape *shape = dynamic_cast<Shape*>(ve);

    if (shape) {
        m_lineColor = QColor(shape->getLineColor());
        m_lineColorProp->setGetterSetter(
                    [=]() { return shape->getLineColor(); },
                    setLineColorFunc);

        m_thicknessProp->setGetterSetter(
                    [=]() { return shape->getlineThickness(); },
                    setThicknessFunc);

        m_fillColor = QColor(shape->getFillColor());
        m_fillColorProp->setGetterSetter(
                    [=]() { return shape->getFillColor(); },
                    setFillColorFunc);
    }
}

void GlobalDrawProperties::unlinkProperties()
{
    m_lineColorProp->setGetterSetter(
                [=]() { return m_lineColor; },
                [=](QColor) { });

    m_thicknessProp->setGetterSetter(
                [=]() { return m_thicknessProp->value(); },
                [=](int) { });

    m_fillColorProp->setGetterSetter(
                [=]() { return m_fillColor; },
                [=](QColor) { });
}


