#include <stdlib.h>
#include "Stack.h"

// O(1)
int Initialize(Stack **stack, void(*Delete)(Node *node))
{
    if ((*stack = (Stack *)malloc(sizeof(Stack))) == NULL)
        return -1;

    (*stack)->size = 0;
    (*stack)->top = NULL;
    (*stack)->Delete = Delete;

    return 1;
}

// O(1)
int Push(Stack* const stack, const void* const data)
{
    Node *node;
    if ((node = (Node *)malloc(sizeof(Node))) == NULL)
        return -1;

    node->next = NULL;
    if (stack->top == NULL)
    {
        stack->top = node;
    }
    else
    {
        node->next = stack->top;
        stack->top = node;
    }

    node->data = (void *)data;
    stack->size++;

    return 0;
}

// O(1)
int Pop(Stack* const stack, const void **data)
{
    if (Size(stack) == 0)
        return -1;

    Node *member = stack->top;
    *data = member->data;

    stack->top = member->next;
    stack->size--;
    stack->Delete(member);

    return 0;
}

// O(1)
int Peek(const Stack* const stack, const void **data)
{
    if (Size(stack) == 0)
        return -1;

    *data = stack->top->data;
    return 0;
}

// O(1)
int Size(const Stack* const stack)
{
    return stack->size;
}

int Destroy(Stack* const stack, void (*Delete)(void *data))
{
    void *remove;
    while(Size(stack) > 0)
    {
        if ((remove = malloc(sizeof(void))) == NULL)
            return -1;

        if (Pop(stack, (void *)&remove) == 0)
            Delete(remove);
    }
    return 0;
}