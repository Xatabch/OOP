#include "figure_builder.h"

const int FigureBuilder::X = 0;
const int FigureBuilder::Y = 1;
const int FigureBuilder::Z = 2;

void FigureBuilder::createFigure()
{
    this->figure = new Figure;
}

void FigureBuilder::setPolygons(std::ifstream& file)
{
    char *line = new char(20);
    size_t mem_size = 20;
    Polygon polygon;
    double num = 0;

    while (file.getline(line, mem_size))
    {
        if(strchr(line, 'f'))
        {
            char *pch = strtok (line," ");
            while (pch != NULL)
            {
                if(strchr(pch, '\n'))
                {
                    if(atof(pch))
                    {
                        num = atof(pch);
                        polygon.polygonArray.push_back(num);
                     }
                     pch = strtok (NULL," ");
                     continue;
                 }
                 if(*pch != 'f')
                 {
                     if(atof(pch))
                     {
                         num = atof(pch);
                         polygon.polygonArray.push_back(num);
                      }
                 }
                 pch = strtok(NULL," ");
              }
            if(!polygon.polygonArray.empty())
            {
               figure->polygonsArray.push_back(polygon);
               polygon.polygonArray.clear();
            }
          }
      }

    delete line;
}

void FigureBuilder::setPoints(std::ifstream& file)
{
    char *line = new char(20);
    size_t mem_size = 20;
    double num = 0;
    int j = 0;
    double x,y,z;


    while (file.getline(line, mem_size))
    {
        char *pch = strtok(line," ");
        if(strchr(line, 'f'))
            break;

        while (pch != NULL)
        {
            if(*pch != 'v')
            {
                num = atof(pch);
                if(j == X)
                    x = num;
                else if(j == Y)
                    y = num;
                else if(j == Z)
                    z = num;
                if(j == Z)
                {
                    j = -1;
                    figure->pointsArray.push_back(Point(x,y,z));
                }
                j++;
            }
            pch = strtok(NULL," ");
        }
    }

    delete line;
}
