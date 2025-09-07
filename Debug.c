#include <stdio.h>
#include "Debug.h"

/* Helper Functions For Printing Arrays */
void Print(const int* const array, size_t size)
{
	printf("Array: ");
	for (size_t i = 0; i < size; i ++)
		printf("%d ", array[i]);
	printf("\n");
}