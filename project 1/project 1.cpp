// project 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>
using namespace std;

#include "sort.h"
#include "imp.h"

int main()
    {
    /****************************************
    *  Preliminary Setup
    *****************************************/
    srand( time( NULL ) );

    /****************************************
    *  Variables
    *****************************************/
    const short int NUM_TRIALS = 100;
    long long trial_duration = 0;


    /****************************************
    *  Sort Random Trials
    *****************************************/
    ofstream output( "output_random.txt" );
    for( int i = 0; i < NUM_TRIALS; i++ )
        {
        trial_duration = insertion_sort_normal();
        output << trial_duration << ", ";
        }
    output.close();

    /****************************************
    *  Sort Best Case Trials
    *****************************************/
    ofstream output2( "output_best.txt" );
    for( int i = 0; i < NUM_TRIALS; i++ )
        {
        trial_duration = insertion_sort_best();
        output2 << trial_duration << ", ";
        }
    output2.close();

    /****************************************
    *  Sort Worst Case Trials
    *****************************************/
    ofstream output3( "output_worst.txt" );
    for( int i = 0; i < NUM_TRIALS; i++ )
        {
        trial_duration = insertion_sort_worst();
        output3 << trial_duration << ", ";
        }
    output3.close();


    return 0;
    }