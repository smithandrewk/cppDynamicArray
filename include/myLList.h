/*
 * file: myLList.h
 * author: Andrew Smith
 * 
 * header file for myLList
 */
#ifndef MYLLIST_H
#define MYLLIST_H

#include <cstdlib>
#include "Datum.h"

using namespace std;
class myLList
{
public:
    myLList();
    myLList(int, float *anArray);
    myLList(const myLList &);
    ~myLList();
    const myLList operator+(const myLList &) const;
    const myLList operator=(const myLList &);
    const Datum operator[](int) const;
    bool operator==(const myLList &) const;
    void add(float aData);
    void insert(float, int);
    void remove(int index);
    void print() const;
    Datum *find(float aData);
    Datum *getHead() const;
    Datum *getTail() const;
    int getSize() const;
    void setHead(Datum *);
    void setTail(Datum *);
    void setSize(int);

private:
    Datum *head;
    Datum *tail;
    int size;
};

#endif // MYLLIST_H