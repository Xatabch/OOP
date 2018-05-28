#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLineEdit>
#include <vector>
#include "facade.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Facade* facade;
    QGraphicsScene *holst;
    void setFigure(char* fileName);
    void draw();
    double scanField(QLineEdit*);
    int getPointSize(std::vector<Point>);
    int getPolygonSize(Facade*, int);
    int getPolygon(Facade*, int, int);
    Point getPoint(Facade* facade, int ind);
    ~MainWindow();

protected slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

protected:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
