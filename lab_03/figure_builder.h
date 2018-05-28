#ifndef FIGURE_BUILDER_H
#define FIGURE_BUILDER_H

#include "builder.h"

class FigureBuilder : public Builder
{
public:
    static const int X;
    static const int Y;
    static const int Z;
    void createFigure();
    void setPolygons(std::ifstream &);
    void setPoints(std::ifstream &);
};

#endif // FIGURE_BUILDER_H
