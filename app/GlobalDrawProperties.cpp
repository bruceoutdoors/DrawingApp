#include "GlobalDrawProperties.hpp"
#include "PropertyColorButton.hpp"
#include "PropertySpinBox.hpp"
#include "Line.hpp"
#include "Shape.hpp"
#include "ActiveSelection.hpp"

#include <QDebug>
#include <QColorDialog>

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

    connect(m_fillColorProp, &PropertyColorButton::pressed,
            this, &GlobalDrawProperties::onClickFillColor);
    connect(m_fillColorProp->getColorDialog(), &QColorDialog::colorSelected,
            this, &GlobalDrawProperties::onSelectFillColor);
    connect(m_fillColorProp->getColorDialog(), &QColorDialog::rejected,
            this, &GlobalDrawProperties::onRejectFillColor);

    connect(m_lineColorProp, &PropertyColorButton::pressed,
            this, &GlobalDrawProperties::onClickLineColor);
    connect(m_lineColorProp->getColorDialog(), &QColorDialog::colorSelected,
            this, &GlobalDrawProperties::onSelectLineColor);
    connect(m_lineColorProp->getColorDialog(), &QColorDialog::rejected,
            this, &GlobalDrawProperties::onRejectLineColor);
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
        m_changeLineColorComm->setValue(c);
        m_changeLineColorComm->execute();
    };

    const static auto setFillColorFunc = [=](QColor c) {
        m_changeFillColorComm->setValue(c);
        m_changeFillColorComm->execute();
    };

    const static auto setThicknessFunc = [=](int t) {
        ChangeLineThicknessCommand *changeLineThicknessComm =
                new ChangeLineThicknessCommand();
        changeLineThicknessComm->setValue(t);
        changeLineThicknessComm->execute();
        changeLineThicknessComm->addtoCommandStack();
    };

    if (selection->getSize() == 0) {
        unlinkProperties();
        return;
    }

    VisualEntity *ve = selection->getLastSelected();
    Line *line = dynamic_cast<Line*>(ve);

    if (line) {
        m_lineColorProp->setGetterSetter(
                    [=]() { return line->getLineColor(); },
                    setLineColorFunc);

        m_thicknessProp->setGetterSetter(
                    [=]() { return line->getLineThickness(); },
                    setThicknessFunc);

        m_fillColorProp->setGetterSetter(
                    [=]() { return getFillColor(); },
                    setFillColorFunc);
        return;
    }

    Shape *shape = dynamic_cast<Shape*>(ve);

    if (shape) {
        m_lineColorProp->setGetterSetter(
                    [=]() { return shape->getLineColor(); },
                    setLineColorFunc);

        m_thicknessProp->setGetterSetter(
                    [=]() { return shape->getLineThickness(); },
                    setThicknessFunc);

        m_fillColorProp->setGetterSetter(
                    [=]() { return shape->getFillColor(); },
                    setFillColorFunc);
    }
}

void GlobalDrawProperties::unlinkProperties()
{
    m_lineColorProp->unlink();
    m_thicknessProp->unlink();
    m_fillColorProp->unlink();
}

void GlobalDrawProperties::onClickFillColor()
{
    if (selection->getSize() == 0) return;

    m_changeFillColorComm = new ChangeFillColorCommand();
}

void GlobalDrawProperties::onSelectFillColor(QColor color)
{
    if (m_changeFillColorComm == nullptr) return;

    if (selection->getSize() == 0) return;

    m_changeFillColorComm->setValue(color);
    m_changeFillColorComm->addtoCommandStack();

    m_changeFillColorComm = nullptr;
}

void GlobalDrawProperties::onRejectFillColor()
{
    if (selection->getSize() == 0) return;

    m_changeFillColorComm->undo();
    delete m_changeFillColorComm;
}

void GlobalDrawProperties::onClickLineColor()
{
    if (selection->getSize() == 0) return;

    m_changeLineColorComm = new ChangeLineColorCommand();
}

void GlobalDrawProperties::onSelectLineColor(QColor color)
{
    if (m_changeLineColorComm == nullptr) return;

    if (selection->getSize() == 0) return;

    m_changeLineColorComm->setValue(color);
    m_changeLineColorComm->addtoCommandStack();

    m_changeLineColorComm = nullptr;
}

void GlobalDrawProperties::onRejectLineColor()
{
    if (selection->getSize() == 0) return;

    m_changeLineColorComm->undo();
    delete m_changeLineColorComm;
}
