#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

int* CreateElement(int data);
int Compare(const Node* const node, const void* const data);
void Delete(void *data);
void Print(const Set* const set);
Set* InitializeSet(int values[], int szie);

int main(void)
{
    Set *setA, *setB, *set;
	if ((setA = Initialize()) == NULL)
        return -1;

    int setAValues[] = { 1, 2, 1, 3 };
    setA = InitializeSet(setAValues, 4);

    printf("SetA size: %d\n", Size(setA));
    ListItem(setA, Print);

    Remove(setA, (void*)(setAValues+3), Compare, Delete);

    printf("Set size after removing: %d\n", Size(setA));
    ListItem(setA, Print);

    if ((setB = Initialize()) == NULL)
        return -1;

    int setBValues[] = { 1, 3 };
    setB = InitializeSet(setBValues, 2);

    printf("SetB size: %d\n", Size(setB));
    ListItem(setB, Print);

    set = Union(setA, setB, Compare);
    printf("Union Set size: %d\nUnion Set ", Size(set));
    ListItem(set, Print);

    if (IsSubSet(setA, set, Compare) == 1)
        printf("SetA is subset of Set\n");
    else
        printf("SetA is not subset of Set\n");

    set = Intersection(setA, setB, Compare);
    printf("Intersection Set size: %d\nIntersection Set ", Size(set));
    ListItem(set, Print);

    if (IsEqual(setA, setB, Compare) == 1)
        printf("SetA and SetB are equal\n");
    else
        printf("SetA and SetB is not equal\n");

    set = Difference(setA, setB, Compare);
    printf("Difference Set size: %d\nDifference Set ", Size(set));
    ListItem(set, Print);

	if (Destroy(set, Compare, Delete) == -1)
		return -1;
	else
		set == NULL;

	printf("Set destroyed\n");

    printf("\nCovering Algorithm\n");
    
    Set *members, *subsets, *covering;
    if ((members = Initialize()) == NULL)
        return -1;

    int memberValues[] = { 1, 2, 3, 4, 5 };
    members = InitializeSet(memberValues, 2);

    printf("Members size: %d\n", Size(members));
    ListItem(members, Print);

    if ((subsets = Initialize()) == NULL)
        return -1;

    if ((covering = Cover(members, subsets)) == NULL)
        return -1;

    Node* element = covering->head;
    /*while(element != NULL)
    {
        ListItem(element->data, Print);
        element = element->next;
    }*/

    return 0;
}

int* CreateElement(int data)
{
    int *value = NULL;
    if ((value = (int*)malloc(sizeof(int))) == NULL)
        return NULL;
    
    *value = data;
    return value;
}

int Compare(const Node* const node, const void* const data)
{
    if (*(int*)node->data == *(int*)data)
        return 1;
    else
        return 0;
}

void Delete(void *data)
{
    printf("Deleting... %d\n", *(int *)data);
    free(data);
}

void Print(const Set* const set)
{
    printf("List: ");
    Node *member = set->head;
    while (member != NULL)
    {
        printf("%d ", *(int *)member->data);
        member = member->next;
    }

    printf("\n");
}

Set* InitializeSet(int values[], int size)
{
    Set *set;
    if ((set = Initialize()) == NULL)
        return NULL;

    int *value = NULL;
    for (int i=0; i<size; i++)
    {
        if ((value = CreateElement(values[i])) == NULL)
            return NULL;
        Insert(set, (void*)value, Compare);
    }

    return set;
}