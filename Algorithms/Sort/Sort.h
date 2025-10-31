#ifndef __SORT__
#define __SORT__

// Function Definitions
void BubbleSort(int* array, size_t size);
void SelectionSort(int* array, size_t size);
void InsertionSort(int* array, size_t size);
void MergeSort(int array[], int start, int end);
void QuickSort(int array[], int start, int end);
void HeapSort(int array[], size_t size);

// Helper Function Definitions
void Merge(int array[], int start, int mid, int end);
int Pivot(int array[], int start, int end);

#endif