#ifndef QUEUE_HEADER
#define QUEUE_HEADER

// Struct Definition
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Queue {
    int size;
    Node* head;
    Node* tail;
} Queue;

// Function Definitions
Queue* Initialize();
int Enqueue(Queue* const queue, const void* const data);
int Peek(const Queue* const queue, const void **data);
int Dequeue(Queue* const queue, const void **data);
int Size(const Queue* const queue);
void ListItem(const Queue* const queue, void(*Print)(const Queue* const queue));
int Destroy(Queue* const queue, void(*Delete)(void *data));

#endif

