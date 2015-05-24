#pragma once

#include <QMainWindow>
#include <memory>

class Canvas;
class Tool;
class SelectionTool;
class DrawCircleTool;
class DrawRectangleTool;
class DrawLineTool;
class GlobalDrawProperties;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Canvas* getCanvas();
    void setActiveTool(Tool *tool);
    ~MainWindow();

private slots:
    void on_actionCircle_triggered();
    void on_actionRectangle_triggered();
    void on_actionLine_triggered();
    void on_actionSelectionTool_triggered();
    void on_actionDrawCircle_triggered();
    void on_actionDrawRectangle_triggered();
    void on_actionDrawLine_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionDelete_triggered();
    void on_actionSend_Backward_triggered();
    void on_actionBring_Forward_triggered();
    void on_actionBring_To_Front_triggered();
    void on_actionSend_to_Back_triggered();

private:
    void uncheckAllToolbar();

    Ui::MainWindow *ui;
    Canvas *m_canvas;
    Tool *m_activeTool;
    GlobalDrawProperties *m_gp;

    std::unique_ptr<SelectionTool> m_selectionTool;
    std::unique_ptr<DrawCircleTool> m_drawCircleTool;
    std::unique_ptr<DrawRectangleTool> m_drawRectangleTool;
    std::unique_ptr<DrawLineTool> m_drawLineTool;
};

