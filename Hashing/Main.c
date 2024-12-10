#include <stdio.h>
#include "ChainedHashTable.h"

bool Compare(const void* const keyA, const void* const keyB);
void Delete(void *data);

// Algorithm Definition
unsigned HashFunction(const void *key);

int main(void)
{
    ChainedHashTable *chainedHashTable = NULL;

    if (InitializeChainedHashTable(&chainedHashTable, 5, HashFunction, Compare, Delete) == false)
        return -1;

    if (DestroyChainedHashTable(&chainedHashTable) == false)
		return -1;

	printf("HashTable destroyed");

    return 0;
}

bool Compare(const void* const keyA, const void* const keyB)
{
    return false;
}

void Delete(void *data)
{

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