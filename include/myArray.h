/*
 * author: Andrew Smith
 * file: myArray.h
 * date: 11/26/19, 9:30PM
 * description: template header for myArray class which contains function prototypes. the array is resizable
 *      and is overloaded to utilize most of the operators that a primitive array would. additionally, the
 *      array is template based. MUST USE MAKEFILE TO COMPILE!
 * 
 */

#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>

using namespace std;

template <class T>

class myArray
{
    /**
     * overloaded string insertion operator which echos the elements of the array onto the indicated ostream
     * @lhs ostream to be echoed onto
     * @rhs myArray<U> to be echoed
     */
    template <class U>
    friend ostream &operator<<(ostream &lhs, const myArray<U> &rhs)
    {
        for (int i = 0; i < rhs.getSize(); i++)
        {
            lhs << rhs[i] << " ";
        }
        return lhs;
    }
    /**
     * overloaded string extraction operator which prompts the user to enter the appropriate number of items into an array
     * @lhs istream to get input from
     * @rhs array to populate
     */
    template <class U>
    friend istream &operator>>(istream &lhs, myArray<U> &rhs)
    {
        U temp;
        lhs >> temp;
        rhs = rhs + temp;
        return lhs;
    }
public:
    myArray();
    myArray(int _size, T content = 0);
    myArray(int _size, T anArray[]);
    myArray(const myArray &);
    ~myArray();

    myArray<T> &operator++();
    myArray<T> operator++(int dummy);
    const myArray<T> operator-() const;
    const myArray<T> operator+(T);
    const myArray<T> operator+(const myArray<T> &) const;
    T &operator[](int index) const;
    const myArray<T> operator=(const myArray<T> &);
    bool operator==(myArray<T> &) const;
    bool operator!=(myArray<T> &) const;
    const int &getSize() const;

private:
    int size;
    T *data;
    void setSize(int);
};
//Because of extensive compilation issues and template
#include "../src/myArray.cpp"
#endif