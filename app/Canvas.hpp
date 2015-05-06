#pragma once

#include <QWidget>
#include <vector>

class VisualEntity;
class Group;
class Selection;

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0);
    virtual ~Canvas();
    void setBackgroundColor(QColor val);
    void addVisualEntity(VisualEntity *val);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    Group *m_mainGroup;
    Selection *m_selection;
};

