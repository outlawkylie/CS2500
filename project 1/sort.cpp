#include "sort.h"
#include <iostream>
using namespace std;

sortclass::sortclass()
    {
    size = default_size;
    unsorted_array = new unsigned short int[ default_size ];
    for( int i = 0; i < default_size; i++ )
        {
        unsorted_array[ i ] = rand() % 10000;
        }
    }

sortclass::sortclass( short int arr_size )
    {
    size = arr_size;
    unsorted_array = new unsigned short int[ arr_size ];
    for( int i = 0; i < arr_size; i++ )
        {
        unsorted_array[ i ] = rand() % 10000;
        }
    }


void sortclass::insertion_sort( void )
    {
    for( int i = 1; i<size; i++ )
        {
        short int key = unsorted_array[ i ];
        int j = i;
        while( j > 0 && ( unsorted_array[j - 1] > key ) )
            {
            unsorted_array[j] = unsorted_array[j - 1];
            j = j - 1; 
            }
        unsorted_array[ j ] = key;
        }
    return;
    }

void sortclass::array_to_bestcase( void )
    {
    for( int i = 0; i < size; i++ )
        {
        unsorted_array[ i ] = i;
        }
    }

void sortclass::array_to_worstcase( void )
    {
    for( int i = 0; i < size; i++ )
        {
        unsorted_array[ i ] = size-i;
        }
    }

void sortclass::array_to_random( void )
    {
    for( int i = 0; i < size; i++ )
        {
        unsorted_array[ i ] = rand() % 100;
        }
    }