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
        //output<<i<<", "; //output number of elements in array

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
            auto start = chrono::high_resolution_clock::now();
            switch ( sort )
                {
                case INSERTIONSORT:
                    tester->insertion_sort();
                    break;

                case QUICKSORT:
                    tester->quick_sort( 0, tester->size-1);
                    break;

                case MERGESORT:
                    tester->merge_sort(0, tester->size-1);
                    break;

                case HEAPSORT:
                    tester->heap_sort();
                    break;

                case SELECTIONSORT:
                    tester->selection_sort();

                default:
                    break;
                }
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
                trial_duration = duration.count();
                total_duration += trial_duration;
            }
        output << total_duration/NUM_TRIALS << "\n";
        delete[] tester->unsorted_array;
        delete tester;
        }
    }