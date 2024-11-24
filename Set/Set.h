#ifndef SET_HEADER
#define SET_HEADER

// Struct Definition
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Set {
    int size;
    Node *head;
    Node *tail;
} Set;

// Function Definition
Set* Initialize();
int IsMember(const Set* const set, const void* const data, int(*Compare)(const Node* const node, const void* const data));
int CreateNode(Set* const set, void *data);
int Insert(Set* const set, void *data, int(*Compare)(const Node* const node, const void* const data));
int Remove(Set* const set, const void* const data, int(*Compare)(const Node* const node, const void* const data), void(*Delete)(void *data));
Set* Union(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data));
Set* Intersection(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data));
Set* Difference(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data));
int IsSubSet(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data));
int IsEqual(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data));
void ListItem(const Set* const set, void(*Print)(const Set* const set));
int Size(const Set* const set);
int Destroy(Set* const set, int(*Compare)(const Node* const node, const void* const data), void(*Delete)(void *data));

// Algorithms
Set* Cover(Set* const member, Set* const subsets);

#endif