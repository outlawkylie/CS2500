// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Class definition for the implementation of the insertion sort algorithm


#ifndef SORT_H
#define SORT_H
#include <iostream>
using namespace std;

/******************************************************************
*   CONSTANTS
******************************************************************/
const short int ARRAY_SIZE = 10;

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
        T default_size = ARRAY_SIZE;
        T size = 0;
        T * unsorted_array;


        // functions to set up array
        void array_to_bestcase( void ); 
        void array_to_worstcase( void ); 
        void array_to_random( void );
        void array_to_same( void ); 


        // sort functions
        void insertion_sort( void );

    };

#endif