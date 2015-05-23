#pragma once

#include <QColor>
#include <QObject>

class VisualEntity;
class PropertyColorButton;
class PropertySpinBox;
class Selection;
class ChangeFillColorCommand;
class ChangeLineColorCommand;

// singleton
class GlobalDrawProperties : public QObject
{
	Q_OBJECT

public:
    static GlobalDrawProperties& getInstance();
    void setup(PropertyColorButton *fillColorProp,
               PropertyColorButton *lineColorProp,
               PropertySpinBox *thicknessProp);
    QColor getFillColor();
    QColor getLineColor();
    bool isSetup() { return m_isSetup; }
    int getThickness();
    void update();
    void unlinkProperties();

private slots:
    void onClickFillColor();
    void onSelectFillColor(QColor color);
    void onRejectFillColor();

    void onClickLineColor();
    void onSelectLineColor(QColor color);
    void onRejectLineColor();

private:
    PropertyColorButton *m_fillColorProp;
    PropertyColorButton *m_lineColorProp;
    PropertySpinBox *m_thicknessProp;

    bool m_isSetup;

    ChangeFillColorCommand *m_changeFillColorComm;
    ChangeLineColorCommand *m_changeLineColorComm;

    GlobalDrawProperties() : m_isSetup(false) {}
    ~GlobalDrawProperties() {}
};

