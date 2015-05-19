#pragma once

#include <QColor>

class VisualEntity;
class PropertyColorButton;
class PropertySpinBox;

// singleton
class GlobalDrawProperties
{
public:
    static GlobalDrawProperties& getInstance();
    void setGlobals(PropertyColorButton *fillColorProp,
                    PropertyColorButton *lineColorProp,
                    PropertySpinBox *thicknessProp);
    QColor getFillColor();
    QColor getLineColor();
    int getThickness();
    void setVisualEntity(VisualEntity *ve);
    void unlinkProperties();

private:
    PropertyColorButton *m_fillColorProp;
    PropertyColorButton *m_lineColorProp;
    PropertySpinBox *m_thicknessProp;

    QColor m_fillColor;
    QColor m_lineColor;

    GlobalDrawProperties() {}
    ~GlobalDrawProperties() {}
    GlobalDrawProperties(GlobalDrawProperties const&) {}
    GlobalDrawProperties& operator=(GlobalDrawProperties const&) {}
};

