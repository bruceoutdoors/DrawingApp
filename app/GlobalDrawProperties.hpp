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
    void setup(PropertyColorButton *fillColorProp,
               PropertyColorButton *lineColorProp,
               PropertySpinBox *thicknessProp);
    QColor getFillColor();
    QColor getLineColor();
    bool isSetup() { return m_isSetup; }
    int getThickness();
    void setVisualEntity(VisualEntity *ve);
    void unlinkProperties();

private:
    PropertyColorButton *m_fillColorProp;
    PropertyColorButton *m_lineColorProp;
    PropertySpinBox *m_thicknessProp;

    QColor m_fillColor;
    QColor m_lineColor;

    bool m_isSetup;

    GlobalDrawProperties() : m_isSetup(false) {}
    ~GlobalDrawProperties() {}
    GlobalDrawProperties(GlobalDrawProperties const&) {}
    GlobalDrawProperties& operator=(GlobalDrawProperties const&) {}
};

