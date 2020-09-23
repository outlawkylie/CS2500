#ifndef SORT_H
#define SORT_H

/* Defines */
#include <iostream>
using namespace std;

/* Constants */
const short int ARRAY_SIZE = 10000;

/* Class Declarations */
class sortclass
    {
    public:
        // constructor 
        sortclass();

        // variables
        short int size = ARRAY_SIZE;
        unsigned short int unsorted_array[ ARRAY_SIZE ];


        // functions
        void array_to_bestcase( void ); 
        void array_to_worstcase( void ); 
        void array_to_random( void );

        // sort functions
        void insertion_sort( void );

    };

#endif