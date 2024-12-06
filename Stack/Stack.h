#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdbool.h>

// Struct Definition
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;

    void(*Delete)(void *data);
} Stack;

// Function Definition
bool Initialize(Stack **stack, void(*Delete)(void *data));
bool Push(Stack* const stack, const void* const data);
bool Pop(Stack* const stack, const void **data);
bool Peek(const Stack* const stack, const void **data);
int Size(const Stack* const stack);
bool IsEmpty(const Stack* const stack);
bool Destroy(Stack **stack);

#endif