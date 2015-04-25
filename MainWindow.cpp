#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include "Canvas.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_canvas = new Canvas(this);

    setCentralWidget(m_canvas);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_canvas;
}
