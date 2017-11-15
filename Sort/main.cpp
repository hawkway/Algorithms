#include "sort.h"

using namespace std;

int main()
{
    int arr[10] = {5, 3, 64, 1, 53, 38, 76, 35, 34, 21};
    int len = sizeof(arr) / sizeof(arr[0]);

    // print unsorted
    Sort<int>::printArray(arr, len);

    // Sort<int>::insertionSort(arr, len);
    Sort<int>::mergeSort(arr, len, "start");

    // print sorted array
    Sort<int>::printArray(arr, len);

    return 0;
} // main