#ifndef DRAWCIRCLEDIALOG_H
#define DRAWCIRCLEDIALOG_H

#include "MainWindow.hpp"
#include <functional>
#include <QDialog>

namespace Ui {
class DrawDialog;
}

class VisualEntity;

class DrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DrawDialog(MainWindow *parent);
    void appendSpinBox(QString label,
                       std::function<int()> getter,
                       std::function<void(int)> setter);
    void appendColorPicker(QString label,
                           std::function<QColor()> getter,
                           std::function<void(QColor)> setter);
    virtual ~DrawDialog();

private:
    Ui::DrawDialog *ui;
    MainWindow *m_parent;
};

#endif // DRAWCIRCLEDIALOG_H
