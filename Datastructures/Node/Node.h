#ifndef __NODE__
#define __NODE__

// Data Definition
typedef void * NodeData;

// Struct Definition
typedef struct _Node {
    NodeData data;
    struct _Node *next;
    struct _Node *previous;
} Node;

#endif