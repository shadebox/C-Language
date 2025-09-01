#ifndef __LINKEDLIST__
#define __LINKEDLIST__

// #include <stdlib.h>
#include <stdbool.h>
#include "../Node/Node.h"

// Struct Definitions
typedef struct LinkedList {
	int size;
	Node *head;

	bool(*Compare)(const Node* const member, const NodeData const data);
	bool(*Delete)(NodeData data);
} LinkedList;

// Function Definitions
bool InitializeLinkedList(LinkedList **linkedList, bool(*Compare)(const Node* const member, const NodeData const data), bool(*Delete)(NodeData data));
bool InsertAtFront(LinkedList* const linkedList, const NodeData const data);
bool InsertAtEnd(LinkedList* const linkedList, const NodeData const data);
// bool InsertAfter(LinkedList* const linkedList, Node* const item, const void* const data);
// bool RemoveAtFront(LinkedList* const linkedList, void **data);
// bool RemoveAtEnd(LinkedList* const linkedList, void **data);
// bool RemoveAfter(LinkedList* const linkedList, Node* const item, void **data);
// Node* GetNode(const LinkedList* const linkedList, const void* const data);
bool DestroyLinkedList(LinkedList **linkedList);

#endif
