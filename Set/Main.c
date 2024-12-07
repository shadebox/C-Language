#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

// Function Definition
int IntegerSetTest();
Set* InitializeIntegerValue(int values[], int size);
int* CreateIntegerElement(int data);
bool CompareInteger(const Node* const member, const void* const data);
void PrintInteger(const Set* const set, char label);
void DeleteInteger(void *data);
// void DeleteNode(Node *data);
// Set* InitializeSetValue(Set* values[], int size);
// int CompareSets(const Node* const node, const void* const data);
// void PrintSet(const void* const data);

// Algorithm Definition
// Set* Cover(Set* const member, Set* const subsets);

int main(void)
{
    if (IntegerSetTest() == -1)
        return -1;

    /*printf("\nCovering Algorithm\n");
    Set *members, *subsets, *covering;

    int valueMemberSet[] = { 1, 2, 3, 4, 5 };
    members = InitializeIntegerValue(valueMemberSet, 5);
    
    printf("Members size: %d\nMember: ", Size(members));
    PrintIntegers(members);

    // Initialize and create sets for subsets
    Set *set1, *set2, *set3, *set4;

    int valueSet1[] = { 1, 2, 3 };
    set1 = InitializeIntegerValue(valueSet1, 3);

    int valueSet2[] = { 1, 5 };
    set2 = InitializeIntegerValue(valueSet2, 2);

    int valueSet3[] = { 1, 2, 3, 4 };
    set3 = InitializeIntegerValue(valueSet3, 4);

    int valueSet4[] = { 5 };
    set4 = InitializeIntegerValue(valueSet4, 1);
    // Initialize and create sets for subsets

    Set* valueSet[] = { set1, set2, set3, set4 };
    subsets = InitializeSetValue(valueSet, 4);

    printf("Covering started.\n");
    if ((covering = Cover(members, subsets)) == NULL)
        return -1;

    Node* element = covering->head;
    while(element != NULL)
    {
        PrintSet(element->data);
        element = element->next;
    }

    printf("Covering ended.\n");*/
    return 0;
}

int IntegerSetTest()
{
    Set *setA, *setB, *setU, *setI, *setD;

    int valueSetA[] = { 1, 2, 1, 3 };
    setA = InitializeIntegerValue(valueSetA, 4);
    PrintInteger(setA, 'A');

    int valueSetB[] = { 1, 3 };
    setB = InitializeIntegerValue(valueSetB, 2);
    PrintInteger(setB, 'B');

    int *removed = NULL;
    if ((removed = (int*)malloc(sizeof(int))) == NULL)
        return -1;
    
    *removed = valueSetA[3];
    if (Remove(setA, (void*)&removed, CompareInteger) == false)
        return -1;

    printf("Removed value: %d\n", *removed);
    PrintInteger(setA, 'A');

    if (Union(setA, setB, &setU, CompareInteger, DeleteInteger) == false)
        return -1;

    PrintInteger(setU, 'U');

    if (IsSubSet(setA, setU, CompareInteger) == true)
        printf("SetA is subset of SetU\n");
    else
        printf("SetA is not subset of SetU\n");

    if (Intersection(setA, setB, &setI, CompareInteger, DeleteInteger) == false)
        return -1;

    PrintInteger(setI, 'I');

    if (IsEqual(setA, setB, CompareInteger) == true)
        printf("SetA and SetB are equal\n");
    else
        printf("SetA and SetB are not equal\n");

    if (Difference(setA, setB, &setD, CompareInteger, DeleteInteger) == false)
        return -1;

    PrintInteger(setD, 'D');

    if (Destroy(&setD) == false)
		return -1;

	printf("Set destroyed\n");
    return 0;
}

Set* InitializeIntegerValue(int values[], int size)
{
    Set *set;
    if (Initialize(&set, DeleteInteger) == false)
        return NULL;

    int *value = NULL;
    for (int i=0; i<size; i++)
    {
        if ((value = CreateIntegerElement(values[i])) == NULL)
            return NULL;
        Insert(set, (void*)value, CompareInteger);
    }

    return set;
}

int* CreateIntegerElement(int data)
{
    int *value = NULL;
    if ((value = (int*)malloc(sizeof(int))) == NULL)
        return NULL;
    *value = data;

    return value;
}

bool CompareInteger(const Node* const member, const void* const data)
{
    if (*(int*)member->data == *(int*)data)
        return true;
    else
        return false;
}

void PrintInteger(const Set* const set, char label)
{
    printf("Set%c size: %d\n", label, Size(set));

    printf("Set%c: ", label);
    Node *member = set->head;
    while (member != NULL)
    {
        printf("%d ", *(int *)member->data);
        member = member->next;
    }

    printf("\n");
}

void DeleteInteger(void *data)
{
    printf("Deleting... %d\n", *(int *)data);
    free(data);
    data = NULL;
}

// Set* InitializeSetValue(Set* values[], int size)
// {
//     Set *set;
//     if (Initialize(&set, DeleteNode) == -1)
//         return NULL;

//     for (int i=0; i<size; i++)
//         Insert(set, (void*)(*(values+i)), CompareSets);
//     return set;
// }

// int CompareSets(const Node* const node, const void* const data)
// {
//     if ((Set*)node->data == (Set*)data)
//         return 1;
//     else
//         return 0;
// }

// void DeleteNode(Node *data)
// {
//     free(data);
// }

// void PrintSet(const void* const data)
// {
//     printf("List: ");

//     Set *set = (Set*)data;
//     Node *member = set->head;
//     while (member != NULL)
//     {
//         printf("%d ", *(int *)member->data);
//         member = member->next;
//     }

//     printf("\n");
// }

// Set* Cover(Set* const member, Set* const subsets)
// {
//     Set* covering;
//     if (Initialize(&covering, DeleteNode) == -1)
//         return NULL;

//     while (Size(member) > 0 && Size(subsets) > 0)
//     {
//         int largestSetSize = 0;
//         Set *largestSet = NULL;
//         Node *node = subsets->head;
        
//         while (node != NULL)
//         {
//             Set *setI;
//             if (Initialize(&setI, DeleteNode) == -1)
//                 return NULL;

//             Intersection(member, node->data, setI, CompareIntegers);
//             if (largestSetSize < Size(setI))
//             {
//                 largestSetSize = Size(setI);
//                 largestSet = node->data;
//             }

//             node = node->next;
//         }

//         Set *removeSet = NULL;
//         CreateNode(covering, (void*)largestSet);

//         Node *remove = largestSet->head;
//         while (remove != NULL)
//         {
//             Node *removeNode = NULL;
//             if ((removeNode = (Node*)malloc(sizeof(Node))) == NULL)
//                 return NULL;

//             Remove(member, (void*)remove->data, (void*)&removeNode, CompareIntegers);
//             remove = remove->next;
//             free(removeNode);
//         }
        
//         Remove(subsets, (void*)largestSet, (void*)&removeSet, CompareSets);
//     }

//     if (Size(member) > 0)
//         return NULL;

//     return covering;
// }