#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "figure.h"
#include "figure_builder.h"

class Director
{
public:
    Figure* createFigure(FigureBuilder&, char*);
};

#endif // DIRECTOR_H
