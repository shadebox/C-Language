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
