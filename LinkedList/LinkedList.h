#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdlib.h>

// Struct Definitions
typedef struct Node {
        void *data;
        struct Node *next;
} Node;

typedef struct LinkedList {
        Node *head;
        int size;

        void(*Delete)(Node *node);
} LinkedList;

// Function Definitions
int Initialize(LinkedList **linkedList, void(*Delete)(Node *node));
int InsertAfter(LinkedList* const linkedList, Node* const item, const void* const data);
int RemoveAfter(LinkedList* const linkedList, Node* const item, void **data);
int Size(const LinkedList* const linkedList);
// void ListItem(const LinkedList* const linkedList, void (*Print)(const LinkedList* const linkedList));
Node* GetNode(const LinkedList* const linkedList, const void* const data, int(*Compare)(const Node* const node, const void* const data));
int Destroy(LinkedList* const linkedList, void(*Delete)(void *data));

#endif
