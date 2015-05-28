#include "GlobalDrawProperties.hpp"
#include "PropertyColorButton.hpp"
#include "PropertySpinBox.hpp"
#include "Line.hpp"
#include "Shape.hpp"
#include "ActiveSelection.hpp"

#include <QDebug>
#include <QColorDialog>

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

void GlobalDrawProperties::setVEProperties(VisualEntity *ve)
{
    ILine *l = dynamic_cast<ILine*>(ve);

    if (l) {
        l->setLineColor(getLineColor());
        l->setLineThickness(getThickness());
    }

    IFillable *f = dynamic_cast<IFillable*>(ve);

    if (f) {
        f->setFillColor(getFillColor());
    }
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
void GlobalDrawProperties::update(size_t selSize)
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
        ChangeLineThicknessCommand *comm =
                new ChangeLineThicknessCommand();

        if (comm->canExecute()) {
            comm->setValue(t);
            comm->execute();
            comm->addtoCommandStack();
        } else {
            delete comm;
        }
    };

    if (selSize == 0) {
        unlinkProperties();
        return;
    }

    VisualEntity *ve = m_as->getLastSelected();
    Line *line = dynamic_cast<Line*>(ve);

    if (line) {
        m_lineColorProp->setGetterSetter(
                    [=]() { return line->getLineColor(); },
                    setLineColorFunc);

        m_thicknessProp->setGetterSetter(
                    [=]() { return line->getLineThickness(); },
                    setThicknessFunc);

        // though seemingly doing nothing, this prevents occasions
        // where on global draw properties tries to retrieve the fill
        // color from a destroyed object. This is why we explicitly cast
        // to Shape and Line instead of ILine and IDrawable.
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
    if (m_as->getSize() == 0) return;

    m_changeFillColorComm = new ChangeFillColorCommand();
}

void GlobalDrawProperties::onSelectFillColor(QColor color)
{
    if (m_changeFillColorComm == nullptr) return;

    if (m_changeFillColorComm->canExecute()) {
        m_changeFillColorComm->setValue(color);
        m_changeFillColorComm->addtoCommandStack();
    } else {
        delete m_changeFillColorComm;
    }

    m_changeFillColorComm = nullptr;
}

void GlobalDrawProperties::onRejectFillColor()
{
    if (m_changeFillColorComm == nullptr) return;

    m_changeFillColorComm->undo();
    delete m_changeFillColorComm;
}

void GlobalDrawProperties::onClickLineColor()
{
    if (m_as->getSize() == 0) return;

    m_changeLineColorComm = new ChangeLineColorCommand();
}

void GlobalDrawProperties::onSelectLineColor(QColor color)
{
    if (m_changeLineColorComm == nullptr) return;

    if (m_changeLineColorComm->canExecute()) {
        m_changeLineColorComm->setValue(color);
        m_changeLineColorComm->addtoCommandStack();
    } else {
        delete m_changeLineColorComm;
    }

    m_changeLineColorComm = nullptr;
}

void GlobalDrawProperties::onRejectLineColor()
{
    if (m_changeLineColorComm == nullptr) return;

    m_changeLineColorComm->undo();
    delete m_changeLineColorComm;
}

GlobalDrawProperties::GlobalDrawProperties() :
    m_isSetup(false)
{
    m_as = &ActiveSelection::getInstance();

    m_as->getSelectionSizeChangedSignal()->connect([=](size_t t) {
        update(t);
    });
}
