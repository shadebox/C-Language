#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int* CreateElement(int data);
void Print(const Queue* const queue);
void Delete(void *data);

int main(void)
{
    Queue* queue;

    if ((queue = Initialize()) == NULL)
        return -1;

    int *value = NULL;
    if ((value = CreateElement(1)) == NULL)
        return -1;
    Enqueue(queue, value);

    value = NULL;
    if ((value = CreateElement(2)) == NULL)
        return -1;
    Enqueue(queue, value);

    value = NULL;
    if ((value = CreateElement(3)) == NULL)
        return -1;
    Enqueue(queue, value);

    if(Peek(queue, (void*)&value) == -1)
        return -1;
    printf("Peek: %d\n", *value);

    if ((value = CreateElement(4)) == NULL)
        return -1;
    Enqueue(queue, value);
    
    ListItem(queue, Print);

    if (Dequeue(queue, (void *)&value) == -1)
        return -1;
    printf("Dequeue: %d\n", *value);

    printf("Queue size: %d\n", Size(queue));
    ListItem(queue, Print);

    if (Destroy(queue, Delete) == -1)
        return -1;
    else
        queue = NULL;

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
    printf("List: ");
    Node* member = queue->head;
    while (member != NULL)
    {
        printf("%d ", *(int *)member->data);
        member = member->next;
    }
    printf("\n");
}

void Delete(void *data)
{
    free(data);
}