#include <stdlib.h>
#include "Set.h"

// O(1)
Set* Initialize()
{
    Set *set = NULL;
    if ((set = (Set*)malloc(sizeof(Set))) == NULL)
        return NULL;

    set->head = set->tail = NULL;
    set->size = 0;

    return set;
}

// O(n)
int IsMember(const Set* const set, const void* const data, int(*Compare)(const Node* const node, const void* const data))
{
    Node *member = set->head;
    while (member != NULL)
    {
        if (Compare(member, data) == 1)
            return 1;
        member = member->next;
    }

    return 0;
}

// O(1)
int CreateNode(Set* const set, void *data)
{
    Node *member = NULL;
    if ((member = (Node*)malloc(sizeof(Node))) == NULL)
        return -1;
    
    member->data = (void*)data;
    member->next = NULL;

    if (Size(set) == 0)
    {
        set->head = set->tail = member;
    }
    else
    {
        set->tail->next = member;
        set->tail = member;
    }

    set->size++;
    return 0;
}

// O(n)
int Insert(Set* const set, void *data, int(*Compare)(const Node* const node, const void* const data))
{
    if (IsMember(set, data, Compare) == 1)
        return 0;

    return CreateNode(set, data);
}

// O(n)
int Remove(Set* const set, const void* const data, int(*Compare)(const Node* const node, const void* const data), void(*Delete)(void *data))
{
    if (Size(set) == 0)
        return -1;

    Node *member, *previous;
    member = previous = set->head;
    while (member != NULL)
    {
        if (Compare(member, data) == 1)
        {
            if (previous != NULL && previous != member)
                previous->next = member->next;
            else
                set->head = member->next;

            set->size--;
            Delete(member->data);
            free(member);
            return 1;
        }

        previous = member;
        member = member->next;
    }

    return 0;
}

// O(n*m)
Set* Union(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data))
{
    Set *set = NULL;
    if ((set = Initialize()) == NULL)
        return NULL;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (CreateNode(set, member->data) == -1)
            return NULL;
        member = member->next;
    }
    
    member = setB->head;
    while (member != NULL)
    {
        Insert(set, member->data, Compare);
        member = member->next;
    }

    return set;
}

// O(n*m)
Set* Intersection(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data))
{
    Set *set = NULL;
    if ((set = Initialize()) == NULL)
        return NULL;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data, Compare) == 1)
            CreateNode(set, member->data);
        member = member->next;
    }
    
    return set;
}

// O(n*m)
Set* Difference(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data))
{
    Set *set = NULL;
    if ((set = Initialize()) == NULL)
        return NULL;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data, Compare) == 0)
            CreateNode(set, member->data);

        member = member->next;
    }

    return set;
}

int IsSubSet(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data))
{
    if (Size(setA) > Size(setB))
        return 0;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data, Compare) == 0)
            return 0;
        member = member->next;
    }

    return 1;
}

// O(n*m)
int IsEqual(const Set* const setA, const Set* const setB, int(*Compare)(const Node* const node, const void* const data))
{
    if (Size(setA) != Size(setB))
        return 0;

    Node *member = setA->head;
    while(member != NULL)
    {
        if (IsMember(setB, member->data, Compare) == 0)
            return 0;
        member = member->next;
    }

    return 1;
}

// O(Print())
void ListItem(const Set* const set, void(*Print)(const Set* const set))
{
    Print(set);
}

// O(1)
int Size(const Set* const set)
{
    return set->size;
}

int Destroy(Set* const set, int(*Compare)(const Node* const node, const void* const data), void(*Delete)(void *data))
{
    void *removed;
    while (Size(set) > 0)
    {
        if ((removed = malloc(sizeof(void))) == NULL)
            return -1;

        Remove(set, set->head->data, Compare, Delete);
    }

    free(set);

    return 0;
}

Set* Cover(Set* const member, Set* const subsets)
{
    Set* covering;
    if ((covering = Initialize()) == NULL)
        return NULL;

    return covering;
}