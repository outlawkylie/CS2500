// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Driver for the implementation of the insertion sort algorithm


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
    const short int NUM_TRIALS     = 10;
    const short int N_SKIP         = 10;
    const short int N_MAX          = 500;
    long long       trial_duration = 0;
    unsigned short int i           = 0;


    /****************************************
    *  Sort Random Trials
    *****************************************/
    ofstream output( "output_random.txt" );
    for(i = N_SKIP; i <= N_MAX; i+= N_SKIP )
        {
        output << i << ", "; //output number of elements in array
        for( int j = 0; j < NUM_TRIALS; j++ )
            {
            //get time in ns for insertion sort to run and output to txt
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
    for( i = N_SKIP; i <= N_MAX; i += N_SKIP )
        {
        output2 << i << ", "; //output number of elements in array
        for( int j = 0; j < NUM_TRIALS; j++ )
            {
            //get time in ns for insertion sort to run and output to txt
            trial_duration = insertion_sort_best( i );
            output2 << trial_duration << ", ";
            }
        output2 << "\n";
        }
    output2.close();


    /****************************************
    *  Sort Worst Case Trials
    *****************************************/
    ofstream output3( "output_worst.txt" );
    for( i = N_SKIP; i <= N_MAX; i += N_SKIP )
        {
        output3 << i << ", "; //output number of elements in array
        for( int j = 0; j < NUM_TRIALS; j++ )
            {
            //get time in ns for insertion sort to run and output to txt
            trial_duration = insertion_sort_worst( i );
            output3 << trial_duration << ", ";
            }
        output3 << "\n";
        }
    output3.close();


    return 0;
    }