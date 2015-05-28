#pragma once

#include "ChangePropertyCommand.hpp"
#include "IFillable.hpp"
#include "ILine.hpp"

typedef
ChangePropertyCommand<
IFillable,
QColor,
&IFillable::setFillColor,
&IFillable::getFillColor> ChangeFillColorCommand;

typedef
ChangePropertyCommand<
ILine,
QColor,
&ILine::setLineColor,
&ILine::getLineColor>     ChangeLineColorCommand;

typedef
ChangePropertyCommand<
ILine,
int,
&ILine::setLineThickness,
&ILine::getLineThickness> ChangeLineThicknessCommand;
