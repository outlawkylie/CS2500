#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>
#include "imp.h"
#include "sort.h"
using namespace std;


void print_array(unsigned short int arr[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        cout<<arr[i]<<" | ";
        }
    cout << endl << endl;
    return;
    }

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