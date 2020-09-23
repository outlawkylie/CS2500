#ifndef SORT_H
#define SORT_H

/* Defines */
#include <iostream>
using namespace std;

/* Constants */
const short int ARRAY_SIZE = 100;

/* Class Declarations */
class sortclass
    {
    public:
        // constructor 
        sortclass();
        sortclass( short int arr_size );

        // variables
        short int default_size = ARRAY_SIZE;
        short int size = 0;
        unsigned short int * unsorted_array;


        // functions
        void array_to_bestcase( void ); 
        void array_to_worstcase( void ); 
        void array_to_random( void );

        // sort functions
        void insertion_sort( void );

    };

#endif