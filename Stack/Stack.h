#ifndef STACK_HEADER
#define STACK_HEADER

// Struct Definition
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;

    void(*Delete)(Node *node);
} Stack;

// Function Definition
int Initialize(Stack **stack, void(*Delete)(Node *node));
int Push(Stack* const stack, const void* const data);
int Pop(Stack* const stack, const void **data);
int Peek(const Stack* const stack, const void **data);
int Size(const Stack* const stack);
int Destroy(Stack* const stack, void (*Delete)(void *data));

#endif