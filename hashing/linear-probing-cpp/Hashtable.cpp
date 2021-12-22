#include "Hashtable.h"

int HashTable::hash(int key)
{
    return key % SIZE;
}

int HashTable::linearProbe(int key)
{
    int i = 0;
    int idx = hash(key);

    while (hashTable[(idx + i) % SIZE] != 0)
        i++;

    return (idx + i) % SIZE;
}

void HashTable::insert(int key)
{
    int idx = hash(key);

    if (hashTable[idx] != 0)
        idx = linearProbe(key);

    hashTable[idx] = key;
}

int HashTable::search(int key)
{
    int i = 0;
    int idx = hash(key);

    while (hashTable[(idx + i) % SIZE] != key)
    {
        i++;
        if (hashTable[(idx + i) % SIZE] == 0)
            return -1;
    }

    return (idx + i) % SIZE;
}
