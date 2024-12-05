#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "DoubleLinkedList.h"

// Function Definition

// O(1)
bool Initialize(DoubleLinkedList **doubleLinkedList, void(*Delete)(void *data))
{
	if ((*doubleLinkedList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList))) == NULL)
	{
		perror("Error message");
		return false;
	}

	(*doubleLinkedList)->head = NULL;
	(*doubleLinkedList)->tail = NULL;
	(*doubleLinkedList)->size = 0;
	(*doubleLinkedList)->Delete = Delete;

	return true;
}

// O(1)
bool InsertAtFront(DoubleLinkedList* const doubleLinkedList, const void* const data)
{
	Node *member = NULL;
	if ((member = (Node*)malloc(sizeof(Node))) == NULL)
	{
		perror("Error message");
		return false;
	}

	member->data = (void*)data;
	member->previous = NULL;
	if (Size(doubleLinkedList) == 0)
	{
		doubleLinkedList->head = doubleLinkedList->tail = member;
		member->next = NULL;
	}
	else
	{
		member->next = doubleLinkedList->head;
		doubleLinkedList->head->previous = member;
		doubleLinkedList->head = member;
	}

	doubleLinkedList->size++;
	return true;
}

// O(1)
bool InsertAtEnd(DoubleLinkedList* const doubleLinkedList, const void* const data)
{
	Node *member = NULL;
	if ((member = (Node*)malloc(sizeof(Node))) == NULL)
	{
		perror("Error message");
		return false;
	}
	
	member->data = (void*)data;
	member->next = NULL;
	if (Size(doubleLinkedList) == 0)
	{
		doubleLinkedList->head = doubleLinkedList->tail = member;
		member->previous = NULL;
	}
	else
	{
		member->previous = doubleLinkedList->tail;
		doubleLinkedList->tail->next = member;
		doubleLinkedList->tail = member;
	}

	doubleLinkedList->size++;
	return true;
}

// O(1)
bool InsertBefore(DoubleLinkedList* const doubleLinkedList, Node* const item, const void* const data)
{
	if (item == NULL)
	{
		return InsertAtFront(doubleLinkedList, data);
	}
	else
	{
		Node *member = NULL;
		if ((member = (Node *)malloc(sizeof(Node))) == NULL)
		{
			perror("Error message");
			return false;
		}

		
		member->data = (void *)data;
		member->previous = item->previous;
		member->next = item;
		item->previous = member;

		doubleLinkedList->size++;
		if (member->previous == NULL)
			doubleLinkedList->head = member;
		else
			member->previous->next = member;
		
		return true;
	}
}

// O(1)
bool InsertAfter(DoubleLinkedList* const doubleLinkedList, Node* const item, const void* const data)
{
	if (item == NULL)
	{
		return InsertAtEnd(doubleLinkedList, data);
	}
	else
	{
		Node *member = NULL;
		if ((member = (Node *)malloc(sizeof(Node))) == NULL)
		{
			perror("Error message");
			return false;
		}

		member->data = (void *)data;
		member->next = item->next;
		item->next = member;
		member->previous = item;

		doubleLinkedList->size++;
		if (member->next == NULL)
			doubleLinkedList->tail = member;

		return true;
	}
}

// O(1)
bool RemoveAtFront(DoubleLinkedList* const doubleLinkedList, void** data)
{
	if (Size(doubleLinkedList) == 0)
		return false;

	Node *member = doubleLinkedList->head;
	*data = (void*)member->data;
	doubleLinkedList->head = member->next;
	doubleLinkedList->head->previous = NULL;
	doubleLinkedList->size--;

	if (Size(doubleLinkedList) == 0)
		doubleLinkedList->tail = NULL;

	free(member);
	return true;
}

// O(1)
bool RemoveAtEnd(DoubleLinkedList* const doubleLinkedList, void** data)
{
	if (Size(doubleLinkedList) == 0)
		return false;

	Node *member = doubleLinkedList->tail;
	*data = (void*)member->data;
	doubleLinkedList->tail = member->previous;
	doubleLinkedList->size--;

	if (doubleLinkedList->tail != NULL)
		doubleLinkedList->tail->next = NULL;

	if (Size(doubleLinkedList) == 0)
		doubleLinkedList->head = NULL;

	free(member);
	return true;
}

// O(1)
bool RemoveAfter(DoubleLinkedList* const doubleLinkedList, Node* const item, void **data)
{
	if (Size(doubleLinkedList) == 0)
		return false;
	
	if (item == NULL)
	{
		return RemoveAtEnd(doubleLinkedList, data);
	}
	else
	{
		Node *member = item->next;
		if (member == NULL)
			return false;

		*data = (void*)member->data;
		item->next = member->next;
		doubleLinkedList->size--;

		if (item->next != NULL)
			item->next->previous = item;
		else
			doubleLinkedList->tail = item;

		free(member);
		return true;
	}
}

// O(1)
bool RemoveBefore(DoubleLinkedList* const doubleLinkedList, Node* const item, void **data)
{
	if (Size(doubleLinkedList) == 0)
		return false;

	if (item == NULL)
	{
		return RemoveAtFront(doubleLinkedList, data);
	}
	else
	{
		Node *member = item->previous;
		if (member == NULL)
			return false;

		*data = (void*)member->data;
		item->previous = member->previous;
		doubleLinkedList->size--;

		if (item->previous != NULL)
			item->previous->next = item;
		else
			doubleLinkedList->head = item;
		
		free(member);
		return true;
	}
}

// O(1)
int Size(const DoubleLinkedList* const doubleLinkedList)
{
	return doubleLinkedList->size;
}

// O(n)
Node* GetNode(const DoubleLinkedList* const doubleLinkedList, const void* const data, int(*Compare)(const Node* const member, const void* const data))
{
	Node *member = doubleLinkedList->head;
	while (member != NULL)
	{
		if (Compare(member, data) == 1)
			return member;
		member = member->next;
	}

	return NULL;
}

// O(n)
bool Destroy(DoubleLinkedList** doubleLinkedList)
{
	void *removed = NULL;
	while (Size(*doubleLinkedList) > 0)
	{
		if ((removed = malloc(sizeof(void))) == NULL)
		{
			perror("Error message");
			return false;
		}

		if (RemoveAfter(*doubleLinkedList, NULL, &removed) == true)
			(*doubleLinkedList)->Delete(removed);
		else
			return false;
	}

	free(*doubleLinkedList);
	*doubleLinkedList = NULL;

	return true;
}
