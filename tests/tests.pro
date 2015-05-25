QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingAppUnitTests
TEMPLATE = app

CONFIG += console
CONFIG += c++11

SOURCES += TestMain.cpp \
    ../app/Canvas.cpp \
    ../app/Group.cpp \
    ../app/Shape.cpp \
    ../app/VisualEntity.cpp \
    GroupTests.cpp \
    VisualEntityTests.cpp \
    ../app/Selection.cpp \
    ../app/AbstractGroup.cpp \
    ../app/Tool.cpp \
    ../app/GlobalDrawProperties.cpp \
    ../app/PropertyColorButton.cpp \
    ../app/PropertySpinBox.cpp \
    ../app/CommandStack.cpp \
    CommandStackTest.cpp \
    ../app/Command.cpp \
    ../app/shapes/Circle.cpp \
    ../app/shapes/Rectangle.cpp \
    ../app/tools/SelectionTool.cpp \
    SelectionTests.cpp \
    ../app/ActiveSelection.cpp \
    ../app/commands/ChangeFillColorCommand.cpp \
    ../app/commands/ChangeLineColorCommand.cpp \
    ../app/commands/ChangeLineThicknessCommand.cpp \
    ../app/commands/DrawCommand.cpp \
    ../app/shapes/Line.cpp \
    ../app/commands/MoveSelectionCommand.cpp \
    ../app/MainCommandStack.cpp \
    ../app/MainWindow.cpp \
    ../app/DrawDialog.cpp \
    ../app/DrawDialogFactory.cpp \
    ../app/tools/DrawCircleTool.cpp \
    ../app/tools/DrawLineTool.cpp \
    ../app/tools/DrawRectangleTool.cpp \
    ../app/commands/BringForwardCommand.cpp \
    ../app/commands/BringToFrontCommand.cpp \
    ../app/commands/BulkOrderCommand.cpp \
    ../app/commands/ChangeOrderCommand.cpp \
    ../app/commands/DeleteSelectedCommand.cpp \
    ../app/commands/SendBackwardCommand.cpp \
    ../app/commands/SendToBackCommand.cpp \
    ../app/fileio/JsonFileReader.cpp \
    ../app/fileio/JsonFileWriter.cpp

HEADERS += \
    ../app/Canvas.hpp \
    ../app/Group.hpp \
    ../app/Shape.hpp \
    ../app/VisualEntity.hpp \
    ../app/Selection.hpp \
    ../app/AbstractGroup.h \
    ../app/Tool.hpp \
    ../app/GlobalDrawProperties.hpp \
    ../app/PropertyColorButton.hpp \
    ../app/PropertySpinBox.hpp \
    ../app/Command.hpp \
    ../app/CommandStack.hpp \
    ../app/interfaces/IDrawable.hpp \
    ../app/interfaces/IFillable.hpp \
    ../app/interfaces/ILine.hpp \
    ../app/interfaces/ISelectable.hpp \
    ../app/interfaces/ITransformable.hpp \
    ../app/shapes/Circle.hpp \
    ../app/shapes/Rectangle.hpp \
    ../app/tools/SelectionTool.hpp \
    ../app/ActiveSelection.hpp \
    ../app/commands/ChangeFillColorCommand.hpp \
    ../app/commands/ChangeLineColorCommand.hpp \
    ../app/commands/ChangeLineThicknessCommand.hpp \
    ../app/commands/DrawCommand.hpp \
    ../app/shapes/Line.hpp \
    ../app/commands/MoveSelectionCommand.hpp \
    ../app/MainCommandStack.hpp \
    ../app/MainWindow.hpp \
    ../app/DrawDialog.hpp \
    ../app/DrawDialogFactory.hpp \
    ../app/tools/DrawCircleTool.hpp \
    ../app/tools/DrawLineTool.hpp \
    ../app/tools/DrawRectangleTool.hpp \
    ../app/commands/BringForwardCommand.hpp \
    ../app/commands/BringToFrontCommand.hpp \
    ../app/commands/BulkOrderCommand.hpp \
    ../app/commands/ChangeOrderCommand.hpp \
    ../app/commands/DeleteSelectedCommand.hpp \
    ../app/commands/SendBackwardCommand.hpp \
    ../app/commands/SendToBackCommand.hpp \
    ../app/fileio/JsonFileReader.hpp \
    ../app/fileio/JsonFileWriter.hpp

INCLUDEPATH += \
    ../app \
    ../app/tools \
    ../app/commands \
    ../app/interfaces \
    ../app/shapes \
    ../app/fileio \
    ../lib

DESTDIR = $$PWD/../build

FORMS += \
    ../app/mainwindow.ui \
    ../app/drawdialog.ui
