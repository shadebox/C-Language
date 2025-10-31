#ifndef __HELPERFUNCTION__
#define __HELPERFUNCTION__

// Function Definitions
void Print(const int* const array, size_t size);
void Swap(int* a, int* b);

// TODO :: Move this to alrogrithm files later
void BuildMaxHeap(int array[], size_t size);
void MaxHeapify(int array[], int i, size_t size);
#endif