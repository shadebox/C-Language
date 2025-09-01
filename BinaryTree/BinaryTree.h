#ifndef BINARYTREE
#define BINARYTREE

#include <stdlib.h>
#include <stdbool.h>

// Struct Definition
typedef struct BinaryTreeNode {
    void *data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    
} BinaryTreeNode;

typedef struct BinaryTree {
    BinaryTreeNode *root;
    int BinaryTreeSize;

    bool(*Delete)(void *data);
    bool(*Compare)(const BinaryTreeNode* const member, const void* const data);
} BinaryTree;

// Function Definition
bool InitializeBinaryTree(BinaryTree **binaryTree, bool(*Compare)(const BinaryTreeNode* const member, const void* const data), void(*Delete)(void *data));
bool DestroyBinaryTree(BinaryTree **binaryTree);

#endif