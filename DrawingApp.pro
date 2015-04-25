#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T20:44:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingApp
TEMPLATE = app


SOURCES += main.cpp\
    Canvas.cpp \
    MainWindow.cpp \
    VisualEntity.cpp \
    Shape.cpp \
    Circle.cpp

HEADERS  += \
    IDrawable.hpp \
    MainWindow.hpp \
    Canvas.hpp \
    VisualEntity.hpp \
    ISelectable.hpp \
    IFillable.hpp \
    ILine.hpp \
    Circle.hpp \
    Shape.hpp

FORMS    += mainwindow.ui
