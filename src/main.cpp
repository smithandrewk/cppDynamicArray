/*
 * file: main.cpp
 * author: Andrew Smith
 * 
 * main method for 
 */
#include <iostream>
#include "../include/myArray.h"
using namespace std;

int main(int argc, char const *argv[])
{   
    cout << "main.cpp::main" << endl;
    cout << "argc: " << argc << endl;
    for(int i=0;i<argc;i++)
        cout << *(argv + i) << " ";
    cout << endl;

    myArray<int> a;
    a.PrintSize();
    a.Print();
    
    myArray<int> b(10);
    b.PrintSize();
    b.Print();

    myArray<int> c(5, 10);
    c.PrintSize();
    c.Print();

    int arr[] = {5,3,5};
    
    //Intended use works; what if size if less than or greater than?
    myArray<int> d(3, arr);
    d.PrintSize();
    d.Print();

    myArray<int> e(a);
    e.PrintSize();
    e.Print();

    a+=1;
    a.PrintSize();
    a.Print();

    a+=b;
    a.PrintSize();
    a.Print();

    (a+d).Print();

    a=d=e;
    a.PrintSize();
    a.Print();

    //Can't do a==(b+d);


    cout << a.getSize() << endl;
    
}
