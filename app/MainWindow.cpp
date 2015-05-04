#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include "Canvas.hpp"
#include "DrawDialogFactory.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"

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

    DrawDialog *d = DrawDialogFactory::CreateDrawDialog(this, c);
    d->exec();
    delete d;
}

void MainWindow::on_actionRectangle_triggered()
{
    Rectangle *r = new Rectangle();
    m_canvas->addVisualEntity(r);

    DrawDialog *d = DrawDialogFactory::CreateDrawDialog(this, r);
    d->exec();
    delete d;
}

void MainWindow::on_actionLine_triggered()
{
    Line *l = new Line();
    m_canvas->addVisualEntity(l);

    DrawDialog *d = DrawDialogFactory::CreateDrawDialog(this, l);
    d->exec();
    delete d;
}
