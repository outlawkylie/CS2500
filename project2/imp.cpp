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


/******************************************************************
*   NAME: insertion_sort_normal()
*
*   DESCRIPTION: runs the insertion sort program on a random array
*                and returns time taken to sort in ns
******************************************************************/
template <typename T>
long long insertion_sort_normal( short int size )
    {
    sortclass<T>* sort = new sortclass( size ); 
    auto start = chrono::high_resolution_clock::now();
    sort->insertion_sort();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    delete sort;
    return duration.count();
    }


/******************************************************************
*   NAME: insertion_sort_best()
*
*   DESCRIPTION: runs the insertion sort program on a best case 
*                array and returns time taken to sort in ns
******************************************************************/
template <typename T>
long long insertion_sort_best( short int size )
    {
    sortclass<T>* sort = new sortclass( size );
    sort->array_to_bestcase();
    auto start = chrono::high_resolution_clock::now();
    sort->insertion_sort();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    delete sort;
    return duration.count();
    }


/******************************************************************
*   NAME:
*
*   DESCRIPTION: runs the insertion sort program on a worst case
*                array and returns time taken to sort in ns
******************************************************************/
template <typename T>
long long insertion_sort_worst( short int size )
    {
    sortclass<T>* sort = new sortclass( size );
    sort->array_to_worstcase();
    auto start = chrono::high_resolution_clock::now();
    sort->insertion_sort();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    delete sort;
    return duration.count();
    }

template <typename T>
void run_test(int type, sortclass<T> test, int size, string name)
    {
    /*  Variables  */
    long long trial_duration = 0;

    /* Run the test */
    ofstream output( name+".txt" );
    for (int i = N_SKIP; i <= N_MAX; i += N_SKIP)
        {
        output<<i<<", "; //output number of elements in array
        for (int j = 0; j < NUM_TRIALS; j++)
            {
            //get time in ns for sort to run and output to txt
            switch (type)
                {
                case BEST_CASE:
                    test->array_to_bestcase();
                    break;

                case NORMAL_CASE:
                    test->array_to_random();
                    break;

                case WORST_CASE:
                    test->array_to_worstcase();
                    break;

                case SAME_CASE:
                    test->array_to_samecase();
                    break;
                     
                default:
                    break;
                }
            }
        }
    }
