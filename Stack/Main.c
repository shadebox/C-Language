#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int* CreateElement(int data);
void Print(const Stack* const stack);
void DeleteInteger(void *data);

int main(void)
{
    Stack *stack;
    if (Initialize(&stack, DeleteInteger) == false)
        return -1;

    int *value = NULL;
    if ((value = CreateElement(1)) == NULL)
        return -1;

    if (Push(stack, value) == false)
        return -1;

    if ((value = CreateElement(2)) == NULL)
        return -1;

    if (Push(stack, value) == false)
        return -1;

    if ((value = CreateElement(3)) == NULL)
        return -1;
    
    if (Push(stack, value) == false)
        return -1;

    if (IsEmpty(stack) == false)
        Print(stack);
    
    if (Peek(stack, (void *)&value) == false)
        return -1;
    
    printf("Peek: %d\n", *value);

    if (Pop(stack, (void *)&value) == false)
        return -1;
    
    printf("Pop: %d\n", *value);

    if (IsEmpty(stack) == false)
        Print(stack);

    if (Destroy(&stack) == false)
        return -1;

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
    printf("Stack size: %d\n", Size(stack));

    printf("List: ");
    Node* member = stack->top;
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
    free((int*)data);
	data = NULL;;
}