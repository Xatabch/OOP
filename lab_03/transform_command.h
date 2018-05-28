#ifndef TRANSFORM_COMMAND_H
#define TRANSFORM_COMMAND_H

#include "transform.h"

class TransformCommand
{
protected:
    TransformCommand(Figure* _figure, Transform* t, double _x, double _y, double _z) :figure(_figure), ptrTransform(t) ,x(_x), y(_y), z(_z) {}
    Figure* figure;
    Transform* ptrTransform;
    double x,y,z;

public:
    virtual ~TransformCommand() {}
    virtual void execute() = 0;
};

class MoveFigure : public TransformCommand
{
public:
    MoveFigure(Figure* figure, Transform* t, double x, double y, double z) : TransformCommand(figure, t, x, y, z) {}
    void execute();
};

class RotateFigure : public TransformCommand
{
public:
    RotateFigure(Figure* figure, Transform* t, double x, double y, double z)  : TransformCommand(figure, t, x, y, z) {}
    void execute();
};

class ScaleFigure : public TransformCommand
{
public:
    ScaleFigure(Figure* figure, Transform* t, double x, double y, double z)  : TransformCommand(figure, t, x, y, z) {}
    void execute();
};
#endif // COMMAND_H
