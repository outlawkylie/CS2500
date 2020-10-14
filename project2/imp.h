// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Function declarations to support insertion sort program


#ifndef IMP_H
#define IMP_H
#include <string.h>


/******************************************************************
*   TYPES
******************************************************************/
enum TEST_CASE_TYPE
    {
    BEST_CASE,
    NORMAL_CASE,
    WORST_CASE,
    SAME_CASE
    };

/******************************************************************
*   CONSTANTS
******************************************************************/
const string NAME_BEST      = "BESTCASE";
const string NAME_NORMAL    = "NORMALCASE";
const string NAME_WORST     = "WORSTCASE";

const string NAME_MERGE     = "MERGESORT";
const string NAME_QUICK     = "QUICKSORT";
const string NAME_HEAP      = "HEAPSORT";
const string NAME_SELECTION = "SELECTIONSORT";

const short int NUM_TRIALS  = 10;
const short int N_SKIP      = 50;
const short int N_MAX       = 500;


/******************************************************************
*   METHODS
******************************************************************/
template <typename T>
void print_array( T arr[], int size ); //Print the array

#endif