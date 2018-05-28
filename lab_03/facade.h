#ifndef FACADE_H
#define FACADE_H

#include <QApplication>

#include "transform.h"
#include "transform_command.h"
#include "director.h"
#include "figure_builder.h"

class Facade
{

public:
    Figure *figure;
    Transform transform;
    TransformCommand* transformCommand;
    Director createFigureDirector;
    FigureBuilder figureBuilder;

    void moveFigure(double, double, double);
    void rotateFigure(double, double, double);
    void scaleFigure(double, double, double);
};

#endif // FACADE_H
