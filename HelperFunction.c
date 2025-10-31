#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

// TODO :: Move this to alrogrithm files later
void BuildMaxHeap(int array[], size_t size)
{
	// Implementation for building a max heap
	int mid = floor(size / 2);

	for (int i = mid; i >= 0; i--)
	{
		MaxHeapify(array, i, size);
	}
}

void MaxHeapify(int array[], int i, size_t size)
{
	int leftIndex = (2 * i) + 1;  // left child index is 2*i + 1
	int rightIndex = (2 * i) + 2; // right child index is (2*i) + 2
	int larger = i;

	int left = array[leftIndex];
	int right = array[rightIndex];

	if (leftIndex <= size && left > array[larger])
		larger = leftIndex;

	if (rightIndex <= size && right > array[larger])
		larger = rightIndex;

	if (larger != i)
	{
		int temp = array[i];
		array[i] = array[larger];
		array[larger] = temp;

		MaxHeapify(array, larger, size);
	}
}