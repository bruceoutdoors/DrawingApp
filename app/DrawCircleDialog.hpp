#ifndef DRAWCIRCLEDIALOG_H
#define DRAWCIRCLEDIALOG_H

#include <QDialog>

namespace Ui {
class DrawCircleDialog;
}

class Circle;

class DrawCircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DrawCircleDialog(QWidget *parent, Circle *circle);
    ~DrawCircleDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_RadiusSpinBox_valueChanged(int arg1);

    void on_XPositionSpinBox_valueChanged(int arg1);

    void on_YPositionSpinBox_valueChanged(int arg1);

private:
    Ui::DrawCircleDialog *ui;
    Circle *m_circle;
};

#endif // DRAWCIRCLEDIALOG_H
