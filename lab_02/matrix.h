#ifndef matrix_h
#define matrix_h

#include <memory>
#include <stdexcept>
#include <iostream>

template<typename T>
class Matrix
{
public:

    Matrix(size_t r, size_t c);

    Matrix(const Matrix &);

    Matrix(Matrix &&);

    Matrix(size_t r, size_t c, T);

    Matrix(size_t r, size_t c, T **);

    Matrix &operator =(const Matrix &);

    std::unique_ptr<T[]> &operator[](size_t);

    const Matrix operator +(const Matrix &) const;

    Matrix &operator +=(const Matrix &);

    Matrix operator -(const Matrix &) const;

    Matrix &operator -=(const Matrix &);

    Matrix operator *(const Matrix &) const;

    Matrix operator *(T ) const;

    Matrix &operator *=(T );

    void enterMatrix();

    void setMatrix(T *);

    template <typename Type>
    friend std::ostream &operator <<(std::ostream &, const Matrix<Type> &);

private:

    std::unique_ptr<std::unique_ptr<T[]>[]> matrix;
    size_t rows;
    size_t columns;
};


template<typename T>
Matrix<T>::Matrix(size_t r, size_t c):matrix(new std::unique_ptr<T[]>[r]), rows(r), columns(c)
{
    for(size_t i = 0; i < rows; i++)
        matrix[i].reset(new T[columns]);

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            matrix[i][j] = 0;
    }
}


template<typename T>
Matrix<T>::Matrix(const Matrix &mt):matrix(new std::unique_ptr<T[]>[mt.rows]), rows(mt.rows), columns(mt.columns)
{
    for(size_t i = 0; i < rows; i++)
        matrix[i] = std::move(mt.matrix[i]);
}


template<typename T>
Matrix<T>::Matrix(Matrix &&mt):matrix(std::move(mt.matrix)), rows(mt.rows), columns(mt.columns)
{}


template<typename T>
Matrix<T>::Matrix(size_t r, size_t c, T data):matrix(new std::unique_ptr<T[]>[r]), rows(r), columns(c)
{
    for(size_t i = 0; i < rows; i++)
        matrix[i].reset(new T[columns]);

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            matrix[i][j] = data;
    }
}


template<typename T>
Matrix<T>::Matrix(size_t r, size_t c, T **data):matrix(new std::unique_ptr<T[]>[r]), rows(r), columns(c)
{
    for(size_t i = 0; i < rows; i++)
        matrix[i].reset(new T[columns]);

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            matrix[i][j] = data[i][j];
    }

}


template<typename T>
Matrix<T> &Matrix<T>::operator =(const Matrix &rhs)
{
    if(this != &rhs)
    {
        if(rows != rhs.rows || columns != rhs.columns)
            throw std::invalid_argument("Argument's size is incorrect");

        for(size_t i = 0; i < rows; i++)
        {
            for(size_t j = 0; j < columns; j++)
            {
                matrix[i][j] = rhs.matrix[i][j];
            }
        }
    }

    return *this;
}


template<typename T>
Matrix<T> const Matrix<T>::operator +(const Matrix &rhs) const
{
    Matrix<T> result(rows,columns);

    if(rows != rhs.rows || columns != rhs.columns)
        throw std::invalid_argument("Term's size if incorrect to add");

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
    }

    return result;
}


template<typename T>
Matrix<T> &Matrix<T>::operator +=(const Matrix &rhs)
{
    if(rows != rhs.rows || columns != rhs.columns)
        throw std::invalid_argument("Invalid argument");

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            matrix[i][j] += rhs.matrix[i][j];
    }

    return *this;
}


template<typename T>
Matrix<T> Matrix<T>::operator -(const Matrix &rhs) const
{
    Matrix<T> result(rows, columns);

    if(rows != result.rows || columns != result.columns)
        throw std::invalid_argument("Invalid argument");

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            result.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
    }

    return result;
}


template<typename T>
Matrix<T> &Matrix<T>::operator -=(const Matrix &rhs)
{
    if(rows != rhs.rows || columns != rhs.columns)
        throw std::invalid_argument("Invalid argument");

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            matrix[i][j] -= rhs.matrix[i][j];
    }

    return *this;
}


template<typename T>
Matrix<T> Matrix<T>::operator *(const Matrix &rhs) const
{

    Matrix<T> result(rows,rhs.columns);

    if(columns != rhs.rows)
        throw std::invalid_argument("Invalid argument");

    for(size_t i = 0; i < rows; i++)
    {
       for(size_t j = 0; j < rhs.columns; j++)
       {
         result.matrix[i][j] = 0;
         for(size_t k = 0; k < columns; k++)
           result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
       }
    }


    return result;
}


template<typename T>
Matrix<T> Matrix<T>::operator *(T rhs) const
{
    Matrix<T> result(rows, columns);

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            result.matrix[i][j] = matrix[i][j] * rhs;
    }

    return result;

}


template<typename T>
Matrix<T> &Matrix<T>::operator *=(T rhs)
{
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
            matrix[i][j] *= rhs;
    }

    return *this;
}


template <typename Type>
std::ostream &operator <<(std::ostream &stream, const Matrix<Type> &matrix)
{
    for(size_t i = 0, j = 0; i < matrix.rows; ++i)
    {
        for(j = 0; j < matrix.columns; ++j)
            stream << matrix.matrix[i][j] << ' ';
        stream << std::endl;
    }

    return stream;
}


template<typename T>
std::unique_ptr<T[]> &Matrix<T>::operator[](size_t index)
{
    if(index < 0 || index >= rows || index >= columns)
        throw std::range_error("Index error\n");

    return matrix[index];
}


template<typename T>
void Matrix<T>::enterMatrix()
{
    for(size_t i = 0; i < rows; i++)
        for(size_t j = 0; j < columns; j++)
            std::cin >> matrix[i][j];
}

template<typename T>
void Matrix<T>::setMatrix(T *data)
{
    for(size_t i = 0; i < rows; i++)
        for(size_t j = 0; j < columns; j++)
            matrix[i][j] = *(data + i*columns + j);
}

#endif // matrix_h
