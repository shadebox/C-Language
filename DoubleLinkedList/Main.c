#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DoubleLinkedList.h"

int* CreateElement(int data);
void Print(const DoubleLinkedList* const doubleLinkedList);
int Compare(const Node* const member, const void* const data);
void DeleteInteger(void *data);

int main(void)
{
	DoubleLinkedList *doubleLinkedList;
	if (Initialize(&doubleLinkedList, DeleteInteger) == false)
        return -1;

	int *value = CreateElement(1);
	if (value == NULL)
		return -1;
		
	if (InsertAtFront(doubleLinkedList, (void*)value) == false)
		return -1;

	Node *member;
	if ((member = GetNode(doubleLinkedList, value, Compare)) == NULL)
		return -1;
	
	value = CreateElement(2);
	if (value == NULL)
		return -1;

	if (InsertAfter(doubleLinkedList, member, (void*)value) == false)
		return -1;

	value = CreateElement(4);
	if (value == NULL)
		return -1;

	if (InsertAtEnd(doubleLinkedList, (void*)value) == false)
		return -1;

	if ((member = GetNode(doubleLinkedList, value, Compare)) == NULL)
		return -1;
	
	value = CreateElement(3);
	if (value == NULL)
		return -1;

	if (InsertBefore(doubleLinkedList, member, (void*)value) == false)
		return -1;
	
	Print(doubleLinkedList);

	int *removed = CreateElement(3);
	if ((member = GetNode(doubleLinkedList, removed, Compare)) == NULL)
		return -1;
	
	if (RemoveAfter(doubleLinkedList, member, (void*)&removed) == true)
		printf("Removed after: %d\n", *removed);

	removed = CreateElement(3);
	if ((member = GetNode(doubleLinkedList, removed, Compare)) == NULL)
		return -1;
	
	if (RemoveBefore(doubleLinkedList, member, (void*)&removed) == true)
		printf("Removed before: %d\n", *removed);

	if (RemoveAtFront(doubleLinkedList, (void*)&removed) == true)
		printf("Removed from front: %d\n", *removed);

	if (RemoveAtEnd(doubleLinkedList, (void*)&removed) == true)
		printf("Removed from end: %d\n", *removed);

	Print(doubleLinkedList);

	if (Destroy(&doubleLinkedList) == false)
		return -1;

	printf("DoubleLinkedList destroyed");

	return 0;
}

int* CreateElement(int data)
{
	int *value;
	if ((value = (int *)malloc(sizeof(int))) == NULL)
		return NULL;

	*value = data;
	return value;
}

void Print(const DoubleLinkedList* const doubleLinkedList)
{
	printf("DoubleLinkedList Size: %d\n", Size(doubleLinkedList));

	printf("List: ");
	Node *member = doubleLinkedList->head;
	while (member != NULL)
	{
		printf("%d ", *(int *)member->data);
		member = member->next;
	}

	printf("\n");
}

int Compare(const Node* const member, const void* const data)
{
	if (*(int*)data == *(int*)member->data)
		return 1;
	return 0;
}

void DeleteInteger(void *data)
{
	printf("Deleting... %d\n", *(int *)data);
	free((int*)data);
	data = NULL;
}