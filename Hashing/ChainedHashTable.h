#ifndef CHAINED_HASH_TABLE
#define CHAINED_HASH_TABLE

#include <stdbool.h>
#include "../LinkedList/LinkedList.h"

// Constant Definition
#define PRIME_TABLE_SIZE 32;

// Struct Definition
typedef struct ChainedHashTable {
    int buckets;
    int size;
    LinkedList *table;

    unsigned(*HashFunction)(const void* const key);
    bool(*Compare)(const void* const keyA, const void* const keyB);
    void(*Delete)(void *data);

} ChainedHashTable;

// Function Definition
bool InitializeChainedHashTable(ChainedHashTable **chainedHashTable, int buckets, unsigned(*HashFunction)(const void* const key), bool(*Compare)(const void* const keyA, const void* const keyB), void(*Delete)(void *data));
bool Insert(ChainedHashTable* const chainedHashTable, const void* const data);
bool Remove(ChainedHashTable* const chainedHashTable, void **data);
int ChainedHashTableSize(const ChainedHashTable* const chainedHashTable);
bool DestroyChainedHashTable(ChainedHashTable **chainedHashTable);

#endif