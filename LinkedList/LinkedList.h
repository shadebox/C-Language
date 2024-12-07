#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdlib.h>
#include <stdbool.h>

// Struct Definitions
typedef struct Node {
        void *data;
        struct Node *next;
} Node;

typedef struct LinkedList {
        Node *head;
        int size;

        void(*Delete)(void *data);
        bool(*Compare)(const Node* const member, const void* const data);
} LinkedList;

// Function Definitions
bool Initialize(LinkedList **linkedList, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data));
bool InsertAtFront(LinkedList* const linkedList, const void* const data);
bool InsertAtEnd(LinkedList* const linkedList, const void* const data);
bool InsertAfter(LinkedList* const linkedList, Node* const item, const void* const data);
bool RemoveAtFront(LinkedList* const linkedList, void **data);
bool RemoveAtEnd(LinkedList* const linkedList, void **data);
bool RemoveAfter(LinkedList* const linkedList, Node* const item, void **data);
int Size(const LinkedList* const linkedList);
Node* GetNode(const LinkedList* const linkedList, const void* const data);
bool Destroy(LinkedList **linkedList);

#endif
