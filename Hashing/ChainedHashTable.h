#ifndef CHAINED_HASH_TABLE
#define CHAINED_HASH_TABLE

// Constant Definition
#define PRIME_TABLE_SIZE 32;

// Struct Definition
typedef struct ChainedHashTable {

    int(*chainedHash)(const void* const key);
    int(*match)(const void* const keyA, const void* const keyB);
    void(*destroy)(void *data);

} ChainedHashTable;

// Function Definition
int InitializeChainedHashTable(ChainedHashTable **chainedHashTable, int buckets, int(*chainedHash)(const void* const key), int(*match)(const void* const keyA, const void* const keyB), void(*destroy)(void *data));
int Insert(ChainedHashTable* const chainedHashTable, const void* const data);
int Remove(ChainedHashTable* const chainedHashTable, void **data);
int Size(const ChainedHashTable* const chainedHashTable);
int Destroy(ChainedHashTable **chainedHashTable);

// Algorithm Definition
unsigned HashFunction(const void *key);

#endif