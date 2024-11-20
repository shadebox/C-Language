#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int* CreateElement(int data);
void Print(const DoubleLinkedList const *doubleLinkedList);

int main(void)
{
	printf("Hellow World!");
	/*DoubleLinkedList *doubleLinkedList;
	if (Initialize(doubleLinkedList) == -1)
    {
        printf("Failed to Initialize DoubleLinkedList");
        return -1;
    }*/

	/*int *value = CreateElement(1);
	if (value == NULL)
		return -1;
	InsertAfter(doubleLinkedList, NULL, (void *)value);

	Node *node;
	if ((node = GetNode(doubleLinkedList, value)) == NULL)
		return -1;

	value = CreateElement(3);
	if (value == NULL)
		return -1;
	InsertAfter(doubleLinkedList, node, (void *)value);

/*	if((node = GetNode(doubleLinkedList, value)) == NULL)
		return -1;
*/
	/*value = CreateElement(2);
	if (value == NULL)
		return -1;
	InsertBefore(doubleLinkedList, NULL, (void *)value);*/

/*	printf("Size after insert %d\n", Size(doubleLinkedList));
        ListItem(doubleLinkedList, Print);
*/
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
		printf("%d", *(int *)node->data);
		node = node->next;
	}

	printf("\n");
}
