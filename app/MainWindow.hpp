#pragma once

#include <QMainWindow>

class Canvas;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateCanvas();
    ~MainWindow();

private slots:
    void on_actionCircle_triggered();
    void on_actionRectangle_triggered();

private:
    Ui::MainWindow *ui;
    Canvas *m_canvas;
};

