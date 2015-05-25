#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include "Canvas.hpp"
#include "Group.hpp"
#include "DrawDialogFactory.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include "SelectionTool.hpp"
#include "DrawCircleTool.hpp"
#include "DrawRectangleTool.hpp"
#include "DrawLineTool.hpp"
#include "PropertyColorButton.hpp"
#include "PropertySpinBox.hpp"
#include "GlobalDrawProperties.hpp"
#include "MainCommandStack.hpp"
#include "ActiveSelection.hpp"
#include "DrawCommand.hpp"
#include "DeleteSelectedCommand.hpp"
#include "SendBackwardCommand.hpp"
#include "BringForwardCommand.hpp"
#include "BringToFrontCommand.hpp"
#include "SendToBackCommand.hpp"
#include "FileReaderFactory.hpp"
#include "FileWriterFactory.hpp"

#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QFileInfo>
#include <cassert>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_appName("Drawing App"),
    m_canvasFile("Untitled"),
    m_appStackIdx(-1),
    m_isFileSet(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_canvas = new Canvas(this);
    m_gp = &GlobalDrawProperties::getInstance();
    m_mcs = &MainCommandStack::getInstance();

    m_mcs->setMainWindow(this);

    m_selectionTool = std::unique_ptr<SelectionTool>
            (new SelectionTool(m_canvas));
    m_drawCircleTool = std::unique_ptr<DrawCircleTool>
            (new DrawCircleTool(m_canvas));
    m_drawRectangleTool = std::unique_ptr<DrawRectangleTool>
            (new DrawRectangleTool(m_canvas));
    m_drawLineTool = std::unique_ptr<DrawLineTool>
            (new DrawLineTool(m_canvas));

    m_canvas->setActiveTool(m_selectionTool.get());

    PropertyColorButton *fillColorBtn =
            new PropertyColorButton(this, getCanvas(), QColor(200, 200, 200));

    PropertyColorButton *lineColorBtn =
            new PropertyColorButton(this, getCanvas(), QColor(0, 0, 0));

    PropertySpinBox *thicknessSpinBox =
            new PropertySpinBox(this, getCanvas(), 2);

    m_gp->setup(fillColorBtn, lineColorBtn, thicknessSpinBox);

    ui->VEProp->addRow("Fill Color", fillColorBtn);
    ui->VEProp->addRow("Line Color", lineColorBtn);
    ui->VEProp->addRow("Line Thickness", thicknessSpinBox);

    setCentralWidget(m_canvas);
    this->setWindowTitle(getTitle());
}

Canvas *MainWindow::getCanvas()
{
    return m_canvas;
}

void MainWindow::setActiveTool(Tool *tool)
{
    m_activeTool = tool;
    m_canvas->setActiveTool(tool);
}

bool MainWindow::isDirty() const
{
    return (m_mcs->getCurrentIdx() != m_appStackIdx);
}

bool MainWindow::promptUnsavedWork()
{
    if (isDirty()) {
        auto answer =
                QMessageBox::question(this,
                                      "Save your current work?",
                                      "Looks like you left a masterpiece behind. Do you want to save it?",
                                       QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel));
        if (answer == QMessageBox::Yes) {
            on_actionSave_triggered();
            if (isDirty()) return false;
        } else if (answer == QMessageBox::Cancel) {
            return false;
        }
    }

    return true;
}

void MainWindow::saveFile()
{
    QString ext = QFileInfo(m_canvasFile).suffix();
    IFileWriter *writer = FileWriterFactory::create(ext.toStdString());

    assert(writer != nullptr);

    writer->setup(m_canvas->getMainGroup());

    if (writer->write(m_canvasFile.toStdString())) {
        ui->statusBar->showMessage(QString("Saved file: \"%1\"").arg(m_canvasFile));
    } else {
        QMessageBox::critical(this,
                              "File Write Error",
                              "I can't write to this file. Does it exist, and if so do you give me access to write to it?");
        delete writer;
        return;
    }

    setCommandStackIdx(m_mcs->getCurrentIdx());
    mainCommandStackHasChanged();

    delete writer;
}

void MainWindow::setCommandStackIdx(int val)
{
    m_appStackIdx = val;
}

void MainWindow::mainCommandStackHasChanged()
{
    QString title = getTitle();

    if (isDirty()) {
        title += "*";
    }

    this->setWindowTitle(title);
}

QString MainWindow::getTitle() const
{
    return QString("%1 - %2").arg(m_appName, m_canvasFile);
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

    ActiveSelection::getInstance().deselectAll();
    c->setSelected(true);

    DrawCommand *comm = new DrawCommand(c);
    comm->addtoCommandStack();
}

void MainWindow::on_actionRectangle_triggered()
{
    Rectangle *r = new Rectangle();
    m_canvas->addVisualEntity(r);

    DrawDialog *d = DrawDialogFactory::CreateDrawDialog(this, r);
    d->exec();
    delete d;

    ActiveSelection::getInstance().deselectAll();
    r->setSelected(true);

    DrawCommand *comm = new DrawCommand(r);
    comm->addtoCommandStack();
}

void MainWindow::on_actionLine_triggered()
{
    Line *l = new Line();
    m_canvas->addVisualEntity(l);

    DrawDialog *d = DrawDialogFactory::CreateDrawDialog(this, l);
    d->exec();
    delete d;

    ActiveSelection::getInstance().deselectAll();
    l->setSelected(true);

    DrawCommand *comm = new DrawCommand(l);
    comm->addtoCommandStack();
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

void MainWindow::resetCommandStack()
{
    m_mcs->clear();
    setCommandStackIdx(-1);
    mainCommandStackHasChanged();
}

QString MainWindow::getCanvasFile() const
{
    return m_canvasFile;
}

void MainWindow::setCanvasFile(const QString &value)
{
    m_canvasFile = value;
    m_isFileSet = true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (!promptUnsavedWork()) {
        event->ignore();
    }
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

void MainWindow::on_actionUndo_triggered()
{
    m_mcs->undo();
    m_canvas->repaint();
}

void MainWindow::on_actionRedo_triggered()
{
    m_mcs->redo();
    m_canvas->repaint();
}

void MainWindow::on_actionDelete_triggered()
{
    if (ActiveSelection::getInstance().getSize() == 0) return;

    DeleteSelectedCommand *dsc = new DeleteSelectedCommand();
    dsc->execute();
    dsc->addtoCommandStack();

    m_canvas->repaint();
}

void MainWindow::on_actionSend_Backward_triggered()
{
    if (!ChangeOrderCommand::canChangeOrder()) return;

    SendBackwardCommand *comm = new SendBackwardCommand();
    comm->execute();
    comm->addtoCommandStack();

    m_canvas->repaint();
}

void MainWindow::on_actionBring_Forward_triggered()
{
    if (!ChangeOrderCommand::canChangeOrder()) return;

    BringForwardCommand *comm = new BringForwardCommand();
    comm->execute();
    comm->addtoCommandStack();

    m_canvas->repaint();
}

void MainWindow::on_actionBring_To_Front_triggered()
{
    if (!ChangeOrderCommand::canChangeOrder()) return;

    BringToFrontCommand *comm = new BringToFrontCommand();
    comm->execute();
    comm->addtoCommandStack();

    m_canvas->repaint();
}

void MainWindow::on_actionSend_to_Back_triggered()
{
    if (!ChangeOrderCommand::canChangeOrder()) return;

    SendToBackCommand *comm = new SendToBackCommand();
    comm->execute();
    comm->addtoCommandStack();

    m_canvas->repaint();
}

void MainWindow::on_actionSave_triggered()
{
    if (!m_isFileSet) {
        on_actionSave_As_triggered();
        return;
    }

    if (isDirty()) {
        saveFile();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    if (!promptUnsavedWork()) return;

    QString fileName =
            QFileDialog::getOpenFileName(this,
                                         tr("Open Canvas"),
                                         QDir::currentPath(),
                                         tr("Json (*.json);;All File Types (*.*)"));

    if (fileName.isEmpty()) return;

    QString ext = QFileInfo(fileName).suffix();
    IFileReader *reader = FileReaderFactory::create(ext.toStdString());

    if (reader == nullptr) {
        QMessageBox::critical(this,
                              "Unsupported file type",
                              QString("I can't read *.%1 files.").arg(ext));
        return;
    }

    Group *readCanvas = new Group();
    reader->setup(readCanvas);

    bool canRead = reader->read(fileName.toStdString());
    delete reader;

    if (canRead) {
        m_canvas->setMainGroup(readCanvas);
        ui->statusBar->showMessage(QString("Opened file: \"%1\"").arg(fileName));
    } else {
        delete readCanvas;
        QMessageBox::critical(this,
                              "File Read Error",
                              "I can't read this file ):");
        return;
    }

    setCanvasFile(fileName);

    resetCommandStack();

    m_canvas->repaint();
}

void MainWindow::on_actionNew_triggered()
{
    if (!promptUnsavedWork()) return;

    m_isFileSet = false;
    m_canvasFile = "Untitled";

    m_canvas->getMainGroup()->clear();

    resetCommandStack();

    m_canvas->repaint();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName =
            QFileDialog::getSaveFileName(this,
                                         tr("Save File"),
                                         QDir::currentPath(),
                                         tr("Json (*.json)"));

    if (fileName.isEmpty()) return;

    setCanvasFile(fileName);
    saveFile();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
