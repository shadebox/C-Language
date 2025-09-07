#include <stdio.h>
#include "Algorithms/Sort/Sort.h"

/* Function Prototypes */
void Print(const int* const array, size_t size);

int main(void)
{
	int array[] = { 72, 54, 59, 30, 31, 78, 2, 77, 82, 72 };

	Print(array, 10);
	BubbleSort(array, 10);
	Print(array, 10);

	return 0;
}

/* Helper Functions For Printing Arrays */
void Print(const int* const array, size_t size)
{
	printf("Array: ");
	for (size_t i = 0; i < size; i ++)
		printf("%d ", array[i]);
	printf("\n");
}