// project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

static const int NUM_RELEVANT_CLASSES = 7;
class trial{
public: 
    int * table;
    };

int main()
{
    cout << "Hello World!\n";
    trial x;
    x.table = new int[NUM_RELEVANT_CLASSES] { 3,
                4,
                5 };
    cout << x.table[ 0 ] << x.table[ 1 ] << x.table[ 3 ];
}