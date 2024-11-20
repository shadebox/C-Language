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
} LinkedList;

// Function Definitions
LinkedList* Initialize();
int InsertAfter(LinkedList *linkedList, Node *item, const void *data);
int RemoveAfter(LinkedList *linkedList, Node *item, void **data);
int Size(const LinkedList const *linkedList);
void ListItem(const LinkedList const *linkedList, void (*Print)(const LinkedList const *linkedList));
Node* GetNode(const LinkedList *linkedList, const void const *data, int(Compare)(const Node const *node, const void const *data));
int Destroy(LinkedList *linkedList, void (*Delete)(void *data));

#endif
