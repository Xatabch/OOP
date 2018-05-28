#ifndef ADAPTER_H
#define ADAPTER_H

#include <QApplication>

#include "mainwindow.h"
#include "facade.h"

class Adapter : public Facade
{
public:
    MainWindow w;
    int createUI(int, char *[]);
    void draw();

};

#endif // ADAPTER_H
