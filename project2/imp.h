// Author: Kylie Outlaw
// Date: 10/15/2020
// Purpose: Function declarations to support insertion sort program


#ifndef IMP_H
#define IMP_H

#include <iostream>
#include <string.h>
using namespace std;


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

enum SORT_TYPE
    {
    INSERTIONSORT,
    QUICKSORT,
    MERGESORT,
    HEAPSORT,
    SELECTIONSORT
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
const string NAME_INSERTION = "INSERTIONSORT";

const short int NUM_TRIALS  = 1000;
const short int N_SKIP      = 1;
const short int N_MAX       = 200;

void run_test(int type, int sort, const string name);


/******************************************************************
*   METHODS
******************************************************************/
template <typename T>
void print_array( T arr[], int size ); //Print the array


#endif