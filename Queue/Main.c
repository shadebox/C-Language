#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int* CreateElement(int data);
void Print(const Queue* const queue);
void DeleteInteger(void *data);

int main(void)
{
    Queue* queue;

    if (Initialize(&queue, DeleteInteger) == false)
        return -1;

    int *value = NULL;
    if ((value = CreateElement(1)) == NULL)
        return -1;
    
    if (Enqueue(queue, value) == false)
        return -1;

    if ((value = CreateElement(2)) == NULL)
        return -1;
    
    if (Enqueue(queue, value) == false)
        return -1;

    if ((value = CreateElement(3)) == NULL)
        return -1;
    
    if (Enqueue(queue, value) == false)
        return -1;

    Print(queue);

    if (Dequeue(queue, (void*)&value) == false)
        return -1;

    printf("Dequeue: %d\n", *value);

    if (Peek(queue, (void*)&value) == true)
        printf("Peek value: %d\n", *value);

    Print(queue);

    if (Destroy(&queue) == false)
        return -1;

	printf("Stack destroyed");

    return 0;
}

int* CreateElement(int data)
{
    int* value;
    if ((value = (int*)malloc(sizeof(int))) == NULL)
        return NULL;

    *value = data;
    return value;
}

void Print(const Queue* const queue)
{
    printf("Queue size: %d\n", Size(queue));

    printf("List: ");
    Node* member = queue->head;
    while (member != NULL)
    {
        printf("%d ", *(int *)member->data);
        member = member->next;
    }
    printf("\n");
}

void DeleteInteger(void *data)
{
    printf("Deleting %d ...\n", *(int*)data);
    free(data);
    data = NULL;
}