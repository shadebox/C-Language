#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST

#include <stdlib.h>
#include <stdbool.h>

// Struct Definition
typedef struct Node {
	void *data;
	struct Node *next;
	struct Node *previous;
} Node;

typedef struct DoubleLinkedList {
	Node *head;
	Node *tail;
	int size;

	void(*Delete)(void *data);
} DoubleLinkedList;

// Function Definition
bool Initialize(DoubleLinkedList**, void(*Delete)(void *data));
bool InsertAtFront(DoubleLinkedList* const doubleLinkedList, const void* const data);
bool InsertAtEnd(DoubleLinkedList* const doubleLinkedList, const void* const data);
bool InsertBefore(DoubleLinkedList* const doubleLinkedList, Node* const item, const void* const data);
bool InsertAfter(DoubleLinkedList* const doubleLinkedList, Node* const item, const void* const data);
bool RemoveAtFront(DoubleLinkedList* const doubleLinkedList, void** data);
bool RemoveAtEnd(DoubleLinkedList* const doubleLinkedList, void** data);
bool RemoveAfter(DoubleLinkedList* const doubleLinkedList, Node* const item, void **data);
bool RemoveBefore(DoubleLinkedList* const doubleLinkedList, Node* const item, void **data);
int Size(const DoubleLinkedList* const doubleLinkedList);
Node* GetNode(const DoubleLinkedList* const doubleLinkedList, const void* const data, bool(*Compare)(const Node* const member, const void* const data));
bool Destroy(DoubleLinkedList** doubleLinkedList);

#endif
