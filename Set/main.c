#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

// Function Definition
Set* InitializeIntegerValue(int values[], int size);
int* CreateIntegerElement(int data);
int CompareIntegers(const Node* const node, const void* const data);
int CompareSets(const Node* const node, const void* const data);
void DeleteInteger(void *data);
void DeleteSets(void *data);
void PrintIntegers(const Set* const set);

// Algorithm Definition
Set* Cover(Set* const member, Set* const subsets);

int main(void)
{
    /*Set *setA, *setB, *setU, *setI, *setD;

    int valueSetA[] = { 1, 2, 1, 3 };
    setA = InitializeIntegerValue(valueSetA, 4);

    printf("SetA size: %d\nSetA: ", Size(setA));
    ListItem(setA, PrintIntegers);

    Remove(setA, (void*)(valueSetA + 3), CompareIntegers, DeleteInteger);

    printf("SetA size after removing: %d\nSetA: ", Size(setA));
    ListItem(setA, PrintIntegers);

    int valueSetB[] = { 1, 3 };
    setB = InitializeIntegerValue(valueSetB, 2);

    printf("SetB size: %d\nSetB: ", Size(setB));
    ListItem(setB, PrintIntegers);

    if (Initialize(&setU) == -1)
        return -1;

    if (Union(setA, setB, setU, CompareIntegers) == NULL)
        return -1;
    printf("SetU size: %d\nSetU: ", Size(setU));
    ListItem(setU, PrintIntegers);

    if (IsSubSet(setA, setU, CompareIntegers) == 1)
        printf("SetA is subset of SetU\n");
    else
        printf("SetA is not subset of SetU\n");

    if (Initialize(&setI) == -1)
        return -1;

    if (Intersection(setA, setB, setI, CompareIntegers) == NULL)
        return -1;
    printf("SetI size: %d\nSetI: ", Size(setI));
    ListItem(setI, PrintIntegers);

    if (IsEqual(setA, setB, CompareIntegers) == 1)
        printf("SetA and SetB are equal\n");
    else
        printf("SetA and SetB is not equal\n");

    if (Initialize(&setD) == -1)
        return -1;

    if (Difference(setA, setB, setD, CompareIntegers) == NULL)
        return -1;
    printf("SetD size: %d\nSetD: ", Size(setD));
    ListItem(setD, PrintIntegers);

	if (Destroy(setD, CompareIntegers, DeleteInteger) == -1)
		return -1;
	else
		setD == NULL;

	printf("Set destroyed\n");*/

    printf("\nCovering Algorithm\n");
    
    Set *members, *subsets, *covering;

    int valueMemberSet[] = { 1, 2, 3, 4, 5 };
    members = InitializeIntegerValue(valueMemberSet, 5);
    
    printf("Members size: %d\nMember: ", Size(members));
    ListItem(members, PrintIntegers);

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

    if (Initialize(&subsets) == -1)
        return -1;
    CreateNode(subsets, (void*)set1);
    CreateNode(subsets, (void*)set2);
    CreateNode(subsets, (void*)set3);
    CreateNode(subsets, (void*)set4);

    printf("Covering started.\n");
    if ((covering = Cover(members, subsets)) == NULL)
        return -1;

    /*Node* element = covering->head;
    while(element != NULL)
    {
        ListItem(element->data, Print);
        element = element->next;
    }*/

    printf("Covering ended.\n");
    return 0;
}

Set* InitializeIntegerValue(int values[], int size)
{
    Set *set;
    if (Initialize(&set) == -1)
        return NULL;

    int *value = NULL;
    for (int i=0; i<size; i++)
    {
        if ((value = CreateIntegerElement(values[i])) == NULL)
            return NULL;
        Insert(set, (void*)value, CompareIntegers);
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

int CompareIntegers(const Node* const node, const void* const data)
{
    if (*(int*)node->data == *(int*)data)
        return 1;
    else
        return 0;
}

void DeleteInteger(void *data)
{
    printf("Deleting... %d\n", *(int *)data);
    free(data);
}

void PrintIntegers(const Set* const set)
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


Set* Cover(Set* const member, Set* const subsets)
{
    Set* covering;
    if (Initialize(&covering) == -1)
        return NULL;

    int largestSetSize = 0;
    Set *largestSet = NULL;
    while (Size(member) > 0 && Size(subsets) > 0)
    {
        Node *node = subsets->head;
        while (node != NULL)
        {
            Set *setI;
            if (Initialize(&setI) == -1)
                return NULL;

            Intersection(member, node->data, setI, CompareIntegers);
            if (largestSetSize < Size(setI))
            {
                largestSetSize = Size(setI);
                largestSet = node->data;
            }

            node = node->next;
        }

        CreateNode(covering, (void*)largestSet);
        Remove(subsets, (void*)largestSet, CompareSets, DeleteSets);

        Node *remove = largestSet->head;
        while (remove != NULL)
        {
            Remove(member, (void*)remove->data, CompareIntegers, DeleteInteger);
            remove = remove->next;
        }
    }

    if (Size(member) > 0)
        return NULL;

    return covering;
}

int CompareSets(const Node* const node, const void* const data)
{
    if ((Set*)node->data == (Set*)data)
        return 1;
    else
        return 0;
}

void DeleteSets(void *data)
{
    free(data);
    /*Node *member = (Node*)data;
    while (member != NULL)
    {
        Node *temp = member;
        member = temp->next;

        if (temp != NULL)
        {
            //if (temp->data != NULL)
              //  free(temp->data);
            free(temp);
        }
    }*/
}