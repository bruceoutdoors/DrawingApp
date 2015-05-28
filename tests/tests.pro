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
    SelectionTests.cpp \
    ../app/ActiveSelection.cpp \
    ../app/shapes/Line.cpp \
    ../app/MainCommandStack.cpp \

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
    ../app/ActiveSelection.hpp \
    ../app/shapes/Line.hpp \
    ../app/MainCommandStack.hpp \
    ../app/commands/ChangePropertyCommand.hpp \
    ../app/commands/ChangePropertyCommandList.hpp

INCLUDEPATH += \
    ../app \
    ../app/tools \
    ../app/commands \
    ../app/interfaces \
    ../app/shapes \
    ../app/fileio \
    ../lib

DESTDIR = $$PWD/../build
