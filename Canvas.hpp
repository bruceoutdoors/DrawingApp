#pragma once

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0);
    virtual ~Canvas();

protected:
    void paintEvent(QPaintEvent *event) override;
};

