#include "transform_command.h"

void MoveFigure::execute()
{
    ptrTransform->moveFigure(figure, x, y, z);
}

void RotateFigure::execute()
{
    ptrTransform->rotateFigure(figure, x, y, z);
}

void ScaleFigure::execute()
{
    ptrTransform->scaleFigure(figure, x, y, z);
}
