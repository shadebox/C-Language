#include <stdio.h>
#include "HelperFunction.h"

/* Helper Functions For Printing Arrays */
void Print(const int* const array, size_t size)
{
	printf("Values: ");
	for (size_t i = 0; i < size; i ++)
		printf("%d ", array[i]);
	printf("\n");
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	// These all have a flaw of some kind, 
	// if the values are too large or the 
	// same memory address is supplied for 
	// both parameters then it will not work correctly.
	// These are for educational purposes only.
	
	// *a = *a + *b;		// 4 + 5 = 9
	// *b = *a - *b;		// 9 - 5 = 4
	// *a = *a - *b;		// 9 - 4 = 5

	// *a = *a ^ *b;		// (original a) ^ (original b)
	// *b = *a ^ *b;		// ((original a) ^ (original b)) ^ (original b) = (original a)
	// *a = *a ^ *b;		// ((original a) ^ (original b)) ^ (original a) = (original b)
}