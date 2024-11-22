#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST

#include <stdlib.h>

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
} DoubleLinkedList;

// Function Definition
DoubleLinkedList* Initialize();
int InsertBefore(DoubleLinkedList* const doubleLinkedList, Node* const item, const void* const data);
int InsertAfter(DoubleLinkedList* const doubleLinkedList, Node* const item, const void* const data);
int RemoveAfter(DoubleLinkedList* const doubleLinkedList, Node* const item, void **data);
int RemoveBefore(DoubleLinkedList* const doubleLinkedList, Node* const item, void **data);
int Size(const DoubleLinkedList* const doubleLinkedList);
void ListItem(const DoubleLinkedList* const doubleLinkedList, void(*Print)(const DoubleLinkedList* const doubleLinkedList));
Node* GetNode(const DoubleLinkedList* const doubleLinkedList, const void* const data, int(Compare)(const Node* const node, const void* const data));
int Destroy(DoubleLinkedList* const doubleLinkedList, void(*Delete)(void *data));

#endif
