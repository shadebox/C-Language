#include <stdlib.h>
#include "LinkedList.h"

// O(1)
int Initialize(LinkedList **linkedList, void(*Delete)(Node *node))
{
	if ((*linkedList = (LinkedList*)malloc(sizeof(LinkedList))) == NULL)
		return -1;

	(*linkedList)->head = NULL;
	(*linkedList)->size = 0;
	(*linkedList)->Delete = Delete;

	return 1;
}

// O(1)
int InsertAfter(LinkedList* const linkedList, Node* const item, const void* const data)
{
	Node *node;
        if ((node = malloc(sizeof(Node))) == NULL)
            return -1;

        node->data = (void*)data;
        if (item == NULL)
        {
            linkedList->head = node;
        	node->next = NULL;
        }
        else
        {
            node->next = item->next;
            item->next = node;
        }

        linkedList->size++;
        return 0;
}

// O(1)
int RemoveAfter(LinkedList* const linkedList, Node* const item, void **data)
{
	if (Size(linkedList) == 0)
		return -1;

	Node *node;
	if (item == NULL)
	{
		node = linkedList->head;
		linkedList->head = node->next;
	}
	else
	{
		node = item->next;
		if (node != NULL)
			item->next = node->next;
	}

	*data = node->data;
	linkedList->size--;
	linkedList->Delete(node);

	return 0;
}

// O(1)
int Size(const LinkedList* const linkedList)
{
	return linkedList->size;
}

// O(n)
Node* GetNode(const LinkedList* const linkedList, const void* const data, int(*Compare)(const Node* const node, const void* const data))
{
	Node *node = linkedList->head;
	while (node != NULL)
	{
		if (Compare(node, data) == 1)
			return node;
		node = node->next;
	}

	return NULL;
}

// O(n)
int Destroy(LinkedList* const linkedList, void(*Delete)(void *data))
{
	void *remove;
	while (Size(linkedList) > 0)
	{
		if ((remove = malloc(sizeof(void))) == NULL)
			return -1;

		if (RemoveAfter(linkedList, NULL, (void*)&remove) == 0)
			Delete(remove);
	}

	free(linkedList);
	return 0;
}

