#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int* CreateElement(int data);
void Print(const Stack* const stack);
void DeleteNode(Node *data);
void Delete(void *data);

int main(void)
{
    Stack *stack;
    if (Initialize(&stack, DeleteNode) == -1)
        return -1;

    int *value = NULL;
    if ((value = CreateElement(1)) == NULL)
        return -1;
    Push(stack, value);

    if ((value = CreateElement(2)) == NULL)
        return -1;
    Push(stack, value);

    if ((value = CreateElement(3)) == NULL)
        return -1;
    Push(stack, value);

    if (Peek(stack, (void *)&value) == -1)
        return -1;
    printf("Peek: %d\n", *value);

    printf("Stack size: %d\n", Size(stack));
    Print(stack);

    if (Pop(stack, (void *)&value) == -1)
        return -1;
    printf("Pop: %d\n", *value);

    printf("Stack size: %d\n", Size(stack));
    Print(stack);

    if (Destroy(stack, Delete) == -1)
        return -1;
    else
        stack = NULL;

	printf("Stack destroyed");
    return 0;
}

int* CreateElement(int data)
{
    int *value;
    if ((value = (int *)malloc(sizeof(int))) == NULL)
        return NULL;

    *value = data;
    return value;
}

void Print(const Stack* const stack)
{
    printf("List: ");
    Node* member = stack->top;
    while (member != NULL)
    {
        printf("%d ", *(int *)member->data);
        member = member->next;
    }
    printf("\n");
}

void DeleteNode(Node *data)
{
    free(data);
}

void Delete(void *data)
{
    free(data);
}