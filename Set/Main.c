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

int CoveringSetTest();
Set* InitializeSetValue(Set* values[], int size);
bool CompareSet(const Node* const member, const void* const data);
void PrintSet(const Set* const set, char label);
void DeleteSet(void *data);

int main(void)
{
    // if (IntegerSetTest() == -1)
    //     return -1;

    if (CoveringSetTest() == -1)
        return -1;

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

int CoveringSetTest()
{
    Set *members, *subsets, *covering;

    int valueMemberSet[] = { 1, 2, 3, 4, 5 };
    members = InitializeIntegerValue(valueMemberSet, 5);
    PrintInteger(members, 'M');

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

    PrintSet(subsets, 'S');

    printf("\nCovering started\n");
    if (Cover(members, subsets, &covering) == false)
        return -1;

    PrintSet(covering, 'C');
    printf("Covering ended.\n");

    return 0;
}

Set* InitializeSetValue(Set* values[], int size)
{
    Set *set;
    if (Initialize(&set, DeleteSet) == false)
        return NULL;

    for (int i=0; i<size; i++)
        Insert(set, (void*)(*(values+i)), CompareSet);
    return set;
}

bool CompareSet(const Node* const member, const void* const data)
{
    if ((Set*)member->data == (Set*)data)
        return true;
    else
        return false;
}

void PrintSet(const Set* const set, char label)
{
    printf("Set%c size: %d\n", label, Size(set));

    printf("Set%c:\n", label);
    Node *member = set->head;
    while (member != NULL)
    {
        Set *data = (Set*)member->data;
        Node *setMember = data->head;
        while (setMember != NULL)
        {
            printf("%d ", *(int *)setMember->data);
            setMember = setMember->next;
        }
        
        member = member->next;
        printf("\n");
    }
}

void DeleteSet(void *data)
{
    printf("Deleting set data....\n");
    free((Set*)data);
    data = NULL;
}