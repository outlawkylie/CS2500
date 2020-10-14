// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Function definitions to support the insertion sort program


#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>
#include "imp.h"
#include "sort.h"
using namespace std;

/******************************************************************
*   NAME: print_array()
*
*   DESCRIPTION: prints any array to terminal given the size
******************************************************************/
void print_array(unsigned short int arr[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        cout<<arr[i]<<" | ";
        }
    cout << endl << endl;
    return;
    }


/******************************************************************
*   NAME: insertion_sort_normal()
*
*   DESCRIPTION: runs the insertion sort program on a random array
*                and returns time taken to sort in ns
******************************************************************/
long long insertion_sort_normal( short int size )
    {
    sortclass* sort = new sortclass( size ); 
    auto start = chrono::high_resolution_clock::now();
    sort->insertion_sort();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    delete sort;
    return duration.count();
    }

/******************************************************************
*   NAME: insertion_sort_best()
*
*   DESCRIPTION: runs the insertion sort program on a best case 
*                array and returns time taken to sort in ns
******************************************************************/
long long insertion_sort_best( short int size )
    {
    sortclass* sort = new sortclass( size );
    sort->array_to_bestcase();
    auto start = chrono::high_resolution_clock::now();
    sort->insertion_sort();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    delete sort;
    return duration.count();
    }


/******************************************************************
*   NAME:
*
*   DESCRIPTION: runs the insertion sort program on a worst case
*                array and returns time taken to sort in ns
******************************************************************/
long long insertion_sort_worst( short int size )
    {
    sortclass* sort = new sortclass( size );
    sort->array_to_worstcase();
    auto start = chrono::high_resolution_clock::now();
    sort->insertion_sort();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    delete sort;
    return duration.count();
    }