#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

// O(1)
DoubleLinkedList* Initialize()
{
	DoubleLinkedList *doubleLinkedList;
	if ((doubleLinkedList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList))) == NULL)
		return NULL;

	doubleLinkedList->head = NULL;
	doubleLinkedList->tail = NULL;
	doubleLinkedList->size = 0;

	return doubleLinkedList;
}

// O(1)
int InsertBefore(DoubleLinkedList *doubleLinkedList, Node *item, const void *data)
{
	Node *node;
	if ((node = (Node *)malloc(sizeof(Node))) == NULL)
		return -1;

	if (item == NULL)
	{
		if (doubleLinkedList->head != NULL)
			return -1;

		doubleLinkedList->head = doubleLinkedList->tail = node;
		node->next = node->previous = NULL;
	}
	else
	{
		node->previous = item->previous;
		node->next = item;
		item->previous->next = node;
		item->previous = node;

		if (node->previous == NULL)
			doubleLinkedList->head = node;
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
		if (doubleLinkedList->tail != NULL)
			return -1;

		doubleLinkedList->head = doubleLinkedList->tail = node;
		node->next = node->previous = NULL;
	}
	else
	{
		node->next = item->next;
		item->next = node;
		node->previous = item;

		if (node->next == NULL)
			doubleLinkedList->tail = node;
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
Node* GetNode(const DoubleLinkedList const *doubleLinkedList, const void const *data, int(Compare)(const Node const *node, const void const *data))
{
	Node *node = doubleLinkedList->head;
	while (node != NULL)
	{
		if (Compare(node, data) == 1)
			return node;
		node = node->next;
	}

	return NULL;
}

int Destroy(DoubleLinkedList *doubleLinkedList, int(*Delete)(void *data))
{
	return 0;
}
