// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Sort class constructor and function definitions

#include "sort.h"
#include <iostream>
using namespace std;


/* Default Constructor */
template <typename T>
sortclass<T>::sortclass()
    {
    size = default_size;
    unsorted_array = new unsigned short int[ default_size ];
    for( int i = 0; i < default_size; i++ )
        {
        unsorted_array[ i ] = rand() % 10000;
        }
    }


/* Parameterized Constructor */
template <typename T>
sortclass<T>::sortclass( short int arr_size )
    {
    size = arr_size;
    unsorted_array = new unsigned short int[ arr_size ];
    for( int i = 0; i < arr_size; i++ )
        {
        unsorted_array[ i ] = rand() % 10000;
        }
    }


/******************************************************************
*   NAME: print_array()
*
*   DESCRIPTION: prints any array to terminal given the size
******************************************************************/
template <typename T>
void sortclass<T>::insertion_sort( void )
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


/******************************************************************
*   NAME: array_to_bestcase()
*
*   DESCRIPTION: adjusts all elements in unsorted_array to be
*                best case scenario
******************************************************************/
template <typename T>
void sortclass<T>::array_to_bestcase( void )
    {
    for( int i = 0; i < size; i++ )
        {
        unsorted_array[ i ] = i;
        }
    }


/******************************************************************
*   NAME: array_to_worstcase()
*
*   DESCRIPTION: adjusts all elements in unsorted_array to be
*                worst case scenario
******************************************************************/
template <typename T>
void sortclass<T>::array_to_worstcase( void )
    {
    for( int i = 0; i < size; i++ )
        {
        unsorted_array[ i ] = size-i;
        }
    }


/******************************************************************
*   NAME: array_to_bestcase()
*
*   DESCRIPTION: adjusts all elements in unsorted_array to be
*                random case scenario
******************************************************************/
template <typename T>
void sortclass<T>::array_to_random( void )
    {
    for( int i = 0; i < size; i++ )
        {
        unsorted_array[ i ] = rand() % 100;
        }
    }


/******************************************************************
*   NAME: array_to_same()
*
*   DESCRIPTION: adjusts all elements in unsorted_array to be same
******************************************************************/
template <typename T>
void sortclass<T>::array_to_same( void )
    {
    for (int i = 0; i < size; i++)
        {
        unsorted_array[i] = 1;
        }
    }