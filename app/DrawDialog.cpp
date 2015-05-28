#include "DrawDialog.hpp"
#include "ui_drawdialog.h"
#include "Circle.hpp"
#include "MainWindow.hpp"
#include "PropertyColorButton.hpp"
#include "PropertySpinBox.hpp"

#include <QDebug>

DrawDialog::DrawDialog(MainWindow *parent) :
    QDialog(parent),
    m_parent(parent),
    ui(new Ui::DrawDialog)
{
    ui->setupUi(this);

}

void DrawDialog::appendSpinBox(QString label,
                               std::function<int()> getter,
                               std::function<void(int)> setter)
{
    PropertySpinBox *b = new PropertySpinBox(this, m_parent->getCanvas(), getter, setter);

    ui->formLayout->addRow(label, b);
}

void DrawDialog::appendColorPicker(QString label,
                                   std::function<QColor()> getter,
                                   std::function<void(QColor)> setter)
{
    PropertyColorButton *b = new PropertyColorButton(this, m_parent->getCanvas(), getter, setter);

    ui->formLayout->addRow(label, b);
}

DrawDialog::~DrawDialog()
{
    delete ui;
}
