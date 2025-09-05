#include <stdlib.h>
#include <errno.h>
#include "LinkedList.h"

// O(1)
bool InitializeLinkedList(LinkedList **linkedList, bool(*Compare)(const Node* const member, const NodeData const data), bool(*Delete)(NodeData data))
{
	if ((*linkedList = (LinkedList*)malloc(sizeof(LinkedList))) == NULL)
	{
		perror("Error message");
		return false;
	}

	(*linkedList)->head = NULL;
	(*linkedList)->size = 0;
	(*linkedList)->Compare = Compare;
	(*linkedList)->Delete = Delete;

	return true;
}

// O(1)
bool InsertAtFront(LinkedList* const linkedList, const NodeData const data)
{
	Node *member = NULL;
	if ((member = (Node*)malloc(sizeof(Node))) == NULL)
	{
		perror("Error message");
		return false;
	}

	member->data = (NodeData)data;
	member->next = NULL;

	if (linkedList->size > 0)
		member->next = linkedList->head;

	linkedList->head = member;
	linkedList->size++;
	return true;
}

// O(n)
bool InsertAtEnd(LinkedList* const linkedList, const NodeData const data)
{
	Node *member = NULL;
	if ((member = (Node*)malloc(sizeof(Node))) == NULL)
	{
		perror("Error message");
		return false;
	}

	member->data = (NodeData)data;
	member->next = NULL;

	if (linkedList->size > 0)
	{
		Node *temp = linkedList->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = member;
	}
	else
	{
		linkedList->head = member;
	}
	
	linkedList->size++;
	return true;
}

/*bool InsertAtEnd(LinkedList* const linkedList, const void* const data)
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
		return false;

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

// O(n)
Node* GetNode(const LinkedList* const linkedList, const void* const data)
{
	Node *member = linkedList->head;
	while (member != NULL)
	{
		if (linkedList->Compare(member, data) == true)
			return member;
		member = member->next;
	}

	return NULL;
}*/

// O(n)
bool DestroyLinkedList(LinkedList** linkedList)
{
	if (*linkedList == NULL)
		return true;

	while ((*linkedList)->size > 0)
	{

	}
	
	free(*linkedList);
	*linkedList = NULL;

	return true;

	/*NodeData remove;
	while ((*linkedList)->size > 0)
	{
		if ((remove = malloc(sizeof(void))) == NULL)
		{
			perror("Error message");
			return false;
		}

		if (RemoveAfter(*linkedList, NULL, (void*)&remove) == true)
			(*linkedList)->Delete(remove);
	}*/
}

