#ifndef SET_HEADER
#define SET_HEADER

// Struct Definition
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Set {
    size_t size;
    Node *head;
    Node *tail;

    void(*Delete)(Node *data);
} Set;

// Function Definition
int Initialize(Set **set, void(*Delete)(Node *data));
int IsMember(const Set* const set, const void* const data, int(*Compare)(const Node* const node, const void* const data));
int CreateNode(Set* const set, void *data);
int Insert(Set* const set, void *data, int(*Compare)(const Node* const node, const void* const data));
int Remove(Set* const set, const void* const remove, void **data, int(*Compare)(const Node* const node, const void* const data));
Set* Union(const Set* const setA, const Set* const setB, Set *set, int(*Compare)(const Node* const node, const void* const data));
Set* Intersection(const Set* const setA, const Set* const setB, Set *set, int(*Compare)(const Node* const node, const void* const data));
Set* Difference(const Set* const setA, const Set* const setB, Set *set, int(*Compare)(const Node* const node, const void* const data));
int IsSubSet(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data));
int IsEqual(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data));
int Size(const Set* const set);
int Destroy(Set* const set, int(*Compare)(const Node* const node, const void* const data), void(*Delete)(void *data));

#endif