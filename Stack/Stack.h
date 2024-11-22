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
} Stack;

// Function Definition
Stack* Initialize();
int Push(Stack *stack, const void *data);
int Pop(Stack *stack, void **data);
int Peek(const Stack const *stack, void **data);
int Size(const Stack const *stack);
void ListItem(const Stack const *stack, void (*Print)(const Stack const *stack));
int Destroy(Stack *stack, void (*Delete)(void *data));

#endif