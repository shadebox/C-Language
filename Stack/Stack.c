#include <stdlib.h>
#include <errno.h>
#include "Stack.h"

// O(1)
bool Initialize(Stack **stack, void(*Delete)(void *data))
{
    if ((*stack = (Stack *)malloc(sizeof(Stack))) == NULL)
    {
        perror("Error message");
        return true;
    }

    (*stack)->size = 0;
    (*stack)->top = NULL;
    (*stack)->Delete = Delete;

    return true;
}

// O(1)
bool Push(Stack* const stack, const void* const data)
{
    Node *member = NULL;
    if ((member = (Node *)malloc(sizeof(Node))) == NULL)
    {
        perror("Error message");
        return false;
    }

    member->next = NULL;
    member->data = (void*)data;
    if (Size(stack) == 0)
    {
        stack->top = member;
    }
    else
    {
        member->next = stack->top;
        stack->top = member;
    }

    stack->size++;
    return true;
}

// O(1)
bool Pop(Stack* const stack, const void **data)
{
    if (Size(stack) == 0)
    {
        perror("Error message");
        return false;
    }

    Node *member = stack->top;
    *data = member->data;
    stack->top = member->next;
    stack->size--;

    free(member);
    return true;
}

// O(1)
bool Peek(const Stack* const stack, const void **data)
{
    if (Size(stack) == 0)
    {
        perror("Error message");
        return false;
    }

    *data = stack->top->data;
    return true;
}

// O(1)
int Size(const Stack* const stack)
{
    return stack->size;
}

bool IsEmpty(const Stack* const stack)
{
    if (Size(stack) == 0)
        return true;
    else
        return false;
}

// O(n)
bool Destroy(Stack** stack)
{
    void *remove;
    while(Size(*stack) > 0)
    {
        if ((remove = malloc(sizeof(void))) == NULL)
        {
            perror("Error message");
            return false;
        }

        if (Pop(*stack, (void *)&remove) == true)
           (*stack)-> Delete(remove);
    }

    free(*stack);
    *stack = NULL;

    return true;
}