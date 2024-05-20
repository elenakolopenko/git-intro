#ifndef TWODARRAY_HPP_
#define TWODARRAY_HPP_
#include <iostream>

template <typename T> class TwoDimensionalArray;
template <typename T> std::ostream &operator<<(std::ostream &os, const TwoDimensionalArray<T> &twodarray);
template <typename T> std::istream &operator>>(std::istream &is, TwoDimensionalArray<T> &twodarray);

template <typename T = int>
class TwoDimensionalArray
{
private:
    T **data;
    int rows;
    int cols;

public:
    TwoDimensionalArray(const int rows = 3, const int cols = 3);
    TwoDimensionalArray(const TwoDimensionalArray<T> &twodarray);
    ~TwoDimensionalArray();

    TwoDimensionalArray &operator=(const TwoDimensionalArray<T> &twodarray);

    friend std::ostream &operator<< <>(std::ostream &os, const TwoDimensionalArray<T> &twodarray);
    friend std::istream &operator>> <>(std::istream &is, TwoDimensionalArray<T> &twodarray);
};

template <typename T>
TwoDimensionalArray<T>::TwoDimensionalArray(const int rows, const int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->data = new T *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->data[i] = new T[this->cols];
    }
}

template <typename T>
TwoDimensionalArray<T>::TwoDimensionalArray(const TwoDimensionalArray<T> &twodarray)
{
    this->rows = twodarray.rows;
    this->cols = twodarray.cols;
    this->data = new T *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->data[i] = new T[this->cols];
        for (int j = 0; j < this->cols; j++)
        {
            this->data[i][j] = twodarray.data[i][j];
        }
    }
}

template <typename T>
TwoDimensionalArray<T>::~TwoDimensionalArray()
{
    for (int i = 0; i < this->rows; i++)
    {
        delete[] this->data[i];
    }
    delete[] this->data;
    std::cout << "!\n";
}

template <typename T>
TwoDimensionalArray<T> &TwoDimensionalArray<T>::operator=(const TwoDimensionalArray<T> &twodarray)
{
    if (this == &twodarray)
    {
        return *this;
    }
    for (int i = 0; i < this->rows; i++)
    {
        delete[] this->data[i];
    }
    delete[] this->data;
    this->rows = twodarray.rows;
    this->cols = twodarray.cols;
    this->data = new T *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->data[i] = new T[this->cols];
        for (int j = 0; j < this->cols; j++)
        {
            this->data[i][j] = twodarray.data[i][j];
        }
    }
    return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const TwoDimensionalArray<T> &twodarray)
{
    for (int i = 0; i < twodarray.rows; i++)
    {
        for (int j = 0; j < twodarray.cols; j++)
        {
            os << twodarray.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, TwoDimensionalArray<T> &twodarray)
{
    for (int i = 0; i < twodarray.rows; i++)
    {
        for (int j = 0; j < twodarray.cols; j++)
        {
            is >> twodarray.data[i][j];
        }
    }
    return is;
}

#endif
