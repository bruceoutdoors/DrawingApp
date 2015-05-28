#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T20:44:30
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingApp
TEMPLATE = app

SOURCES += main.cpp \
    Canvas.cpp \
    MainWindow.cpp \
    VisualEntity.cpp \
    Shape.cpp \
    Group.cpp \
    DrawDialog.cpp \
    DrawDialogFactory.cpp \
    Selection.cpp \
    AbstractGroup.cpp \
    Tool.cpp \
    PropertySpinBox.cpp \
    PropertyColorButton.cpp \
    GlobalDrawProperties.cpp \
    Command.cpp \
    shapes/Circle.cpp \
    shapes/Line.cpp \
    shapes/Rectangle.cpp \
    tools/DrawCircleTool.cpp \
    tools/DrawLineTool.cpp \
    tools/DrawRectangleTool.cpp \
    tools/SelectionTool.cpp \
    ActiveSelection.cpp \
    commands/DrawCommand.cpp \
    commands/DeleteSelectedCommand.cpp \
    commands/MoveSelectionCommand.cpp \
    commands/SendBackwardCommand.cpp \
    commands/ChangeOrderCommand.cpp \
    commands/BringForwardCommand.cpp \
    commands/BringToFrontCommand.cpp \
    commands/SendToBackCommand.cpp \
    MainCommandStack.cpp \
    CommandStack.cpp \
    commands/BulkOrderCommand.cpp \
    fileio/JsonFileReader.cpp \
    fileio/JsonFileWriter.cpp \
    fileio/FileReaderFactory.cpp \
    fileio/FileWriterFactory.cpp

HEADERS  += \
    MainWindow.hpp \
    Canvas.hpp \
    VisualEntity.hpp \
    Shape.hpp \
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
    commands/DrawCommand.hpp \
    commands/DeleteSelectedCommand.hpp \
    commands/MoveSelectionCommand.hpp \
    commands/SendBackwardCommand.hpp \
    commands/ChangeOrderCommand.hpp \
    commands/BringForwardCommand.hpp \
    commands/BringToFrontCommand.hpp \
    commands/SendToBackCommand.hpp \
    MainCommandStack.hpp \
    CommandStack.hpp \
    commands/BulkOrderCommand.hpp \
    interfaces/IFileWriter.hpp \
    interfaces/IFileReader.hpp \
    fileio/JsonFileReader.hpp \
    fileio/JsonFileWriter.hpp \
    fileio/FileReaderFactory.hpp \
    fileio/FileWriterFactory.hpp \
    commands/ChangePropertyCommand.hpp \
    commands/ChangePropertyCommandList.hpp \
    Signal.hpp

FORMS    += mainwindow.ui \
    drawdialog.ui

DESTDIR = $$PWD/../build

INCLUDEPATH += \
    $$PWD \
    interfaces \
    commands \
    tools \
    shapes \
    fileio

RESOURCES += \
    resource.qrc
