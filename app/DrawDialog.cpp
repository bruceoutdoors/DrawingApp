#include "DrawDialog.hpp"
#include "ui_drawdialog.h"
#include "Circle.hpp"
#include "MainWindow.hpp"

#include <QColorDialog>
#include <QPushButton>
#include <QSpinBox>
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
    QSpinBox *b = new QSpinBox(this);

    b->setMaximum(999);

    b->setValue(getter());
    connect(b, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int v) {
                setter(v);
                m_parent->updateCanvas();
            }
    );

    ui->formLayout->addRow(label, b);
}

void DrawDialog::appendColorPicker(QString label,
                                   std::function<QColor()> getter,
                                   std::function<void(QColor)> setter)
{
    QPushButton *b = new QPushButton(this);

    b->setText(getter().name());
    b->setStyleSheet(QString("background-color: %1")
                               .arg(getter().name()));
    b->setPalette(QPalette(getter()));

    connect(b, &QPushButton::clicked,
            [=]() {
                const QColor color = QColorDialog::getColor(getter(), this);

                if (color.isValid()) {
                    setter(color);
                    b->setText(color.name());
                    b->setStyleSheet(QString("background-color: %1")
                                               .arg(color.name()));
                    b->setPalette(QPalette(color));
                    m_parent->updateCanvas();
                }
            }
    );

    ui->formLayout->addRow(label, b);
}

DrawDialog::~DrawDialog()
{
    delete ui;
}
