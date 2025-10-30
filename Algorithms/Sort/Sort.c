#include <stdio.h>
#include <stdbool.h>
#include "Sort.h"
#include "../../HelperFunction.h"

void BubbleSort(int* array, size_t size)
{
    for (size_t i = size - 1; i > 0; i--)
    {
        bool didSwap = false;
        for (size_t j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                Swap(&array[j], &array[j + 1]);
                didSwap = true;
            }
        }

        if (!didSwap)
            break;
        Print(array, size);
    }
}

void SelectionSort(int* array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[minIndex] > array[j])
                minIndex = j;
        }

        if (i != minIndex)
            Swap(&array[i], &array[minIndex]);
        Print(array, size);
    }
}

void InsertionSort(int* array, size_t size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
        Print(array, size);
    }
}

void MergeSort(int array[], int start, int end)
{
    // Base Case
    if (start >= end)
        return;

    // Divide the array into two halves
    int mid = (start + end) / 2;

    MergeSort(array, start, mid);
    MergeSort(array, mid + 1, end);

    // Conquer the two halves
    Merge(array, start, mid, end);
}

void QuickSort(int array[], int start, int end)
{
    // Base Case
    if (start >= end)
        return;
    
    // Choosing the first element as pivot
    int pivotIndex = Pivot(array, start, end);

    // Call QuickSort again on subarrays
    QuickSort(array, start, pivotIndex - 1);
    QuickSort(array, pivotIndex + 1, end); 
}

// MergeSort Helper Function
void Merge(int array[], int start, int mid, int end)
{
    int n1 = mid - start + 1; // Size of left array
    int n2 = end - mid;       // Size of right array

    // Store the two halves in temporary arrays
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = array[start + i];

    // We want mid + 1 because mid is part of the left array
    for (int i = 0; i < n2; i++)
        right[i] = array[ mid + 1 + i];

    // Merge the two halves back into the original array
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }

        k++;
    }
    
     while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }
        
    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

int Pivot(int array[], int start, int end)
{
    int pivotValue = array[end];

    // These will track the index for swapping
    int i = start - 1;

    for (int j = start; j <= end; j++)
    {
        if (array[j] < pivotValue)
        {
            i = i + 1;
            Swap(&array[i], &array[j]);
        }
    }
    
    i = i + 1;
    Swap(&array[i], &array[end]);

    return i;
}