#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include "Canvas.hpp"
#include "DrawCircleDialog.hpp"
#include "Circle.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_canvas = new Canvas(this);

    setCentralWidget(m_canvas);
}

void MainWindow::updateCanvas()
{
    m_canvas->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_canvas;
}

void MainWindow::on_actionCircle_triggered()
{
    Circle *c = new Circle();
    m_canvas->addVisualEntity(c);
    DrawCircleDialog drawCircle(this, c);
    drawCircle.exec();
}
