#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include "LinkedList.h"

// O(1)
bool Initialize(LinkedList **linkedList, void(*Delete)(void *data))
{
	if ((*linkedList = (LinkedList*)malloc(sizeof(LinkedList))) == NULL)
	{
		perror("Error message");
		return false;
	}

	(*linkedList)->head = NULL;
	(*linkedList)->size = 0;
	(*linkedList)->Delete = Delete;

	return true;
}

// O(1)
bool InsertAtFront(LinkedList* const linkedList, const void* const data)
{
	Node *member = NULL;
	if ((member = (Node*)malloc(sizeof(Node))) == NULL)
	{
		perror("Error message");
		return false;
	}

	member->data = (void*)data;
	member->next = NULL;
	if (Size(linkedList) == 0)
	{
		linkedList->head = member;
	}
	else
	{
		member->next = linkedList->head;
		linkedList->head = member;
	}

	linkedList->size++;
	return true;
}

// O(n)
bool InsertAtEnd(LinkedList* const linkedList, const void* const data)
{
	Node *member = NULL;
	if ((member = (Node*)malloc(sizeof(Node))) == NULL)
	{
		perror("Error message");
		return false;
	}

	member->data = (void*)data;
	member->next = NULL;
	if (Size(linkedList) == 0)
	{
		linkedList->head = member;
	}
	else
	{
		Node *temp = linkedList->head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = member;
	}

	linkedList->size++;
	return true;
}

// O(1)
bool InsertAfter(LinkedList* const linkedList, Node* const item, const void* const data)
{
	Node *member = NULL;
    if ((member = malloc(sizeof(Node))) == NULL)
    {
		perror("Error message");
		return false;
	}

    member->data = (void*)data;
	member->next = NULL;
    if (item == NULL)
	{
		perror("Error message");
		return false;
	}
	else
	{
		member->next = item->next;
		item->next = member;
	}

	linkedList->size++;
	return true;
}

// O(1)
bool RemoveAtFront(LinkedList* const linkedList, void **data)
{
	if (Size(linkedList) == 0)
	{
		perror("Error message");
		return false;
	}
	else
	{
		Node *member = linkedList->head;
		linkedList->head = member->next;
		linkedList->size--;
		*data = member->data;
		
		free(member);
		return true;
	}
}

// O(n)
bool RemoveAtEnd(LinkedList* const linkedList, void **data)
{
	Node *member = linkedList->head;
	if (Size(linkedList) == 0)
	{
		perror("Error message");
		return false;
	}
	else if (member->next == NULL)
	{
		*data = member->data;
		linkedList->head = member->next;
		linkedList->size--;
		free(member);
	}
	else
	{
		while (member->next->next != NULL)
			member = member->next;

		Node *remove = member->next;
		member->next = NULL;
		*data = remove->data;
		linkedList->size--;
		free(remove);
	}

	return true;
}

// O(1)
bool RemoveAfter(LinkedList* const linkedList, Node* const item, void **data)
{
	if (Size(linkedList) == 0)
	{
		perror("Error message");
		return false;
	}

	Node *member = NULL;
	if (item == NULL)
	{
		member = linkedList->head;
		*data = member->data;
		linkedList->head = member->next;
	}
	else if (item->next == NULL)
	{
		return false;
	}
	else
	{
		member = item->next;
		item->next = member->next;
		*data = member->data;
	}

	linkedList->size--;
	free(member);

	return true;
}

// O(1)
int Size(const LinkedList* const linkedList)
{
	return linkedList->size;
}

// O(n)
Node* GetNode(const LinkedList* const linkedList, const void* const data, int(*Compare)(const Node* const member, const void* const data))
{
	Node *member = linkedList->head;
	while (member != NULL)
	{
		if (Compare(member, data) == 1)
			return member;
		member = member->next;
	}

	return NULL;
}

// O(n)
bool Destroy(LinkedList** const linkedList)
{
	void *remove;
	while (Size(*linkedList) > 0)
	{
		if ((remove = malloc(sizeof(void))) == NULL)
		{
			perror("Error message");
			return false;
		}

		if (RemoveAfter(*linkedList, NULL, (void*)&remove) == 1)
			(*linkedList)->Delete(remove);
	}

	free(*linkedList);
	*linkedList = NULL;

	return true;
}

