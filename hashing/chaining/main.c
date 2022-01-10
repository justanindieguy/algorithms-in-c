#include <stdio.h>
#include "Chains.h"

int hash(int key)
{
    return key % 10;
}

void insert(struct Node *hashTable[], int key)
{
    int idx = hash(key);
    sortedInsert(&hashTable[idx], key);
}

int main()
{
    int i;
    struct Node *hashTable[10];
    struct Node *temp;

    for (i = 0; i < 10; i++)
        hashTable[i] = NULL;

    insert(hashTable, 12);
    insert(hashTable, 22);
    insert(hashTable, 42);

    temp = search(hashTable[hash(22)], 22);
    printf("%p\n", temp);

    return 0;
}
