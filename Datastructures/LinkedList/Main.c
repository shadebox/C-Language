#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int* CreateElement(int data);
void Print(const LinkedList* const linkedList);
bool Compare(const Node* const member, const NodeData const data);
bool Delete(NodeData data);

int main(void)
{
	LinkedList *linkedList;
    if (InitializeLinkedList(&linkedList, Compare, Delete) == false)
		return -1;

	int *value = CreateElement(1);
	if (value == NULL)
		return -1;

	if (InsertAtFront(linkedList, value) == false)
		return -1;
	
	value = CreateElement(2);
	if (value == NULL)
		return -1;

	if (InsertAtEnd(linkedList, value) == false)
		return -1;

	Print(linkedList);

	if (DestroyLinkedList(&linkedList) == false)
		return -1;

	if (DestroyLinkedList(&linkedList) == false)
		return -1;

	return 0;
}

/*
int main(void)
{
	LinkedList *linkedList;
    if (Initialize(&linkedList, Compare, Delete) == false)
		return -1;

	int *value = CreateElement(1);
	if (value == NULL)
		return -1;
		
	if (InsertAtFront(linkedList, (void*)value) == false)
		return -1;

	Node *member;
	if ((member = GetNode(linkedList, value)) == NULL)
		return -1;

	value = CreateElement(2);
	if (value == NULL)
		return -1;

	if (InsertAfter(linkedList, member, (void*)value) == false)
		return -1;

	value = CreateElement(3);
	if (value == NULL)
		return -1;

	if (InsertAtEnd(linkedList, (void*)value) == false)
		return -1;

	Print(linkedList);

	if ((value = (int *)malloc(sizeof(int))) == NULL)
		return -1;
	
    if (RemoveAfter(linkedList, member, (void *)&value) == false)
		printf("Failed to remove member\n");
	else
		printf("Value removed %d\n", *value);

	Print(linkedList);

	if (Destroy(&linkedList) == false)
		return -1;

	printf("LinkedList destroyed");

	return 0;
}*/

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
	printf("Size: %d\n", linkedList->size);

	Node *member = linkedList->head;
	printf("List: ");
	while (member != NULL)
	{
		printf("%d ", *(int*) member->data);
		member = member->next;
	}

	printf("\n");
}

bool Compare(const Node* const member, const NodeData const data)
{
	if (*(int*)data == *(int*)member->data)
		return true;
	return false;
}

bool Delete(NodeData data)
{
	if (data == NULL)
		return false;

    printf("Deleting %d ...\n", *(int*)data);
	
	free((int*)data);
	data = NULL;

	return true;
}