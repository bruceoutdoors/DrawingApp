#include "DrawCircleDialog.hpp"
#include "ui_drawcircledialog.h"
#include "Circle.hpp"
#include "MainWindow.hpp"

#include <QColorDialog>

DrawCircleDialog::DrawCircleDialog(QWidget *parent, Circle *circle) :
    QDialog(parent),
    ui(new Ui::DrawCircleDialog),
    m_circle(circle)
{
    ui->setupUi(this);

    ui->RadiusSpinBox->setValue(m_circle->getRadius());
    ui->XPositionSpinBox->setValue(m_circle->getPosition().x());
    ui->YPositionSpinBox->setValue(m_circle->getPosition().y());
    ui->OutlineThicknessSpinBox->setValue(m_circle->getlineThickness());

    ui->FillBtn->setText(m_circle->getFillColor().name());
    ui->FillBtn->setStyleSheet(QString("background-color: %1").arg(m_circle->getFillColor().name()));
    ui->FillBtn->setPalette(QPalette(m_circle->getFillColor()));

    ui->OutlineBtn->setText(m_circle->getLineColor().name());
    ui->OutlineBtn->setStyleSheet(QString("background-color: %1").arg(m_circle->getLineColor().name()));
    ui->OutlineBtn->setPalette(QPalette(m_circle->getLineColor()));
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

void DrawCircleDialog::on_FillBtn_clicked()
{
    const QColor color = QColorDialog::getColor(m_circle->getFillColor(), this, "Select Circle fill Color");

    if (color.isValid()) {
        m_circle->setFillColor(color);
        ui->FillBtn->setText(color.name());
        ui->FillBtn->setStyleSheet(QString("background-color: %1")
                                   .arg(color.name()));
        ui->FillBtn->setPalette(QPalette(color));
        ((MainWindow*)parentWidget())->updateCanvas();
    }

}

void DrawCircleDialog::on_OutlineBtn_clicked()
{
    const QColor color = QColorDialog::getColor(m_circle->getLineColor(), this, "Select Circle ouline Color");

    if (color.isValid()) {
        m_circle->setLineColor(color);
        ui->OutlineBtn->setText(color.name());
        ui->OutlineBtn->setStyleSheet(QString("background-color: %1")
                                   .arg(color.name()));
        ui->OutlineBtn->setPalette(QPalette(color));
        ((MainWindow*)parentWidget())->updateCanvas();
    }
}

void DrawCircleDialog::on_OutlineThicknessSpinBox_valueChanged(int arg1)
{
    m_circle->setlineThickness(arg1);
    ((MainWindow*)parentWidget())->updateCanvas();
}
