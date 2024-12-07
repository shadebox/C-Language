#ifndef SET_HEADER
#define SET_HEADER

#include <stdbool.h>
#include "../DoubleLinkedList/DoubleLinkedList.h"

// Struct Definition
typedef DoubleLinkedList Set;

// Function Definition
bool IsMember(const Set* const set, const void* const data, bool(*Compare)(const Node* const member, const void* const data));
bool Insert(Set* const set, void *data, bool(*Compare)(const Node* const member, const void* const data));
bool Remove(Set* const set, void **data, bool(*Compare)(const Node* const member, const void* const data));
bool Union(const Set* const setA, const Set* const setB, Set **setU, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data));
bool Intersection(const Set* const setA, const Set* const setB, Set **setI, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data));
bool Difference(const Set* const setA, const Set* const setB, Set **setD, bool(*Compare)(const Node* const member, const void* const data), void(*Delete)(void *data));
bool IsSubSet(const Set* const setA, const Set* const setB, bool(*Compare)(const Node* const member, const void* const data));
bool IsEqual(const Set* const setA, const Set* const setB, bool(*Compare)(const Node* const member, const void* const data));

// Algorithm Definition
bool Cover(Set* const memberSet, Set* const subsets, Set** cover);

#endif