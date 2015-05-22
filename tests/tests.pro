QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingAppUnitTests
TEMPLATE = app

CONFIG += console

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
    ../app/tools/SelectionTool.cpp

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
    ../app/tools/SelectionTool.hpp

INCLUDEPATH += \
    ../app \
    ../app/tools \
    ../app/interfaces \
    ../app/shapes \
    ../lib

DESTDIR = $$PWD/../build
