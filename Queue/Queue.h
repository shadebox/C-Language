#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stdbool.h>

// Struct Definition
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Queue {
    int size;
    Node* head;
    Node* tail;

    void(*Delete)(void *data);
} Queue;

// Function Definitions
bool Initialize(Queue **queue, void(*Delete)(void *data));
bool Enqueue(Queue* const queue, const void* const data);
bool Peek(const Queue* const queue, const void **data);
bool Dequeue(Queue* const queue, const void **data);
bool IsEmpty(const Queue* const queue);
int Size(const Queue* const queue);
bool Destroy(Queue** queue);

#endif

