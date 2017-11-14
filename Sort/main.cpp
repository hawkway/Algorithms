#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
    int arr[10] = {5, 3, 64, 1, 53, 38, 76, 35, 34, 21};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Sort<int>::insertionSort(arr, len);

    Sort<int>::mergeSort(arr, len, "start");

    for (int i : arr)
        cout << i << " ";

    return 0;
} // main

