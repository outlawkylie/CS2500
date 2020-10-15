// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Function definitions to support the insertion sort program


#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>
#include "imp.h"
#include "sort.h"
using namespace std;

/******************************************************************
*   NAME: print_array()
*
*   DESCRIPTION: prints any array to terminal given the size
******************************************************************/
template <typename T>
void print_array(T arr[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        cout<<arr[i]<<" | ";
        }
    cout << endl << endl;
    return;
    }

void run_test(int type, int sort, const string name)
    {
    /*  Variables  */
    long long trial_duration = 0;
    long long total_duration = 0;

    /* Run the test */
    ofstream output(name); //setup output TXT file

    // Run through each length 
    for (int i = 0; i <= N_MAX; i += N_SKIP)
        {
        sortclass<int>* tester = new sortclass<int>(i);
        output<<i<<", "; //output number of elements in array

        // Run the test NUM_TRIALS number of times
        for (int j = 0; j < NUM_TRIALS; j++)
            {
            /* First, sort the array to match its best/worst scenario */
            switch ( type )
                {
                case BEST_CASE:
                    tester->array_to_bestcase();
                    break;

                case NORMAL_CASE:
                    tester->array_to_random();
                    break;

                case WORST_CASE:
                    tester->array_to_worstcase();
                    break;

                case SAME_CASE:
                    tester->array_to_same();
                    break;
                     
                default:
                    break;
                }
            /* Next, run the sort required for this test */
            switch ( sort )
                {
                case INSERTIONSORT:
                    trial_duration = tester->insertion_sort();
                    break;

                case QUICKSORT:
                    trial_duration = tester->quick_sort( 0, tester->size-1);
                    break;

                case MERGESORT:
                    trial_duration = tester->merge_sort(0, tester->size-1);
                    break;

                case HEAPSORT:
                    trial_duration = tester->heap_sort();
                    break;

                case SELECTIONSORT:
                    trial_duration = tester->selection_sort();

                default:
                    break;
                }
                total_duration += trial_duration;
            }
        output << total_duration/NUM_TRIALS << "\n";
        delete[] tester->unsorted_array;
        delete tester;
        }
    }