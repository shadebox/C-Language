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
int InsertBefore(DoubleLinkedList *doubleLinkedList, Node *item, const void *data);
int InsertAfter(DoubleLinkedList *doubleLinkedList, Node *item, const void *data);
int RemoveAfter(DoubleLinkedList *doubleLinkedList, Node *item, void **data);
int RemoveBefore(DoubleLinkedList *doubleLinkedList, Node *item, void **data);
int Size(const DoubleLinkedList const *doubleLinkedList);
void ListItem(const DoubleLinkedList const *doubleLinkedList, void(*Print)(const DoubleLinkedList const *doubleLinkedList));
Node* GetNode(const DoubleLinkedList const *doubleLinkedList, const void const *data, int(Compare)(const Node const *node, const void const *data));
int Destroy(DoubleLinkedList *doubleLinkedList, int(*Delete)(void *data));

#endif
