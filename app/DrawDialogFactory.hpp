#pragma once

#include "DrawDialog.hpp"

class MainWindow;
class Shape;
class Circle;
class Rectangle;
class Line;

class DrawDialogFactory
{
public:
    DrawDialogFactory();
    ~DrawDialogFactory();

    static DrawDialog* CreateShapeDrawDialog(MainWindow *parent, Shape *shape);
    static DrawDialog* CreateDrawDialog(MainWindow *parent, Circle *c);
    static DrawDialog* CreateDrawDialog(MainWindow *parent, Rectangle *r);
    static DrawDialog* CreateDrawDialog(MainWindow *parent, Line *l);
};

