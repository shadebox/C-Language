#include <stdio.h>
#include <stdbool.h>
#include "Sort.h"
#include "../../Debug.h"

void BubbleSort(int* array, size_t size)
{
    for (size_t i = size - 1; i > 0; i--)
    {
        bool didSwap = false;
        for (size_t j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                // array[j] = array[j] + array[j + 1];             // 4 + 5 = 9
                // array[j + 1] = array[j] - array[j + 1];         // 9 - 5 = 4
                // array[j] = array[j] - array[j + 1];             // 9 - 4 = 5

                array[j] = array[j] ^ array[j + 1];                 // (original a) ^ (original b)
                array[j + 1] = array[j] ^ array[j + 1];             // ((original a) ^ (original b)) ^ (original b) = (original a)
                array[j] = array[j] ^ array[j + 1];                 // ((original a) ^ (original b)) ^ (original a) = (original b)

                didSwap = true;
            }
        }

        if (!didSwap)
            break;
        Print(array, 10);
    }
}