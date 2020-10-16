// Author: Kylie Outlaw
// Date: 10/15/2020
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
*   PRECONDITION: Array A[n] exists with comparable values
*
*   POSTCONDITION: Array A[0...n-1] is sorted
* 
******************************************************************/
template <typename T>
void sortclass<T>::insertion_sort(void)
    {
    // Invarient for loop: Array [0...i-1] is sorted
    for (int i = 1; i < size; i++)
        {
        T key = unsorted_array[i];
        int j = i;

        // Invarient while loop: A[i-1] is largest in A[i-1...j]
        while (j > 0 && (unsorted_array[j - 1] > key))
            {
            unsorted_array[j] = unsorted_array[j - 1];
            j = j - 1;
            }
        unsorted_array[j] = key;
        // Check invarient
        assert( unsorted_array[i] >= unsorted_array[i-1]);
        }
    }


/******************************************************************
*   NAME: quick_sort()
*
*   DESCRIPTION: Sorts unsorted_array[] member variable
*                using quicksort method
* 
*   PRECONDITION: Array A[n] exists with comparable values
*
*   POSTCONDITION: Array A[0...n-1] is sorted
* 
******************************************************************/
template <typename T>
void sortclass<T>::quick_sort( int low, int high )
    {
    // verify that low < high (needed for successful algorithm)
    assert( low < high );

    // run the sort algorithm
    if (low < high)
        {
        int test = quick_sort_partition( low, high );
        quick_sort( low, test-1 );
        quick_sort( test+1, high );
        }
    //ensure that the first array value is lesser than the following
    assert( unsorted_array[low] <= unsorted_array[low+1]);
    }

/******************************************************************
*   NAME: quick_sort_partition()
*
*   DESCRIPTION: Partitions array for quick_sort().
******************************************************************/
template <typename T>
int sortclass<T>::quick_sort_partition( int low, int high )
    {
    // verify that low < high (needed for successful algorithm)
    assert(low < high);

    int x = unsorted_array[high];
    int i = low-1;
    for (int j = low; j <= high - 1; j++)
        {
        if (unsorted_array[j] < x)
            {
            i++;
            // swap A[j] & A[i]
            swap(i, j);
            }
        }
        // Swap A[i+1] and A[high]
        assert( i == high+1 );
        swap(i+1, high);
    return (i+1);
    }



/******************************************************************
*   NAME: merge_sort()
*
*   DESCRIPTION: Sorts unsorted_array[] member variable using
*                merge sort method
* 
*   PRECONDITION: Array A[n] exists with comparable values
*
*   POSTCONDITION: Array A[0...n-1] is sorted
* 
******************************************************************/
template <typename T>
void sortclass<T>::merge_sort( int low, int high )
    {
    int middle;
    // assert if low&high not valid or if array of size 0 or 1
    assert(low < high); //check if low and high values are valid

    // run through merge sort  for the first half, second half, then combine
    // the two new sorted halves
    if (low < high)
        {
        middle = (low+high)/2;
        merge_sort( low, middle );
        merge_sort( middle+1, high);
        merge(low, high, middle);
        }
    }


/******************************************************************
*   NAME: merge()
*
*   DESCRIPTION: Merges together two sorted arrays for merge_sort()
******************************************************************/
template <typename T>
void sortclass<T>::merge(int low, int high, int mid)
    {
    int i = 0, j = 0, k = 0; //initialize variables for merge
    T * new_array = new T[size];

    //set up loop counters, i for low side, j for high side
    //and k to represent the current location in the new sorted array
    i = low, k = low, j = mid + 1;

    // loop until every array value has been touched
    while (i <= mid && j <= high) 
        {
        // if the value on left side is less than right side, 
        //copy the left side value to new array and increment counters
        if (unsorted_array[i] < unsorted_array[j]) 
            {
            new_array[k] = unsorted_array[i];
            k++;
            i++;
            }
        // otherwise, copy the right side value and increment counters
        else 
            {
            new_array[k] = unsorted_array[j];
            k++;
            j++;
            }
        // check invarient each loop to make sure the values are
        // each being updated in sorted order
        assert(new_array[k] > new_array[k+1]);
        }
    // if there are any remaining values on either side,
    // copy over to new array and increment counters
    while (i <= mid) 
        {
        new_array[k] = unsorted_array[i];
        k++;
        i++;
        }
    while (j <= high) 
        {
        new_array[k] = unsorted_array[j];
        k++;
        j++;
        }
    // copy all the new, sorted values, back to the original array
    for (i = low; i < k; i++) 
        {
        unsorted_array[i] = new_array[i];
        }
    delete[] new_array; //clear memory
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
        swap(i, largest);
        max_heapify( unsorted_array, sz, largest);
        }

    return;
    }


/******************************************************************
*   NAME: heap_sort()
*
*   DESCRIPTION: Sorts unsorted_array[] member variable using
*                heap sort method
* 
*   PRECONDITION: Array A[n] exists with comparable values
*
*   POSTCONDITION: Array A[0...n-1] is sorted
* 
******************************************************************/
template <typename T>
void sortclass<T>::heap_sort(void)
    {
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
        swap(0, i);

        max_heapify( unsorted_array, i, 0);
        }
    }


/******************************************************************
*   NAME: selection_sort()
*
*   DESCRIPTION: Sorts unsorted_array[] member variable using
*                selection sort
*
*   PRECONDITION: Array A[n] exists with comparable values
*
*   POSTCONDITION: Array A[0...n-1] is sorted
* 
******************************************************************/
template <typename T>
void sortclass<T>::selection_sort(void)
    {
    int min=0, i=0, j=0; // set up counters
    
    // for each value in the array, set the minimum = to the current i
    for ( i = 0; i < size; i++)
        {
        min = i;

        // compare the values at min and each other value in the array
        for ( j = i + 1; j < size; j++)
            {
            if (unsorted_array[j] < unsorted_array[min])
                {
                //if a value is lower than the current min, set it to new min
                min = j;
                }
            }
        //swap the newest minimum value with the old i value
        swap(min, i);

        //check that the current index is now lesser than the one after it
        assert(unsorted_array[i]<unsorted_array[i+1]);
        }
        
    }


/******************************************************************
*   NAME: array_to_bestcase()
*
*   DESCRIPTION: adjusts all elements in unsorted_array[] to be
*                best case scenario (already sorted)
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
*   DESCRIPTION: adjusts all elements in unsorted_array[] to be
*                worst case scenario (reverse sorted)
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
*   DESCRIPTION: adjusts all elements in unsorted_array[] to be
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
*   DESCRIPTION: adjusts all elements in unsorted_array[] to be same
******************************************************************/
template <typename T>
void sortclass<T>::array_to_same(void)
    {
    for (int i = 0; i < size; i++)
        {
        unsorted_array[i] = 1;
        }
    }


/******************************************************************
*   NAME: swap()
*
*   DESCRIPTION: swaps unsorted_array[] elements x and y
******************************************************************/
template <typename T>
void sortclass<T>::swap(int x, int y)
    {
    T temp = unsorted_array[x];
    unsorted_array[x] = unsorted_array[y];
    unsorted_array[y] = temp;
    }