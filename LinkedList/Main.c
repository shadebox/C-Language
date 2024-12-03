#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int* CreateElement(int data);
void Print(const LinkedList* const linkedList);
int Compare(const Node* const node, const void* const data);
void DeleteInteger(void *data);

int main(void)
{
	LinkedList *linkedList;
    if (Initialize(&linkedList, DeleteInteger) == false)
		return -1;

	int *value = CreateElement(1);
	if(value == NULL)
		return -1;
		
	if (InsertAtFront(linkedList, (void*)value) == false)
		return -1;

	Node *member;
	if ((member = GetNode(linkedList, value, Compare)) == NULL)
		return -1;

	value = CreateElement(2);
	if(value == NULL)
		return -1;

	if (InsertAfter(linkedList, member, (void*)value) == false)
		return -1;
	member = NULL;
	
	value = CreateElement(3);
	if(value == NULL)
		return -1;

	if (InsertAtEnd(linkedList, (void*)value) == false)
		return -1;

	Print(linkedList);

	if ((member = GetNode(linkedList, value, Compare)) == NULL)
		return -1;

	if ((value = (int *)malloc(sizeof(int))) == NULL)
		return -1;
	
    if (RemoveAfter(linkedList, member, (void *)&value) == false)
		printf("Failed to remove member\n");
	else
		printf("Value removed %d\n", *value);

	if (Destroy(&linkedList) == false)
		return -1;

	printf("LinkedList destroyed");

	return 0;
}

int* CreateElement(int data)
{
	int *value = NULL;
	if((value = (int *)malloc(sizeof(int))) == NULL)
		return NULL;
		
	*value = data;
	return value;
}

void Print(const LinkedList* const linkedList)
{
	printf("Size: %d\n", Size(linkedList));

	Node *member = linkedList->head;
	printf("List: ");
	while (member != NULL)
	{
			printf("%d ", *(int*) member->data);
			member = member->next;
	}

	printf("\n");
}

int Compare(const Node* const node, const void* const data)
{
	if (*(int*)data == *(int*)node->data)
		return 1;
	return 0;
}

void DeleteInteger(void *data)
{
	free((int*)data);
	data = NULL;
}