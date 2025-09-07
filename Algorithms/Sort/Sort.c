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
        Print(array, 10);
    }
}


void SelectionSort(int* array, size_t size)
{

}
