// project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "project3.h"

int main()
    {
    int arr[arrSZ][arrSZ] = { 0 };   /* create adjacency matrix */
    int r_arr[arrSZ][arrSZ] = { 0 }; /* create resudial matrix  */
    int max_flow = 0;
    ofstream out(OUT);


    out<<"Kylie Outlaw\nInput file:  "<<NET<<"\n\nInput:"<<endl;
    setup( NET, arr, out);
    print(arr);
    max_flow = FF(arr, r_arr);
    output(arr, r_arr, out);
    out<<"Max flow in this network is "<<max_flow;
    }