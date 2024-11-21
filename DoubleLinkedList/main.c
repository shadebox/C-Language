#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int* CreateElement(int data);
void Print(const DoubleLinkedList const *doubleLinkedList);
int Compare(const Node const *node, const void const *data);
void Delete(void *data);

int main(void)
{
	DoubleLinkedList *doubleLinkedList;
	if ((doubleLinkedList = Initialize(doubleLinkedList)) == NULL)
    {
        printf("Failed to Initialize DoubleLinkedList");
        return -1;
    }

	int *value = CreateElement(1);
	if (value == NULL)
		return -1;
	InsertAfter(doubleLinkedList, NULL, (void *)value);

	Node *node;
	if ((node = GetNode(doubleLinkedList, value, Compare)) == NULL)
		return -1;

	value = CreateElement(3);
	if (value == NULL)
		return -1;
	InsertAfter(doubleLinkedList, node, (void *)value);

	if ((node = GetNode(doubleLinkedList, value, Compare)) == NULL)
		return -1;

	value = CreateElement(2);
	if (value == NULL)
		return -1;
	InsertBefore(doubleLinkedList, node, (void *)value);

	int nodeValue = 3;
	if ((node = GetNode(doubleLinkedList, &nodeValue, Compare)) == NULL)
		return -1;
	
	value = CreateElement(4);
	if (value == NULL)
		return -1;
	InsertAfter(doubleLinkedList, node, (void *)value);

	printf("DoubleLinkedList Size: %d\n", Size(doubleLinkedList));
    ListItem(doubleLinkedList, Print);

	nodeValue = 3;
	int *removed = NULL;
	if ((node = GetNode(doubleLinkedList, &nodeValue, Compare)) == NULL)
		return -1;
	RemoveBefore(doubleLinkedList, node, (void*)&removed);
	printf("Removed: %d\n", *removed);

	nodeValue = 1;
	removed = NULL;
	if ((node = GetNode(doubleLinkedList, &nodeValue, Compare)) == NULL)
		return -1;
	RemoveAfter(doubleLinkedList, node, (void*)&removed);
	printf("Removed: %d\n", *removed);

	// removed = NULL;
	// RemoveAfter(doubleLinkedList, NULL, (void*)&removed);
	// printf("Removed: %d\n", *removed);

	
	// removed = NULL;
	// RemoveBefore(doubleLinkedList, NULL, (void*)&removed);
	// printf("Removed: %d\n", *removed);

	printf("DoubleLinkedList Size: %d\n", Size(doubleLinkedList));
    ListItem(doubleLinkedList, Print);

	if (Destroy(doubleLinkedList, Delete) == -1)
		return -1;
	else
		doubleLinkedList == NULL;

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

void Print(const DoubleLinkedList const *doubleLinkedList)
{
	printf("List: ");
	Node *node = doubleLinkedList->head;
	while (node != NULL)
	{
		printf("%d ", *(int *)node->data);
		node = node->next;
	}

	printf("\n");
}

int Compare(const Node const *node, const void const *data)
{
	if (*(int*)data == *(int*)node->data)
		return 1;
	return 0;
}

void Delete(void *data)
{
	printf("Deleting... %d\n", *(int *)data);
	free(data);
}