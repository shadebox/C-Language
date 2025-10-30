#include <stdio.h>
#include "HelperFunction.h"
#include "Algorithms/Sort/Sort.h"

int main(void)
{
	int array[] = { 72, 54, 59, 30, 31, 78, 2, 77, 82, 72 };
	int len = sizeof(array) / sizeof(array[0]);

	Print(array, len);

	// QuickSort(array, 0, len - 1);
	// MergeSort(array, 0, len);
	// InsertionSort(array, len);
	// SelectionSort(array, len);
	// BubbleSort(array, len);

	Print(array, len);

	return 0;
}
