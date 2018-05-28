#include "facade.h"

void Facade::moveFigure(double dx, double dy, double dz)
{
    transformCommand = new MoveFigure(figure, &transform, dx, dy, dz);
    transformCommand->execute();
    delete transformCommand;
}

void Facade::rotateFigure(double dx, double dy, double dz)
{
    transformCommand = new RotateFigure(figure, &transform, dx, dy, dz);
    transformCommand->execute();
    delete transformCommand;
}

void Facade::scaleFigure(double dx, double dy, double dz)
{
    transformCommand = new ScaleFigure(figure, &transform, dx, dy, dz);
    transformCommand->execute();
    delete transformCommand;
}
