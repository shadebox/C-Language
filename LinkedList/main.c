#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int* CreateElement(int data);
void Print(const LinkedList* const linkedList);
int Compare(const Node* const node, const void* const data);
void DeleteNode(Node *node);
void Delete(void *data);

int main(void)
{
	LinkedList *linkedList;
    if (Initialize(&linkedList, DeleteNode) == -1)
		return -1;

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
	Print(linkedList);

	if ((value = (int *)malloc(sizeof(int))) == NULL)
		return -1;
    if (RemoveAfter(linkedList, node, (void *)&value) == -1)
		printf("Failed to remove node\n");
	else
		printf("Value removed %d\n", *value);

	printf("Size after remove %d\n", Size(linkedList));
	Print(linkedList);

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

void DeleteNode(Node *node)
{
	free(node);
}

void Delete(void *data)
{
	free(data);
}