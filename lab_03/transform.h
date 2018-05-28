#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>
#include <cmath>

#include "figure.h"

class Transform
{
public:
    static const int N;
    static const double PI;
    static const double IN_DEGREES;

    double** allocateMatrixRows(int, int);
    void setZeroResult(int, int, double**&);
    void deleteMatrixRows(int, double**&);
    void multiply(int, int, double**, int, double**, double**&);
    double** setXRotateMatrix(double);
    double** setYRotateMatrix(double);
    double** setZRotateMatrix(double);
    void rotateFigure(Figure* fig, double x_angle, double y_angle, double z_angle);
    void moveFigure(Figure* fig, double dx, double dy, double dz);
    double** setScaleMatrix(double, double, double);
    void scaleFigure(Figure* fig, double x, double y, double z);
};

#endif // TRANSFORM_H
