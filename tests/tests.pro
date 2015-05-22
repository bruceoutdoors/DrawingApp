QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingAppUnitTests
TEMPLATE = app

CONFIG += console

SOURCES += TestMain.cpp \
    ../app/Canvas.cpp \
    ../app/Circle.cpp \
    ../app/Group.cpp \
    ../app/Shape.cpp \
    ../app/VisualEntity.cpp \
    GroupTests.cpp \
    VisualEntityTests.cpp \
    ../app/Rectangle.cpp \
    ../app/Selection.cpp \
    ../app/AbstractGroup.cpp \
    ../app/SelectionTool.cpp \
    ../app/Tool.cpp \
    ../app/GlobalDrawProperties.cpp \
    ../app/PropertyColorButton.cpp \
    ../app/PropertySpinBox.cpp \
    ../app/CommandStack.cpp \
    CommandStackTest.cpp \
    ../app/Command.cpp

HEADERS += \
    ../app/Canvas.hpp \
    ../app/Circle.hpp \
    ../app/Group.hpp \
    ../app/IDrawable.hpp \
    ../app/IFillable.hpp \
    ../app/ILine.hpp \
    ../app/ISelectable.hpp \
    ../app/ITransformable.hpp \
    ../app/Shape.hpp \
    ../app/VisualEntity.hpp \
    ../app/Rectangle.hpp \
    ../app/Selection.hpp \
    ../app/AbstractGroup.h \
    ../app/SelectionTool.hpp \
    ../app/Tool.hpp \
    ../app/GlobalDrawProperties.hpp \
    ../app/PropertyColorButton.hpp \
    ../app/PropertySpinBox.hpp \
    ../app/Command.hpp \
    ../app/CommandStack.hpp

INCLUDEPATH += \
    ../app \
    ../lib

DESTDIR = $$PWD/../build
