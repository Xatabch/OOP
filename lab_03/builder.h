#ifndef BUILDER_H
#define BUILDER_H

#include "figure.h"
#include <fstream>

class Builder
{
protected:
    Figure* figure;

public:
    Builder() : figure(0) {}
    virtual ~Builder() {}
    virtual void createFigure() = 0;
    virtual void setPolygons(std::ifstream &) = 0;
    virtual void setPoints(std::ifstream &) = 0;
    virtual Figure* getFigure()
    {
        return figure;
    }
};

#endif // BUILDER_H
