/*
 * file: myArray.cpp
 * author: Andrew Smith
 * date: 11/26/19, 9:30PM
 * description: this file is the implmentation file for the myArray class with the function definitions
 */
#include <iostream>
#include "../include/myArray.h"

using namespace std;

/**
 * default constructor sets size of array to 0 and data to NULL
 */
template <class T>
myArray<T>::myArray() : size(0), data(NULL)
{
    // cout << "myArray.cpp::myArray()" << endl;
}
/**
 * alternate constructor that accepts a size and value, where default value is 0
 * @_size size of array to set
 * @content content to set every element equal to
 */
template <class T>
myArray<T>::myArray(int _size, T content)
{
    setSize(_size);
    data = new T[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = content;
        *(data + i) = content;
    }
}
/**
 * alternate constructor that takes a primitive array to initialize a myArray object
 * @_size size of array to set
 * @anArray array to set myArray equal to the contents of
 */
template <class T>
myArray<T>::myArray(int _size, T anArray[])
{
    setSize(_size);
    data = new T[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = anArray[i];
        *(data + i) = *(anArray + i);
    }
}
/**
 * copy constructor
 * @rhs array to copy
 */
template <class T>
myArray<T>::myArray(const myArray &rhs)
{
    setSize(rhs.getSize());
    data = new T[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = rhs.data[i];
    }
}
/**
 * destructor
 */
template <class T>
myArray<T>::~myArray()
{
    // cout << "myArray.cpp::~myArray()" << endl;
    delete[] data;
}
/**
 * overloaded prefix operator, increments all array entries by 1
 */
template <class T>
myArray<T> &myArray<T>::operator++()
{
    for (int i = 0; i < this->getSize(); i++)
    {
        ++data[i];
    }
    return *this;
}
/**
 * overloaded postfix operator, increments all array entries by 1
 * @dummy dummy value to distinguish from prefix operator
 */
template <class T>
myArray<T> myArray<T>::operator++(int dummy)
{
    myArray<T> ret(*this);
    ++(*this);
    return ret;
}
/**
 * overloaded negation operator negates the sign of all array elements
 */
template <class T>
const myArray<T> myArray<T>::operator-() const
{
    myArray<T> temp(*this);
    for (int i = 0; i < this->getSize(); i++)
    {
        temp.data[i] *= -1;
    }
    return temp;
}
/**
 * overloaded addition operator adds a single number to the end of the array
 * @value number to add to the end of the array
 */
template <class T>
const myArray<T> myArray<T>::operator+(T value)
{
    myArray<T> temp(size + 1);

    for (int i = 0; i < size; i++)
    {
        temp.data[i] = data[i];
    }
    temp.data[size] = value;

    return temp;
}
/**
 * overloaded addition operator concatenates two arrays
 * @rhs array to concatenate to this
 */
template <class T>
const myArray<T> myArray<T>::operator+(const myArray<T> &rhs) const
{
    myArray<T> temp(size + rhs.getSize());

    for (int i = 0; i < size; i++)
    {
        temp.data[i] = data[i];
    }
    for (int i = 0; i < rhs.size; i++)
    {
        temp.data[size + i] = rhs[i];
    }

    return temp;
}
/**
 * overlaoded array square brackets allow access to the given index in a myArray object
 * @index index of array to access
 */
template <class T>
T &myArray<T>::operator[](int index) const
{
    return data[index];
}
/**
 * overloaded assignment operator is cascadable and secure
 * @rhs array to assign this to
 */
template <class T>
const myArray<T> myArray<T>::operator=(const myArray<T> &rhs)
{
    setSize(rhs.getSize());
    delete[] data;
    data = new T[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = rhs.data[i];
    }
    return *this;
}
/**
 * overloaded equality operator returns a bool based on size and content
 * @rhs array to be evaluated against this
 */
template <class T>
bool myArray<T>::operator==(myArray<T> &rhs) const
{
    bool returnValue = true;

    if (size != rhs.size)
    {
        returnValue = false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] != rhs.data[i])
            {
                returnValue = false;
            }
        }
    }
    return returnValue;
}
/**
 * overloaded negation operator returns a bool based on size and content
 * @rhs array to be evaluated against this
 */
template <class T>
bool myArray<T>::operator!=(myArray<T> &rhs) const
{
    if (*this == rhs)
    {
        return false;
    }
    else
    {
        return true;
    }
}
/**
 * to get size of an array
 */
template <class T>
const int& myArray<T>::getSize() const
{
    return size;
}
/* Private Members */
/**
 * to set size from constructors of myArray objects
 * @_size size of array to set
 */
template <class T>
void myArray<T>::setSize(int _size)
{
    if (_size >= 0)
    {
        size = _size;
    }
    else
    {
        //Do something here.
    }
}

// template class myArray<float>;
