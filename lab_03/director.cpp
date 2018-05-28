#include "director.h"

Figure* Director::createFigure(FigureBuilder &builder,char* fileName)
{
    builder.createFigure();

    std::ifstream file;
    file.open(fileName);
    if(file.is_open())
    {
        builder.setPolygons(file);
        file.close();
        file.open(fileName);
        builder.setPoints(file);
        file.close();
        return (builder.getFigure());
    }
    else
    {
        throw std::runtime_error("Ошибка создания фигуры");
    }

}
