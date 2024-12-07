#include <stdlib.h>
#include <errno.h>
#include "Set.h"

// Function Definition

// O(n)
bool IsMember(const Set* const set, const void* const data, bool(*Compare)(const Node* const member, const void* const data))
{
    Node *member = set->head;
    while (member != NULL)
    {
        if (Compare(member, data) == true)
            return true;
        member = member->next;
    }

    return false;
}

// O(n)
bool Insert(Set* const set, void *data, bool(*Compare)(const Node* const member, const void* const data))
{
    if (IsMember(set, data, Compare) == true)
        return false;
    return InsertAtEnd(set, data);
}

// O(n)
bool Remove(Set* const set, void **data, bool(*Compare)(const Node* const member, const void* const data))
{
    if (Size(set) == 0)
        return false;

    Node *member = NULL;
    if ((member = GetNode(set, *data, Compare)) == NULL)
        return false;

    member = member->previous;
    return RemoveAfter(set, member, data);
}

// O(n*m)
bool Union(const Set* const setA, const Set* const setB, Set **setU, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data))
{
    if (Initialize(setU, Delete) == false)
        return false;

    Node *member = setA->head;
    while (member != NULL)
    {
        InsertAtEnd(*setU, member->data);
        member = member->next;
    }
    
    member = setB->head;
    while (member != NULL)
    {
        Insert(*setU, member->data, Compare);
        member = member->next;
    }

    return true;
}

// O(n*m)
bool Intersection(const Set* const setA, const Set* const setB, Set **setI, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data))
{
    if (Initialize(setI, Delete) == false)
        return false;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data, Compare) == true)
            InsertAtEnd(*setI, member->data);
        member = member->next;
    }
    
    return true;
}

// O(n*m)
bool Difference(const Set* const setA, const Set* const setB, Set **setD, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data))
{
    if (Initialize(setD, Delete) == false)
        return false;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data, Compare) == false)
            InsertAtEnd(*setD, member->data);

        member = member->next;
    }

    return true;
}

// O(n*m)
bool IsSubSet(const Set* const setA, const Set* const setB, bool(*Compare)(const Node* const member, const void* const data))
{
    if (Size(setA) > Size(setB))
        return false;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data, Compare) == false)
            return false;
        member = member->next;
    }

    return true;
}

// O(n*m)
bool IsEqual(const Set* const setA, const Set* const setB, bool(*Compare)(const Node* const member, const void* const data))
{
    if (Size(setA) != Size(setB))
        return false;

    Node *member = setA->head;
    while(member != NULL)
    {
        if (IsMember(setB, member->data, Compare) == false)
            return false;
        member = member->next;
    }

    return true;
}

// Algorithm Definition
bool Cover(Set* const memberSet, Set* const subsets, Set** cover, bool (*Compare)(const Node *const member, const void *const data), void (*Delete)(void *data))
{
    while (Size(memberSet) > 0 && Size(subsets) > 0)
    {
        int largestSetSize = 0;
        Set *largestSet = NULL;
        Node *member = subsets->head;

        while (member != NULL)
        {
            // find largest intersection
            Set *setI = NULL;
            Intersection(memberSet, (Set*)member->data, &setI, Compare, Delete);
            
            if (largestSetSize < Size(setI))
            {
                largestSetSize = Size(setI);
                largestSet = setI;
            }

            member = member->next;
        }

        // Add this to covering
        Insert(*cover, largestSet, Compare);

        // remove the members from memberSet
        Node *temp = largestSet->head;
        while (temp != NULL)
        {
            Remove(member, temp->data, Compare);
            temp = temp->next;
        }

        // remove the largest set from subsets
        Remove(subsets, largestSet, Compare);
    }

    if (Size(memberSet) != 0 || Size(subsets) != 0)
        return false;

    return true;
}


Set* Cover2(Set* const member, Set* const subsets)
{
    Set* covering;
    if (Initialize(&covering, DeleteNode) == -1)
        return NULL;

    while (Size(member) > 0 && Size(subsets) > 0)
    {
        int largestSetSize = 0;
        Set *largestSet = NULL;
        Node *node = subsets->head;
        
        while (node != NULL)
        {
            Set *setI;
            if (Initialize(&setI, DeleteNode) == -1)
                return NULL;

            Intersection(member, node->data, setI, CompareIntegers);
            if (largestSetSize < Size(setI))
            {
                largestSetSize = Size(setI);
                largestSet = node->data;
            }

            node = node->next;
        }

        Set *removeSet = NULL;
        CreateNode(covering, (void*)largestSet);

        Node *remove = largestSet->head;
        while (remove != NULL)
        {
            Node *removeNode = NULL;
            if ((removeNode = (Node*)malloc(sizeof(Node))) == NULL)
                return NULL;

            Remove(member, (void*)remove->data, (void*)&removeNode, CompareIntegers);
            remove = remove->next;
            free(removeNode);
        }
        
        Remove(subsets, (void*)largestSet, (void*)&removeSet, CompareSets);
    }

    if (Size(member) > 0)
        return NULL;

    return covering;
}