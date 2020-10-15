// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Class definition for the implementation of the insertion sort algorithm


#ifndef SORT_H
#define SORT_H


#include <iostream>
#include <cassert>
using namespace std;


/******************************************************************
*   CLASSES
******************************************************************/
template <typename T>
class sortclass
    {
    public:
        // constructor 
        sortclass();
        sortclass( short int arr_size );

        // variables
        int size = 0;
        T * unsorted_array;


        // functions to set up array
        void array_to_bestcase( void ); 
        void array_to_worstcase( void ); 
        void array_to_random( void );
        void array_to_same( void ); 


        // sort functions
        void insertion_sort( void );
        void quick_sort( int low, int high ); 
        void merge_sort( int low, int high );
        void heap_sort( void );
        void selection_sort( void );

        // supporting sort functions
        void swap(int x, int y); 
        void max_heapify(T arr[], int size, int i); 
        int quick_sort_partition(int low, int high);
        void merge(const int p, const int q, const int r);

    };

#include "sort.hpp"
#endif