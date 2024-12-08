#include <stdlib.h>
#include "ChainedHashTable.h"
#include "../LinkedList/LinkedList.h"

// Function Definition

// O(n)
bool InitializeChainedHashTable(ChainedHashTable **chainedHashTable, int buckets, bool(*ChainedHash)(const void* const key), bool(*Compare)(const void* const keyA, const void* const keyB), void(*Destroy)(void *data))
{
    if ((*chainedHashTable = (ChainedHashTable*)malloc(sizeof(ChainedHashTable))) == NULL)
        return -1;

    (*chainedHashTable)->ChainedHash = ChainedHash;
    (*chainedHashTable)->Compare = Compare;
    (*chainedHashTable)->Destroy = Destroy;

    for (int i=0; i<buckets; i++)
    {
        // initialize all the linked list buckets
    }

    return 1;
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
int Size(const ChainedHashTable* const chainedHashTable)
{
    return -1;
}

// O(n)
bool Destroy(ChainedHashTable **chainedHashTable)
{
    free(chainedHashTable);
    chainedHashTable = NULL;

    return 1;
}

// Hash Algorithm
unsigned HashFunction(const void *key)
{
    const char *localKey = key;
    unsigned int value = 0;;

    while (*localKey != '\0')
    {
        unsigned int temp;

        value = (value << 4) + (*localKey);

        if (temp = (value & 0xf0000000))
        {
            value = value ^ (temp >> 24);
            value = value ^ temp;
        }

        localKey++;
    }

    return value % PRIME_TABLE_SIZE;
}