#include <stdio.h>
#include "HelperFunction.h"
#include "Algorithms/Sort/Sort.h"

int main(void)
{
	int array[] = { 72, 54, 59, 30, 31, 78, 2, 77, 82, 72 };
	size_t len = sizeof(array) / sizeof(array[0]);

	Print(array, len);
	InsertionSort(array, len);
	// SelectionSort(array, len);
	// BubbleSort(array, len);

	return 0;
}
