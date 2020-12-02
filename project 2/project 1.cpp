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
    const short int NUM_TRIALS     = 100;
    const short int N_SKIP         = 500;
    const short int N_MAX          = 10000;
    long long       trial_duration = 0;


    /****************************************
    *  Sort Random Trials
    *****************************************/
    ofstream output( "output_random.txt" );
    for( short int i = N_SKIP; i <= N_MAX; i+= N_SKIP )
        {
        output << i << ", ";
        for( int j = 0; j < NUM_TRIALS; j++ )
            {
            trial_duration = insertion_sort_normal( i );
            output << trial_duration << ", ";
            }
        output << "\n";
        }
    output.close();

    /****************************************
    *  Sort Best Case Trials
    *****************************************/
    ofstream output2( "output_best.txt" );
    for( short int i = N_SKIP; i < N_MAX; i += N_SKIP )
        {
        for( int j = 0; j < NUM_TRIALS; j++ )
            {
            trial_duration = insertion_sort_best( i );
            output << trial_duration << ", ";
            }
        output2 << "\n";
        }
    output2.close();

    /****************************************
    *  Sort Worst Case Trials
    *****************************************/
    ofstream output3( "output_worst.txt" );
    for( short int i = N_SKIP; i < N_MAX; i += N_SKIP )
        {
        for( int j = 0; j < NUM_TRIALS; j++ )
            {
            trial_duration = insertion_sort_worst( i );
            output << trial_duration << ", ";
            }
        output3 << "\n";
        }
    output3.close();


    return 0;
    }