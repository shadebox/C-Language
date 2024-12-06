#include <stdlib.h>
#include <errno.h>
#include "Queue.h"

// O(1)
bool Initialize(Queue **queue, void(*Delete)(void *data))
{
    if ((*queue = (Queue *)malloc(sizeof(Queue))) == NULL)
    {
        perror("Error message");
        return false;
    }

    (*queue)->size = 0;
    (*queue)->head = (*queue)-> tail = NULL;
    (*queue)->Delete = Delete;

    return true;
}

// O(1)
bool Enqueue(Queue* const queue, const void* const data)
{
    Node *member = NULL;
    if ((member = (Node*)malloc(sizeof(Node))) == NULL)
    {
        perror("Error message");
        return false;
    }

    member->data = (void*)data;
    member->next = NULL;
    if (Size(queue) == 0)
    {
        queue->head = queue->tail = member;
    }
    else
    {
        queue->tail->next = member;
        queue->tail = member;
    }

    queue->size++;
    return true;
}

// O(1)
bool Peek(const Queue* const queue, const void **data)
{
    if (Size(queue) == 0)
        return false;

    *data = queue->head->data;
    return true;
}

// O(1)
bool Dequeue(Queue* const queue, const void **data)
{
    if (Size(queue) == 0)
        return false;

    Node *member = queue->head;
    *data = member->data;

    queue->head = member->next;
    queue->size--;
    free(member);

    return true;
}

// O(1)
bool IsEmpty(const Queue* const queue)
{
    if (Size(queue) == 0)
        return true;
    else
        return false;
}

// O(1)
int Size(const Queue* const queue)
{
    return queue->size;
}

// O(n)
bool Destroy(Queue** queue)
{
    void *remove = NULL;
    while (Size(*queue) > 0)
    {
        if ((remove = malloc(sizeof(void))) == NULL)
        {
            perror("Error message");
            return false;
        }

        if (Dequeue(*queue, (void*)&remove) == true)
            (*queue)->Delete(remove);
    }

    free(*queue);
    *queue = NULL;

    return true;
}