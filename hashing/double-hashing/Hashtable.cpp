#include "Hashtable.h"
#define SIZE 10
#define PRIME 7

int HashTable::hash(int key)
{
    return key % SIZE;
}

int HashTable::primeHash(int key)
{
    return PRIME - (key % PRIME);
}

int HashTable::doubleHash(int key)
{
    int idx = hash(key);
    int i = 0;

    while (ht[(hash(idx) + i * primeHash(key)) % SIZE] != 0)
        i++;

    return (idx + i * primeHash(key)) % SIZE;
}

void HashTable::insert(int key)
{
    int idx = hash(key);

    if (ht[idx] != 0)
        idx = doubleHash(key);

    ht[idx] = key;
}

int HashTable::search(int key)
{
    int idx = hash(key);
    int i = 0;

    while (ht[(hash(idx) + i * primeHash(key)) % SIZE] != key)
    {
        i++;
        if (ht[(hash(idx) + i * primeHash(key)) % SIZE] == 0)
            return -1;
    }

    return (idx + i * primeHash(key)) % SIZE;
}
