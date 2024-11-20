#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

// O(1)
int Initialize(DoubleLinkedList *doubleLinkedList)
{
	if ((doubleLinkedList = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList))) == NULL)
		return -1;

	doubleLinkedList->size = 0;
	doubleLinkedList->head = NULL;
	doubleLinkedList->tail = NULL;

	return 0;
}

// O(1)
int InsertBefore(DoubleLinkedList *doubleLinkedList, Node *item, const void *data)
{
	Node *node;
	if ((node = (Node *)malloc(sizeof(Node))) == NULL)
		return -1;

	if (item == NULL)
	{
		doubleLinkedList->head = node;
		node->next = node->previous = NULL;
	}
	else
	{
		node->previous = item->previous;
		node->previous->next = node;

		node->next = item;
		item->previous = node;
	}

	node->data = (void *)data;
	doubleLinkedList->size++;

	return 0;
}

// O(1)
int InsertAfter(DoubleLinkedList *doubleLinkedList, Node *item, const void *data)
{
	Node *node;
	if ((node = (Node *)malloc(sizeof(Node))) == NULL)
		return -1;

	if (item == NULL)
	{
		doubleLinkedList->head = node;
		node->next = node->previous = NULL;
	}
	else
	{
		node->next = item->next;
		node->next->previous = node;
		printf("Error\n");

		if (item == NULL)
			printf("Error 1\n");
		item->next = node;
		node->previous = item;
	}

	node->data = (void *)data;
	doubleLinkedList->size++;

	return 0;
}

int RemoveAfter(DoubleLinkedList *doubleLinkedList, Node *item, void **data)
{
	return 0;
}

int RemoveBefore(DoubleLinkedList *doubleLinkedList, Node *item, void **data)
{
	return 0;
}

// O(1)
int Size(const DoubleLinkedList const *doubleLinkedList)
{
	return doubleLinkedList->size;
}

// O(Print())
void ListItem(const DoubleLinkedList const *doubleLinkedList, void(*Print)(const DoubleLinkedList const *doubleLinkedList))
{
	Print(doubleLinkedList);
}

// O(n)
Node* GetNode(const DoubleLinkedList const *doubleLinkedList, const void const *data)
{
	Node *node = doubleLinkedList->head;
	while (node != NULL)
	{
		if (node->data == data)
			return node;
		node = node->next;
	}

	return NULL;
}

int Destroy(DoubleLinkedList *doubleLinkedList, int(*Delete)(void *data))
{
	return 0;
}
