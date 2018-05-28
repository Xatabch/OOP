#include "transform.h"

const int Transform::N = 3;
const double Transform::PI = 3.14159265;
const double Transform::IN_DEGREES = PI/180;

double** Transform::allocateMatrixRows(int n, int m)
{
    double **data = new double*[n];
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++){
        data[i] = new double[m];
    }

    setZeroResult(n, m, data);

    return data;
}
void Transform::setZeroResult(int n, int m, double **&data)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            data[i][j] = 0;
        }
    }
}

void Transform::deleteMatrixRows(int n, double **&data)
{
    for (int i = 0; i < n; i++){
        delete data[i];
    }

    delete data;
}

void Transform::multiply(int n1, int m1, double **a, int m2, double **b, double **&result)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < m1; k++)
            {
                result[i][j] += (a[i][k]) * (b[k][j]);
            }
        }
    }
}

void Transform::moveFigure(Figure* fig, double dx, double dy, double dz)
{

    for (auto &&item : fig->pointsArray)
    {
        item.x += dx;
        item.y += dy;
        item.z += dz;
    }
}

double** Transform::setScaleMatrix(double x, double y, double z)
{
    double **data = new double*[N];
    if (!data)
        return NULL;

    for (int i = 0; i < N; i++){
        data[i] = new double[N];
        for (int j = 0 ; j < N; j++){
            data[i][j] = 0;
        }
    }

    data[0][0] = x;
    data[1][1] = y;
    data[2][2] = z;

    return data;
}

void Transform::scaleFigure(Figure* fig, double x, double y, double z)
{

    int tmpN = 1, tmpM = 3;
    double **tmpDot = allocateMatrixRows(tmpN, tmpM);
    double **tmpResult = allocateMatrixRows(tmpN, tmpM);
    double **scaleMatrix = setScaleMatrix(x,y,z);

    for (auto &&item : fig->pointsArray){
        // перепишем координаты из структуры в массив для дальнейшего перемножения
        tmpDot[0][0] = item.x;
        tmpDot[0][1] = item.y;
        tmpDot[0][2] = item.z;

        multiply(tmpN, tmpM, tmpDot, N, scaleMatrix, tmpResult);

        // переписываем получившиеся новые координаты точки обратно в структуру
        item.x = tmpResult[0][0];
        item.y = tmpResult[0][1];
        item.z = tmpResult[0][2];
        setZeroResult(tmpN, tmpM, tmpResult); // чтобы tmpResult не накапливал в себе результаты прошлого умножения
    }

    deleteMatrixRows(tmpN, tmpDot);
    deleteMatrixRows(tmpN, tmpResult);
    deleteMatrixRows(N, scaleMatrix);
}

double** Transform::setXRotateMatrix(double x_angle)
{
    double **data = allocateMatrixRows(N,N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            data[i][j] = 0;
        }
    }
    data[0][0] = 1;
    data[1][1] = cos(x_angle * IN_DEGREES);
    data[1][2] = -1 * sin(x_angle * IN_DEGREES);
    data[2][1] = sin(x_angle * IN_DEGREES);
    data[2][2] = cos(x_angle * IN_DEGREES);

    return data;
}

double** Transform::setYRotateMatrix(double y_angle)
{
    double **data = allocateMatrixRows(N,N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            data[i][j] = 0;
        }
    }
    data[1][1] = 1;
    data[0][0] = cos(y_angle * IN_DEGREES);
    data[0][2] = sin(y_angle * IN_DEGREES);
    data[2][0] = -1 * sin(y_angle * IN_DEGREES);
    data[2][2] = cos(y_angle * IN_DEGREES);

    return data;
}

double** Transform::setZRotateMatrix(double z_angle)
{
    double **data = allocateMatrixRows(N,N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            data[i][j] = 0;
        }
    }
    data[2][2] = 1;
    data[0][0] = cos(z_angle * IN_DEGREES);
    data[0][1] = -1 * sin(z_angle * IN_DEGREES);
    data[1][0] = sin(z_angle * IN_DEGREES);
    data[1][1] = cos(z_angle * IN_DEGREES);

    return data;
}

void Transform::rotateFigure(Figure* fig, double x_angle, double y_angle, double z_angle)
{

    int tmpN = 1, tmpM = 3;
    double **tmpDot = allocateMatrixRows(tmpN, tmpM);
    double **tmpResult = allocateMatrixRows(tmpN, tmpM);

    // хранение результатов перемножения матриц
    double **y_x_result = allocateMatrixRows(N, N);
    double **z_y_x_result = allocateMatrixRows(N, N); // результат умножения 3-х матриц

    // получаем матрицы поворота вокруг каждой из осей
    double **x_rotate_matrix = setXRotateMatrix(x_angle);
    double **y_rotate_matrix = setYRotateMatrix(y_angle);
    double **z_rotate_matrix = setZRotateMatrix(z_angle);

    // итоговая матрица поворота = z_rotat_matrix * (y_rotate_matrix * x_rotate_matrix)
    multiply(N, N, y_rotate_matrix, N, x_rotate_matrix, y_x_result);
    multiply(N, N, z_rotate_matrix, N, y_x_result, z_y_x_result);

    // умножаем координаты каждой точки на матрицу поворота z_y_x_result
    for (auto &&item : fig->pointsArray){
        // перепишем координаты из структуры в массив для дальнейшего перемножения
        tmpDot[0][0] = item.x;
        tmpDot[0][1] = item.y;
        tmpDot[0][2] = item.z;

        multiply(tmpN, tmpM, tmpDot, N, z_y_x_result, tmpResult);

        // переписываем получившиеся новые координаты точки обратно в структуру
        item.x = tmpResult[0][0];
        item.y = tmpResult[0][1];
        item.z = tmpResult[0][2];

        setZeroResult(tmpN, tmpM, tmpResult); // чтобы tmpResult не накапливал в себе результаты прошлого умножения
    }

    deleteMatrixRows(tmpN, tmpDot);
    deleteMatrixRows(tmpN, tmpResult);
    deleteMatrixRows(N, y_x_result);
    deleteMatrixRows(N, z_y_x_result);
    deleteMatrixRows(N, x_rotate_matrix);
    deleteMatrixRows(N, y_rotate_matrix);
    deleteMatrixRows(N, z_rotate_matrix);
}


