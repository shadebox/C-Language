#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int* CreateElement(int data);
void Print(const LinkedList* const linkedList);
int Compare(const Node* const node, const void* const data);
void Delete(void *data);

int main(void)
{
	LinkedList *linkedList;
    if ((linkedList = Initialize(linkedList)) == NULL)
	{
		printf("Failed to Initialize LinkedList");
		return -1;
	}

	int *value = CreateElement(1);
	if(value == NULL)
		return -1;
        InsertAfter(linkedList, NULL, (void *)value);

	Node *node;
	if((node = GetNode(linkedList, value, Compare)) == NULL)
		return -1;

	value = CreateElement(2);
	if(value == NULL)
		return -1;
        InsertAfter(linkedList, node, (void *)value);

	if((node = GetNode(linkedList, value, Compare)) == NULL)
		return -1;

	value = CreateElement(3);
	if(value == NULL)
		return -1;
        InsertAfter(linkedList, node, (void *)value);

	printf("Size after insert %d\n", Size(linkedList));
	ListItem(linkedList, Print);

	int *remove = NULL;
	if ((value = (int *)malloc(sizeof(int))) == NULL)
		return -1;
        if (RemoveAfter(linkedList, node, (void *)&remove) == -1)
		printf("Failed to remove node\n");
	else
		printf("Value removed %d\n", *remove);

	printf("Size after remove %d\n", Size(linkedList));
	ListItem(linkedList, Print);

	if (Destroy(linkedList, Delete) == -1)
		return -1;
	else
		linkedList == NULL;

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

void Delete(void *data)
{
	printf("Deleting... %d\n", *(int *)data);
	free(data);
}