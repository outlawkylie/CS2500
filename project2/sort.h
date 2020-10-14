// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Class definition for the implementation of the insertion sort algorithm


#ifndef SORT_H
#define SORT_H

#include <iostream>
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
        T size = 0;
        T * unsorted_array;


        // functions to set up array
        void array_to_bestcase( void ); 
        void array_to_worstcase( void ); 
        void array_to_random( void );
        void array_to_same( void ); 


        // sort functions
        long long insertion_sort( void );
        long long quick_sort( void ); 
        long long merge_sort( void );
        long long heap_sort( void );
        long long selection_sort( void );

        // supporting sort functions
        void max_heapify( T arr[], int size, int i ); 

    };

#include "sort.hpp"
#endif