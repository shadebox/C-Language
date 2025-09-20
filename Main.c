#include <stdio.h>
#include "HelperFunction.h"
#include "Algorithms/Sort/Sort.h"

int main(void)
{
	int array[] = { 72, 54, 59, 30, 31, 78, 2, 77, 82, 72 };

	Print(array, 10);
	SelectionSort(array, 10);
	// BubbleSort(array, 10);

	return 0;
}
