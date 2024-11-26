#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

// O(1)
int Initialize(DoubleLinkedList **doubleLinkedList, void(*Delete)(Node *data))
{
	if ((*doubleLinkedList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList))) == NULL)
		return -1;

	(*doubleLinkedList)->head = NULL;
	(*doubleLinkedList)->tail = NULL;
	(*doubleLinkedList)->size = 0;
	(*doubleLinkedList)->Delete = Delete;

	return 1;
}

// O(1)
int InsertBefore(DoubleLinkedList* const doubleLinkedList, Node* const item, const void* const data)
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
int InsertAfter(DoubleLinkedList* const doubleLinkedList, Node* const item, const void* const data)
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

// O(1)
int RemoveAfter(DoubleLinkedList* const doubleLinkedList, Node* const item, void **data)
{
	if (Size(doubleLinkedList) == 0)
		return -1;

	Node *node;
	if (item == NULL)
	{
		node = doubleLinkedList->tail;
		doubleLinkedList->tail = node->previous;

		if (doubleLinkedList->tail != NULL)
			doubleLinkedList->tail->next = NULL;
	}
	else
	{
		node = item->next;
		item->next = node->next;
		item->next->previous = item;

		if (node->next == NULL)
			doubleLinkedList->tail = item;
	}

	*data = node->data;
	doubleLinkedList->size--;
	doubleLinkedList->Delete(node);

	return 0;
}

// O(1)
int RemoveBefore(DoubleLinkedList* const doubleLinkedList, Node* const item, void **data)
{
	if (Size(doubleLinkedList) == 0)
		return - 1;

	Node *node;
	if (item == NULL)
	{
		node = doubleLinkedList->head;
		doubleLinkedList->head = node->next;

		if (doubleLinkedList->head != NULL)
			doubleLinkedList->head->previous = NULL;
	}
	else
	{
		node = item->previous;
		item->previous = node->previous;
		node->previous->next = item;

		if (node->previous == NULL)
			doubleLinkedList->head = item;
	}

	*data = node->data;
	doubleLinkedList->size--;
	doubleLinkedList->Delete(node);

	return 0;
}

// O(1)
int Size(const DoubleLinkedList* const doubleLinkedList)
{
	return doubleLinkedList->size;
}

// O(n)
Node* GetNode(const DoubleLinkedList* const doubleLinkedList, const void* const data, int(*Compare)(const Node* const node, const void* const data))
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

// O(n)
int Destroy(DoubleLinkedList* const doubleLinkedList, void(*Delete)(void *data))
{
	void *removed;
	while (Size(doubleLinkedList) > 0)
	{
		if ((removed = malloc(sizeof(void))) == NULL)
			return -1;

		if (RemoveAfter(doubleLinkedList, NULL, &removed) == 0)
			Delete(removed);
	}

	free(doubleLinkedList);

	return 0;
}
