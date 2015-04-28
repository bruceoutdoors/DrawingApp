#include "DrawCircleDialog.hpp"
#include "ui_drawcircledialog.h"
#include "Circle.hpp"
#include "MainWindow.hpp"

DrawCircleDialog::DrawCircleDialog(QWidget *parent, Circle *circle) :
    QDialog(parent),
    ui(new Ui::DrawCircleDialog),
    m_circle(circle)
{
    ui->setupUi(this);

    ui->RadiusSpinBox->setValue(m_circle->getRadius());
    ui->XPositionSpinBox->setValue(m_circle->getPosition().x());
    ui->YPositionSpinBox->setValue(m_circle->getPosition().y());
}

DrawCircleDialog::~DrawCircleDialog()
{
    delete ui;
}

void DrawCircleDialog::on_buttonBox_accepted()
{

}

void DrawCircleDialog::on_buttonBox_rejected()
{
    m_circle->selfDestruct();
}

void DrawCircleDialog::on_RadiusSpinBox_valueChanged(int arg1)
{
    m_circle->setRadius(arg1);
    ((MainWindow*)parentWidget())->updateCanvas();
}

void DrawCircleDialog::on_XPositionSpinBox_valueChanged(int arg1)
{
    m_circle->setPosition(QPoint(arg1, m_circle->getPosition().y()));
    ((MainWindow*)parentWidget())->updateCanvas();
}

void DrawCircleDialog::on_YPositionSpinBox_valueChanged(int arg1)
{
    m_circle->setPosition(QPoint(m_circle->getPosition().x(), arg1));
    ((MainWindow*)parentWidget())->updateCanvas();
}
