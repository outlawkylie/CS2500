// project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "project3.h"

int main()
    {
    ofstream out(OUT);
    out<<"Kylie Outlaw\nInput file:  "<<NET<<"\n\nInput:"<<endl;
    int arr[arrSZ][arrSZ] = {0};
    setup( NET, arr, out);
    print(arr);
    output(arr, out);
    }