#include <iostream>
#include "imp.h"
using namespace std;


void print_array(short int arr[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        cout<<arr[i]<<" | ";
        }
    cout << endl << endl;
    return;
    }