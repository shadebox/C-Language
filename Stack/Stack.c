#include <stdlib.h>
#include "Stack.h"

// O(1)
Stack* Initialize()
{
    Stack *stack;
    if ((stack = (Stack *)malloc(sizeof(Stack))) == NULL)
        return NULL;

    stack->size = 0;
    stack->top = NULL;

    return stack;
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

    free(member);
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

// O(Print())
void ListItem(const Stack* const stack, void (*Print)(const Stack* const stack))
{
    Print(stack);
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