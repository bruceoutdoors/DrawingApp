#pragma once

#include <QWidget>
#include <vector>

class VisualEntity;

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0);
    virtual ~Canvas();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<VisualEntity*> m_visuals;
};

