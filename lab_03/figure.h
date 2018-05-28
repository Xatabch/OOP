#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

#include "point.h"
#include "polygon.h"

class Figure
{
public:
    std::vector<Point> pointsArray;
    std::vector<Polygon> polygonsArray;
};

#endif // FIGURE_H
