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
    ../app/Rectangle.cpp

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
    ../app/Rectangle.hpp

INCLUDEPATH += \
    ../app \
    ../lib

DESTDIR = $$PWD/../build
