#pragma once

#include "DrawDialog.hpp"

class MainWindow;
class Shape;
class Circle;
class Rectangle;

class DrawDialogFactory
{
public:
    DrawDialogFactory();
    ~DrawDialogFactory();

    static DrawDialog* CreateShapeDrawDialog(MainWindow *parent, Shape *shape);
    static DrawDialog* CreateDrawDialog(MainWindow *parent, Circle *c);
    static DrawDialog* CreateDrawDialog(MainWindow *parent, Rectangle *r);
};

