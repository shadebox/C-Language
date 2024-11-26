#include <stdlib.h>
#include "Queue.h"

// O(1)
int Initialize(Queue **queue, void(*Delete)(Node *data))
{
    if ((*queue = (Queue *)malloc(sizeof(Queue))) == NULL)
        return -1;

    (*queue)->size = 0;
    (*queue)->head = (*queue)-> tail = NULL;
    (*queue)->Delete = Delete;

    return 1;
}

// O(1)
int Enqueue(Queue* const queue, const void* const data)
{
    Node *node = NULL;
    if ((node = (Node*)malloc(sizeof(Node))) == NULL)
        return -1;

    if (Size(queue) == 0)
    {
        queue->head = queue->tail = node;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = node;
    }

    node->data = (void*)data;
    node->next = NULL;
    queue->size++;

    return 0;
}

// O(1)
int Peek(const Queue* const queue, const void **data)
{
    if (Size(queue) == 0)
        return -1;

    *data = queue->head->data;
    return 0;
}

// O(1)
int Dequeue(Queue* const queue, const void **data)
{
    if (Size(queue) == 0)
        return -1;

    Node *member = queue->head;
    *data = member->data;

    queue->head = member->next;
    queue->size--;
    queue->Delete(member);

    return 0;
}

// O(1)
int Size(const Queue* const queue)
{
    return queue->size;
}

int Destroy(Queue* const queue, void(*Delete)(void *data))
{
    void *remove = NULL;
    while (Size(queue) > 0)
    {
        if ((remove = malloc(sizeof(void))) == NULL)
            return -1;

        if (Dequeue(queue, (void*)&remove) == 0)
            Delete(remove);
    }

    return 0;
}