#include <stdlib.h>
#include <errno.h>
#include "ChainedHashTable.h"
#include "../LinkedList/LinkedList.h"

// Function Definition

// O(n)
bool InitializeChainedHashTable(ChainedHashTable **chainedHashTable, int buckets, unsigned(*HashFunction)(const void* const key), bool(*Compare)(const void* const keyA, const void* const keyB), void(*Delete)(void *data))
{
    if ((*chainedHashTable = (ChainedHashTable*)malloc(sizeof(ChainedHashTable))) == NULL)
    {
        perror("Error message");
        return false;
    }

    if (((*chainedHashTable)->table = (LinkedList*)malloc(buckets * sizeof(LinkedList))) == NULL)
    {
        perror("Error message");
        return false;
    }

    (*chainedHashTable)->buckets = buckets;
    (*chainedHashTable)->size = 0;

    for (int i = 0; i < buckets; i++)
    {
        if (Initialize(&(*chainedHashTable)->table+i, NULL, Delete) == false)
            return false;

        (*chainedHashTable)->size++;
    }

    (*chainedHashTable)->HashFunction = HashFunction;
    (*chainedHashTable)->Compare = Compare;
    (*chainedHashTable)->Delete = Delete;

    return true;
}

// O(1)
bool Insert(ChainedHashTable* const chainedHashTable, const void* const data)
{
    return -1;
}

// O(1)
bool Remove(ChainedHashTable* const chainedHashTable, void **data)
{
    return -1;
}

// O(1)
int ChainedHashTableSize(const ChainedHashTable* const chainedHashTable)
{
    return chainedHashTable->size;
}

// O(n)
bool DestroyChainedHashTable(ChainedHashTable **chainedHashTable)
{
	LinkedList *remove;
    while ((*chainedHashTable)->size > 0)
    {
        if ((remove = malloc(sizeof(void))) == NULL)
		{
			perror("Error message");
			return false;
		}

		if (RemoveAfter((*chainedHashTable)->table, NULL, (void*)&remove) == true)
            Destroy(&remove);
			
        (*chainedHashTable)->size--;
    }
    
    free((*chainedHashTable)->table);
    (*chainedHashTable)->table = NULL;

    free(*chainedHashTable);
    *chainedHashTable = NULL;

    return true;
}