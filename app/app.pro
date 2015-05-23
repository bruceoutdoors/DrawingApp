#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T20:44:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingApp
TEMPLATE = app

SOURCES += main.cpp \
    Canvas.cpp \
    MainWindow.cpp \
    VisualEntity.cpp \
    Shape.cpp \
    Canvas.cpp \
    Group.cpp \
    DrawDialog.cpp \
    DrawDialogFactory.cpp \
    Selection.cpp \
    AbstractGroup.cpp \
    Tool.cpp \
    PropertySpinBox.cpp \
    PropertyColorButton.cpp \
    GlobalDrawProperties.cpp \
    CommandStack.cpp \
    Command.cpp \
    shapes/Circle.cpp \
    shapes/Line.cpp \
    shapes/Rectangle.cpp \
    tools/DrawCircleTool.cpp \
    tools/DrawLineTool.cpp \
    tools/DrawRectangleTool.cpp \
    tools/SelectionTool.cpp \
    ActiveSelection.cpp \
    commands/ChangeFillColorCommand.cpp \
    commands/ChangeLineColorCommand.cpp \
    commands/ChangeLineThicknessCommand.cpp \
    commands/DrawCommand.cpp

HEADERS  += \
    MainWindow.hpp \
    Canvas.hpp \
    VisualEntity.hpp \
    Shape.hpp \
    Canvas.hpp \
    Group.hpp \
    DrawDialog.hpp \
    DrawDialogFactory.hpp \
    Selection.hpp \
    Tool.hpp \
    AbstractGroup.hpp \
    PropertySpinBox.hpp \
    PropertyColorButton.hpp \
    GlobalDrawProperties.hpp \
    Command.hpp \
    CommandStack.hpp \
    interfaces/IDrawable.hpp \
    interfaces/IFillable.hpp \
    interfaces/ILine.hpp \
    interfaces/ISelectable.hpp \
    interfaces/ITransformable.hpp \
    shapes/Circle.hpp \
    shapes/Line.hpp \
    shapes/Rectangle.hpp \
    tools/DrawCircleTool.hpp \
    tools/DrawLineTool.hpp \
    tools/DrawRectangleTool.hpp \
    tools/SelectionTool.hpp \
    ActiveSelection.hpp \
    commands/ChangeFillColorCommand.hpp \
    commands/ChangeLineColorCommand.hpp \
    commands/ChangeLineThicknessCommand.hpp \
    commands/DrawCommand.hpp

FORMS    += mainwindow.ui \
    drawdialog.ui

DESTDIR = $$PWD/../build

INCLUDEPATH += \
    $$PWD \
    interfaces \
    commands \
    tools \
    shapes

RESOURCES += \
    resource.qrc
