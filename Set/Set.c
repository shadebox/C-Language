#include <stdlib.h>
#include <errno.h>
#include "Set.h"

// Function Definition

// O(n)
bool IsMember(const Set* const set, const void* const data)
{
    Node *member = set->head;
    while (member != NULL)
    {
        if (set->Compare(member, data) == true)
            return true;
        member = member->next;
    }

    return false;
}

// O(n)
bool Insert(Set* const set, void *data)
{
    if (IsMember(set, data) == true)
        return false;
    return InsertAtEnd(set, data);
}

// O(n)
bool Remove(Set* const set, void **data)
{
    if (Size(set) == 0)
        return false;

    Node *member = NULL;
    if ((member = GetNode(set, *data)) == NULL)
        return false;

    member = member->previous;
    if (member == NULL)
        return RemoveAtFront(set, data);
    else
        return RemoveAfter(set, member, data);
}

// O(n*m)
bool Union(const Set* const setA, const Set* const setB, Set **setU, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data))
{
    if (Initialize(setU, Compare, Delete) == false)
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
        Insert(*setU, member->data);
        member = member->next;
    }

    return true;
}

// O(n*m)
bool Intersection(const Set* const setA, const Set* const setB, Set **setI, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data))
{
    if (Initialize(setI, Compare, Delete) == false)
        return false;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data) == true)
            InsertAtEnd(*setI, member->data);
        member = member->next;
    }
    
    return true;
}

// O(n*m)
bool Difference(const Set* const setA, const Set* const setB, Set **setD, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data))
{
    if (Initialize(setD, Compare, Delete) == false)
        return false;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data) == false)
            InsertAtEnd(*setD, member->data);

        member = member->next;
    }

    return true;
}

// O(n*m)
bool IsSubSet(const Set* const setA, const Set* const setB)
{
    if (Size(setA) > Size(setB))
        return false;

    Node *member = setA->head;
    while (member != NULL)
    {
        if (IsMember(setB, member->data) == false)
            return false;
        member = member->next;
    }

    return true;
}

// O(n*m)
bool IsEqual(const Set* const setA, const Set* const setB)
{
    if (Size(setA) != Size(setB))
        return false;

    Node *member = setA->head;
    while(member != NULL)
    {
        if (IsMember(setB, member->data) == false)
            return false;
        member = member->next;
    }

    return true;
}

// Algorithm Definition
bool Cover(Set* const memberSet, Set* const subsets, Set** cover)
{
    while (Size(memberSet) > 0 && Size(subsets) > 0)
    {
        int largestSetSize = 0;
        Set *largestSet = NULL;
        Node *member = subsets->head;

        while (member != NULL)
        {
            Set *setI = NULL;
            Intersection(memberSet, (Set*)member->data, &setI, memberSet->Compare, memberSet->Delete);
            
            if (largestSetSize < Size(setI))
            {
                largestSetSize = Size(setI);
                largestSet = (Set*)member->data;
            }

            member = member->next;
        }

        if (largestSetSize == 0)
            return false;

        Insert(*cover, largestSet);

        Node *removeNode = largestSet->head;
        while (removeNode != NULL)
        {
            Remove(memberSet, (void*)&removeNode->data);
            removeNode = removeNode->next;
        }

        Remove(subsets, (void*)&largestSet);
    }

    if (Size(memberSet) != 0)
        return false;

    return true;
}