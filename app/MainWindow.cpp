#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include "Canvas.hpp"
#include "DrawDialogFactory.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include "SelectionTool.hpp"
#include "DrawCircleTool.hpp"
#include "DrawRectangleTool.hpp"
#include "DrawLineTool.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_canvas = new Canvas(this);

    m_selectionTool = std::unique_ptr<SelectionTool>(new SelectionTool(m_canvas));
    m_drawCircleTool = std::unique_ptr<DrawCircleTool>(new DrawCircleTool(m_canvas));
    m_drawRectangleTool = std::unique_ptr<DrawRectangleTool>(new DrawRectangleTool(m_canvas));
    m_drawLineTool = std::unique_ptr<DrawLineTool>(new DrawLineTool(m_canvas));

    m_canvas->setActiveTool(m_selectionTool.get());

    setCentralWidget(m_canvas);
}

void MainWindow::updateCanvas()
{
    m_canvas->repaint();
}

void MainWindow::setActiveTool(Tool *tool)
{
    m_activeTool = tool;
    m_canvas->setActiveTool(tool);
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

void MainWindow::on_actionSelectionTool_triggered()
{
    uncheckAllToolbar();
    ui->actionSelectionTool->setChecked(true);
    setActiveTool(m_selectionTool.get());
}

void MainWindow::uncheckAllToolbar()
{
    ui->actionDrawLine->setChecked(false);
    ui->actionDrawCircle->setChecked(false);
    ui->actionDrawRectangle->setChecked(false);
    ui->actionSelectionTool->setChecked(false);
}

void MainWindow::on_actionDrawCircle_triggered()
{
    uncheckAllToolbar();
    ui->actionDrawCircle->setChecked(true);
    setActiveTool(m_drawCircleTool.get());
}

void MainWindow::on_actionDrawRectangle_triggered()
{
    uncheckAllToolbar();
    ui->actionDrawRectangle->setChecked(true);
    setActiveTool(m_drawRectangleTool.get());
}

void MainWindow::on_actionDrawLine_triggered()
{
    uncheckAllToolbar();
    ui->actionDrawLine->setChecked(true);
    setActiveTool(m_drawLineTool.get());
}
