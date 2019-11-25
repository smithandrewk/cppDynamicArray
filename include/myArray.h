/*
 * file: myArray.h
 * author: Andrew Smith
 * 
 * src file for myArray
 */

//TODO overload cout
//TODO adjust constant qualifiers
#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>

using namespace std;

//#1
template <class T>
//#2
class myArray
{
public:
    myArray();
    myArray(int _size);
    myArray(int _size, T content);
    myArray(int _size, T anArray[]);
    myArray(const myArray &);
    ~myArray();

    void Print() const;
    void operator+=(T);
    void operator+=(myArray<T> &);
    const myArray<T> operator+(const myArray<T> &) const;
    // const myArray<T> operator-() const;
    // myArray<T> operator++();
    // myArray<T> operator++(int);
    //TODO needs to work on both sides of assignment operator
    //?Return reference?
    // const T operator[](int) const;
    // friend ostream & operator<<(ostream &, const myArray<T> &);
    // friend istream & operator>>(istream &, myArray<T> &);
    bool operator==(myArray<T> &) const;
    bool operator!=(myArray<T> &) const;
    const myArray<T> operator=(const myArray<T> &);

    void PrintSize() const;
    const int& getSize() const;
    const T& getData(int) const;

private:
    int size;
    T *data;
    void setSize(int);
};

/* Public Members */
//#3
template <class T>
myArray<T>::myArray() : size(0), data(NULL)
{
    cout << "myArray.cpp::myArray()" << endl;
}
//?Remove this constructor to solve default value issue in next constructor
template <class T>
myArray<T>::myArray(int _size)
{
    setSize(_size);
    data = new T[size];

    for (int i = 0; i < getSize(); i++)
    {
        data[i] = 0;
        *(data + i) = 0;
    }
}
//?How to accept default value for a template
//#4
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
//#5
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
//#6
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
template <class T>
myArray<T>::~myArray()
{
    cout << "myArray.cpp::~myArray()" << endl;
    delete[] data;
}
template <class T>
void myArray<T>::Print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
template <class T>
void myArray<T>::operator+=(T value)
{
    T *temp = new T[size + 1]; //Make a temporary space

    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i]; //Move data to temp
    }
    temp[size] = value; //This is the last element of the temp array that is one longer than data.

    delete[] data; //Release the block that was reserved for data (not needed anymore).
    size++;       //Increase size by 1.
    data = temp;   //Point the current data pointer to what temp is pointing to.
}
//#10
//!...ALMOST: need to change to operator + and disallow self-modification
template <class T>
void myArray<T>::operator+=(myArray<T> &rhs)
{
    T *temp = new T[size + rhs.size];

    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    for (int i = 0; i < rhs.size; i++)
    {
        temp[size + i] = rhs.getData(i);
    }
    delete[] data;
    size += rhs.size;
    data = temp;
}
//#11
//*Attempted to return const myArray<T>& and recieved compilation error
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
        temp.data[size + i] = rhs.getData(i);
    }

    return temp;
}
//#7
//?What would returning const myArray<T>& change?
//*Possibly just have to return this
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
//#8
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
//#9
template <class T>
bool myArray<T>::operator!=(myArray<T> &rhs) const{
    //? should be *this or this?
    if(*this==rhs){
        return false;
    } else {
        return true;
    }
}

template <class T>
void myArray<T>::PrintSize() const
{
    cout << "size: " << size << endl;
}
template <class T>
const int& myArray<T>::getSize() const
{
    return size;
}
template <class T>
const T& myArray<T>::getData(int index) const
{
    //TODO Check for index validity
    return (data[index]);
}
/* Private Members */
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


#endif