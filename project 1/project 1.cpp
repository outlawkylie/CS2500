// project 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;

#include "sort.h"
#include "imp.h"

int main()
    {
    /* Variables */
    sortclass* sort = new sortclass;


    /* Preliminary Setup */
    srand( time(NULL) );

    /* Begin Main */
    auto start = chrono::high_resolution_clock::now();
    sort->insertion_sort();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout<<"The array was sorted in " << duration.count() << "ns."<<endl;


    return 0;
    }