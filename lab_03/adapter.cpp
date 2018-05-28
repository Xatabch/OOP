#include "adapter.h"

int Adapter::createUI(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

void Adapter::draw()
{
    for(int i = 0; i < figure->numPolygons; i++)
    {
        int j = 0;
        for(j = 0; j < (int)(sizeof(figure->polygonsArray[i].polygonArray)/sizeof(figure->polygonsArray[i].polygonArray[0])); j++)
        {
            size_t ind_1 = figure->polygonsArray[i].polygonArray[j];
            size_t ind_2 = figure->polygonsArray[i].polygonArray[j + 1];
            w.holst->addLine(figure->pointsArray[ind_1].x,
                                 figure->pointsArray[ind_1].y,
                                 figure->pointsArray[ind_2].x,
                                 figure->pointsArray[ind_2].y,
                                 QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));

        }
        size_t ind_1 = figure->polygonsArray[i].polygonArray[0];
        size_t ind_2 = figure->polygonsArray[i].polygonArray[j];
        w.holst->addLine(figure->pointsArray[ind_1].x,
                       figure->pointsArray[ind_1].y,
                       figure->pointsArray[ind_2].x,
                       figure->pointsArray[ind_2].y,
                       QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));

    }
}
