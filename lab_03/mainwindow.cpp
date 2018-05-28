#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    facade = new Facade;
    holst = new QGraphicsScene();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getPolygonSize(Facade* facade, int i)
{
    return(facade->figure->polygonsArray[i].polygonArray.size());
}

int MainWindow::getPointSize(std::vector<Point> point)
{
    return (point.size());
}

int MainWindow::getPolygon(Facade* facade, int i, int j)
{
    return (facade->figure->polygonsArray[i].polygonArray[j]);
}

Point MainWindow::getPoint(Facade* facade, int ind)
{
    return (facade->figure->pointsArray[ind]);
}

void MainWindow::draw()
{
    int pointSize = getPointSize(facade->figure->pointsArray);

    for(int i = 0; i < pointSize; i++)
    {
        int j = 0;
        int arraySize = getPolygonSize(facade,i);
        for(j = 0; j < (arraySize-1); j++)
        {
            size_t ind_1 = getPolygon(facade,i,j) - 1;
            size_t ind_2 = getPolygon(facade, i, j+1) - 1;
            holst->addLine(getPoint(facade,ind_1).x,
                           getPoint(facade,ind_1).y,
                           getPoint(facade,ind_2).x,
                           getPoint(facade,ind_2).y,
                           QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
         }
            size_t ind_1 = getPolygon(facade, i, 0) - 1;
            size_t ind_2 = getPolygon(facade, i, j) - 1;
            holst->addLine(getPoint(facade,ind_1).x,
                           getPoint(facade,ind_1).y,
                           getPoint(facade,ind_2).x,
                           getPoint(facade,ind_2).y,
                           QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
     }

    ui->graphicsView->setScene(holst);
}

void MainWindow::setFigure(char *fileName)
{
    facade->figure = facade->createFigureDirector.createFigure(facade->figureBuilder, fileName);
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/Users/ivanmorozov",
                                                    tr("Txt file(*.obj)"));

    ui->lineEdit->setText(fileName);

    setFigure(fileName.toLatin1().data());
    draw();

}

double MainWindow::scanField(QLineEdit *obj)
{
    QString input = obj->text();
    return input.toDouble();
}

void MainWindow::on_pushButton_2_clicked()
{
    double dx = scanField(ui->lineEdit_2);
    double dy = scanField(ui->lineEdit_3);
    double dz = scanField(ui->lineEdit_4);

    facade->moveFigure(dx, dy, dz);

    holst->clear();
    draw();
}

void MainWindow::on_pushButton_3_clicked()
{
    double dx = scanField(ui->lineEdit_5);
    double dy = scanField(ui->lineEdit_6);
    double dz = scanField(ui->lineEdit_7);

    facade->rotateFigure(dx, dy, dz);
    holst->clear();
    draw();
}

void MainWindow::on_pushButton_4_clicked()
{
    double dx = scanField(ui->lineEdit_8);
    double dy = scanField(ui->lineEdit_9);
    double dz = scanField(ui->lineEdit_10);

    facade->scaleFigure(dx, dy, dz);
    holst->clear();
    draw();
}
