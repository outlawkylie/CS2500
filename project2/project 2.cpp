// Author: Kylie Outlaw
// Date: 10/15/2020
// Purpose: Driver for the implementation of merge, 
//          quick, selection, insertion, heap sorts


#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>
#include <string.h>
#include <cstring>

#include "sort.h"
#include "imp.h"
using namespace std;

int main()
    {
    /****************************************
    *  Preliminary Setup
    *****************************************/
    srand( time( NULL ) );

    /****************************************
    *  Sort Random Trials
    *****************************************/
    // Merge Sorts
    run_test((int)NORMAL_CASE, (int)MERGESORT, (string)(NAME_NORMAL + "_" + NAME_MERGE + ".txt"));
    run_test((int)BEST_CASE, (int)MERGESORT, (string)(NAME_BEST + "_" + NAME_MERGE + ".txt"));
    run_test((int)WORST_CASE, (int)MERGESORT, (string)(NAME_WORST + "_" + NAME_MERGE + ".txt"));
    
    // Quick Sorts
    run_test((int)NORMAL_CASE, (int)QUICKSORT, (string)(NAME_NORMAL + "_" + NAME_QUICK + ".txt"));
    run_test((int)BEST_CASE, (int)QUICKSORT, (string)(NAME_BEST + "_" + NAME_QUICK + ".txt"));
    run_test((int)WORST_CASE, (int)QUICKSORT, (string)(NAME_WORST + "_" + NAME_QUICK + ".txt"));
    
    // Selection Sorts
    run_test((int)NORMAL_CASE, (int)SELECTIONSORT, (string)(NAME_NORMAL + "_" + NAME_SELECTION + ".txt"));
    run_test((int)BEST_CASE, (int)SELECTIONSORT, (string)(NAME_BEST + "_" + NAME_SELECTION + ".txt"));
    run_test((int)WORST_CASE, (int)SELECTIONSORT, (string)(NAME_WORST + "_" + NAME_SELECTION + ".txt"));

    // Heap Sort
    run_test((int)NORMAL_CASE, (int)HEAPSORT, (string)(NAME_NORMAL + "_" + NAME_HEAP + ".txt"));
    run_test((int)BEST_CASE, (int)HEAPSORT, (string)(NAME_BEST + "_" + NAME_HEAP + ".txt"));
    run_test((int)WORST_CASE, (int)HEAPSORT, (string)(NAME_WORST + "_" + NAME_HEAP + ".txt"));

    return 0;
    }