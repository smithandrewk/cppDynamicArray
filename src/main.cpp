/*
 * file: main.cpp
 * author: Andrew Smith
 * date: 11/26/19, 9:30PM
 * description: main
 */
#include <iostream>
#include "../include/myArray.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "main" << endl;
    myArray<int> a(2,10);
    a=a+1;
    cout << a << endl;
    cout << a[2] << endl;
    cin >> a;
    cout << a << endl;
    myArray<int> b(3,5);
    myArray<int> c,d;
    d=c = a+b;
    cout << c << endl;
    cout << d << endl;
}
