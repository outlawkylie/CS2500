// Author: Kylie Outlaw
// Date: 9/27/2020
// Purpose: Sort class constructor and function definitions

#include <iostream>
using namespace std;


/* Default Constructor */
template <typename T>
sortclass<T>::sortclass()
    {
    size = 0;
    unsorted_array = NULL;
    }


/* Parameterized Constructor */
template <typename T>
sortclass<T>::sortclass(short int arr_size)
    {
    size = arr_size;
    unsorted_array = new T[arr_size];
    for (int i = 0; i < arr_size; i++)
        {
        unsorted_array[i] = rand() % 10000;
        }
    }


/******************************************************************
*   NAME: insertion_sort()
*
*   DESCRIPTION: returns the amount of time in ns required to
*                perform insertion sort
******************************************************************/
template <typename T>
long long sortclass<T>::insertion_sort(void)
    {
    auto start = chrono::high_resolution_clock::now();


    for (int i = 1; i < size; i++)
        {
        T key = unsorted_array[i];
        int j = i;
        while (j > 0 && (unsorted_array[j - 1] > key))
            {
            unsorted_array[j] = unsorted_array[j - 1];
            j = j - 1;
            }
        unsorted_array[j] = key;
        }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    return duration.count();
    }


/******************************************************************
*   NAME: quick_sort()
*
*   DESCRIPTION: returns the amount of time in ns required to
*                perform quick sort
******************************************************************/
template <typename T>
long long sortclass<T>::quick_sort(void)
    {
    auto start = chrono::high_resolution_clock::now();


    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    return duration.count();
    }


/******************************************************************
*   NAME: merge_sort()
*
*   DESCRIPTION: returns the amount of time in ns required to
*                perform merge sort
******************************************************************/
template <typename T>
long long sortclass<T>::merge_sort(void)
    {
    auto start = chrono::high_resolution_clock::now();


    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    return duration.count();
    }


/******************************************************************
*   NAME: max_heapify()
*
*   DESCRIPTION: heapifys the subtree
******************************************************************/
template <typename T>
void sortclass<T>::max_heapify(T arr[], int sz, int i)
    {
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    // check if the left node is larger than root node
    if ((left < sz) && unsorted_array[left] > unsorted_array[largest])
        {
        largest = left;
        }

    // check if right node is larger than current largest
    if ((right < sz) && unsorted_array[right] > unsorted_array[largest])
        {
        largest = right;
        }

    // swap with root if the root isn't the largest currently
    if (largest != i)
        {
        T temp = unsorted_array[i];
        unsorted_array[i] = unsorted_array[largest];
        unsorted_array[largest] = temp;

        max_heapify(unsorted_array, sz, largest);
        }

    return;
    }


/******************************************************************
*   NAME: heap_sort()
*
*   DESCRIPTION: returns the amount of time in ns required to
*                perform heap sort
******************************************************************/
template <typename T>
long long sortclass<T>::heap_sort(void)
    {
    auto start = chrono::high_resolution_clock::now();
    int sz = size;
    // build max heap
    for (int i = (sz / 2) - 1; i >= 0; i--)
        {
        max_heapify( unsorted_array, sz, i );
        }

    // sort the heap
    for (int i = sz - 1; i > 0; i--)
        {
        // swap A[i] and A[0]
        T temp = unsorted_array[0];
        unsorted_array[0] = unsorted_array[i];
        unsorted_array[i] = temp;

        max_heapify(unsorted_array, i, 0);
        }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    return duration.count();
    }


/******************************************************************
*   NAME: selection_sort()
*
*   DESCRIPTION: returns the amount of time in ns required to
                 perform selection sort
******************************************************************/
template <typename T>
long long sortclass<T>::selection_sort(void)
    {
    auto start = chrono::high_resolution_clock::now();
    int min=0, i=0, j=0; 
    for ( i = 0; i < size; i++)
        {
        min = i;
        for ( j = i + 1; j < size; j++)
            {
            if (unsorted_array[j] < unsorted_array[min])
                {
                min = j;
                }
            }
        T temp = unsorted_array[min];
        unsorted_array[min] = unsorted_array[i];
        unsorted_array[i] = temp;
        }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    return duration.count();
    }


/******************************************************************
*   NAME: array_to_bestcase()
*
*   DESCRIPTION: adjusts all elements in unsorted_array to be
*                best case scenario
******************************************************************/
template <typename T>
void sortclass<T>::array_to_bestcase(void)
    {
    for (int i = 0; i < size; i++)
        {
        unsorted_array[i] = i;
        }
    }


/******************************************************************
*   NAME: array_to_worstcase()
*
*   DESCRIPTION: adjusts all elements in unsorted_array to be
*                worst case scenario
******************************************************************/
template <typename T>
void sortclass<T>::array_to_worstcase(void)
    {
    for (int i = 0; i < size; i++)
        {
        unsorted_array[i] = size - i;
        }
    }


/******************************************************************
*   NAME: array_to_bestcase()
*
*   DESCRIPTION: adjusts all elements in unsorted_array to be
*                random case scenario
******************************************************************/
template <typename T>
void sortclass<T>::array_to_random(void)
    {
    for (int i = 0; i < size; i++)
        {
        unsorted_array[i] = rand() % 100;
        }
    }


/******************************************************************
*   NAME: array_to_same()
*
*   DESCRIPTION: adjusts all elements in unsorted_array to be same
******************************************************************/
template <typename T>
void sortclass<T>::array_to_same(void)
    {
    for (int i = 0; i < size; i++)
        {
        unsorted_array[i] = 1;
        }
    }
