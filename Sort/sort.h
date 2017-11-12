#ifndef SORT_H
#define SORT_H

#include <string>
#include <math.h>
#include <iostream>

using namespace std;

//----------------------------------------------------------------
template <typename T>
class Sort
{
    // outline public member functions
    public:
        Sort();
        ~Sort();
        static void insertionSort(T input[], int len);
        static void mergeSort(T input[], len);

    // set private member functions
    private:
        static void findMin(T input[], int len);
        static void merge(T left[], T right[], T combined[]);

};
//----------------------------------------------------------------
template <typename T>
Sort<T>::Sort()
{
    // constructor
}
//----------------------------------------------------------------
template <typename T>
Sort<T>::~Sort()
{
    // destructor
}
//----------------------------------------------------------------
template <typename T>
void Sort<T>::insertionSort(T input[], int len)
{
    // copy contents
    T key;
    int i = 0;

    // set first element of array to the smallest
    Sort<T>::findMin(input, len);

    for (int j = 1; j < len; j++)
    {
        key = input[j];
        i = j - 1;
        while (i > 0 && input[i] > key)
        {
            input[i+1] = input[i];
            i = i - 1;
        } // while
        input[i+1] = key;
    } // for
} // insertion sort
//----------------------------------------------------------------
template <typename T>
void Sort<T>::findMin(T input[], int len)
{
    T temp;
    T min = input[0];
    int minIndex;

    for (int i = 0; i < len; i++)
    {
        if (input[i] < min)
        {
            min = input[i];
            minIndex = i;
        } // if
    } // for

    // swap min and first element
    temp = input[0];
    input[0] = min;
    if (minIndex != -1)
        input[minIndex] = temp;

} // find min
//----------------------------------------------------------------
template<typename T>
void Sort<T>::mergeSort(T input[], len)
{
    // get num of array elements
    int arrLen = sizeof(input)/sizeof(input[0]);

    if (arrLen > 1)
    {
        // get size of left sub array
        int leftSize = floor(arrLen/2);
        // get size of right sub array
        int rightSize = arrLen - ((floor(arrLen/2))+1);
        int rightStart = (floor(arrLen/2))+1;
        // create new sub arrays
        T left[leftSize] = {0};
        T right[rightSize] = {0};
        T combined[arrLen] = {0};
        // divide array
        // make left array
        for (int i = 0; i < leftSize; i++)
        {
            left[i] = input[i];
            cout << "left[" << i << "] = input[] = " << input[i] << "\n";
        }
        // make right array
        for (int i = rightStart; i < rightSize; i++)
        {
            right[i] = input[i];
            cout << "right[" << i << "] = input[] = " << input[i] << "\n";
        }

        // send arrays for division
        mergeSort(left);
        mergeSort(right);
        // merge sorted arrays
        merge(left, right, combined);

    } // if 
} // mergeSort
//----------------------------------------------------------------
template <typename T>
void Sort<T>::merge(T left[], T right[], T combined[])
{
    // get size of arrays
    int leftSize = sizeof(left)/sizeof(left[0]);
    int rightSize = sizeof(right)/sizeof(right[0]);
    int combinedSize = leftSize + rightSize;
    // init counters outside of loop
    int i = 0;
    int j = 0;
    // merge two arrays into one
    for (int k = 0; i < combinedSize; k++)
    {
        if ((i <= leftSize) && (j <= rightSize) && (left[i] <= right[j]))
        {
            // verify arrays are in bounds
            // if let is smaller
            combined[k] = left[i];
            i++;
        }
        else if ((i <= leftSize) && (j <= rightSize) && (left[i] <= right[j]))
        {
            // verify arrays are in bounds
            // if right is smaller
            combined[k] = right[j];
            j++;
        }
    } // for
} // merge
//----------------------------------------------------------------
#endif