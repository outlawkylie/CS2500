// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Driver for the implementation of the insertion sort algorithm


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
    run_test((int)NORMAL_CASE, (int)HEAPSORT, (string)(NAME_NORMAL+"_"+NAME_HEAP+".txt"));
    run_test((int)NORMAL_CASE, (int)SELECTIONSORT, (string)(NAME_NORMAL + "_" + NAME_SELECTION + ".txt"));



    return 0;
    }