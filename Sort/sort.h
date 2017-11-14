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
        static void mergeSort(T input[], int len, string id);

    // set private member functions
    private:
        static void findMin(T input[], int len);
        static void merge(T left[], T right[], T combined[], int leftSize, int rightSize);

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
void Sort<T>::mergeSort(T input[], int len, string id)
{
    printf("enter mergeSort(%s)\n", id.c_str());
    if (len > 1)
    {
        // get size of left sub array
        int leftSize = floor(len/2);
        cout << "leftSize = " << leftSize << "\n";
        // get size of right sub array
        int rightSize = len - (floor(len/2)+1);
        cout << "rightSize = " << rightSize << "\n";
        int rightStart = (floor(len/2))+1;
        // create new sub arrays
        T left[leftSize] = {0};
        T right[rightSize] = {0};
        T combined[len] = {0};
        // divide array
        // make left array
        for (int i = 0; i < leftSize; i++)
        {
            left[i] = input[i];
            printf("left[%d] = input[%d] = %d\n", i, i, input[i]);
        }
        // make right array
        for (int i = rightStart; i < rightSize; i++)
        {
            right[i] = input[i];
            printf("right[%d] = input[%d] = %d\n", i, i, input[i]);
        }

        // send arrays for division
        mergeSort(left, leftSize, "left");
        mergeSort(right, rightSize, "right");
        // merge sorted arrays
        merge(left, right, combined, leftSize, rightSize);

        for (int i = 0; i < len; i++)
            printf("combined[%d] = %d\n", i, combined[i]);

        cout << "\n\n";
    } // if
    else
        cout << "len <= 1\n";
} // mergeSort
//----------------------------------------------------------------
template <typename T>
void Sort<T>::merge(T left[], T right[], T combined[], int leftSize, int rightSize)
{
    // get size of arrays
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